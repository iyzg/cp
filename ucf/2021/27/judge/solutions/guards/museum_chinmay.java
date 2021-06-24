import java.util.*;
import java.io.*;

public class museum_chinmay {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("museum.in"));
		PrintStream out = new PrintStream(new File("museum.out"));

		/* The idea of this problem is simple: The day is divided 
		 * into 48 half-hour slots. Each guard specifies which slots 
		 * he can work with (in a rather tricky fashion..) and a 
		 * capacity on the number of slots he can work. Now suppose
		 * we are trying to see if we can have k guards man every slot.
		 * Then clearly, this is an application of max-flow. We set up
		 * the following directed bipartite graph: All the guards are
		 * on the left side and all the 48 slots are on the right side.
		 * An edge goes from a guard to a slot if that guard can work that
		 * slot. And the capacity of this edge is 1. Moreover there is a 
		 * super-source with edges to all the guards. The capacity of this
		 * edge is the number of total slots the guard can work. There is also
		 * a super-sink which has edges coming in from all slots, and capacity
		 * of each such edge is k. If the maxflow saturates all the sink edges,
		 * then clearly we can assign guards to slots (keeping in mind their
		 * limits) such that each slot gets k guards.
		 * 
		 * Now we just need to find the maximum value of k for which this happens.
		 * Note that k can be at most N so we can even do a linear search for k
		 * starting at 1. Moreover, this is also a great optimization, because
		 * of the way Ford-Fulkerson computes the max-flow. The max-flow for k
		 * can be built by 48 flow augmentations from the max-flow for k-1. 
		 * (Because the capacity increases by at most that much).
		 * 
		 */
		
		
		int N;
		
		while((N=in.nextInt())>0)
		{
			
			/* table is the edge capacity matrix of the graph which has N nodes for guards,
			 * 48 nodes for the time slots and 1 each for the source and the sink.
			 * 
			 * Indices are assigned as follows:
			 * 0-47 slots 48 source 49 sink 50-50+N-1 guards
			 * 
			 * table[i][j] is the capacity of the edge going from i to j (0 if no edge)
			 */
			
			int table[][] = new int[N+50][N+50];
			for(int i = 0; i < table.length; i++) Arrays.fill(table[i], 0);

			/* In what follows, we compute the union of every guard's available time intervals.
			 * We iterate over each minute of the day. There may be a faster and messier way of 
			 * doing the same, but this suffices.
			 */
			boolean ar[] = new boolean[1440];
			for(int i = 0; i < N; i++)
			{
				int K = in.nextInt();
				
				//Set the number of time slots the guard can work
				table[48][50+i] = in.nextInt()/30;
				
				
				Arrays.fill(ar, false);
				for(int j = 0; j < K; j++)
				{
					String start = in.next();
					String end = in.next();
					
					//Converting the start and end times into an index between 0 and 1439 for the minutes
					int s = Integer.parseInt(start.substring(0,2))*60 + Integer.parseInt(start.substring(3,5));
					int e = Integer.parseInt(end.substring(0,2))*60 + Integer.parseInt(end.substring(3,5));

					
					//Cases to handle intervals going past midnight and such
					if(s == e)
					{
						Arrays.fill(ar, true);
					}
					else if(s > e)
					{
						for(int k = s; k < 1440; k++)
							ar[k] = true;
						for(int k = 0; k < e; k++)
							ar[k] = true;
					}
					else
					{
						for(int k = s; k < e; k++)
							ar[k] = true;
					}
				}
				
				
				/* Finally, from the map of every minute computed above,
				 * figure out which slots the guard can work.
				 */
				for(int j = 0; j < 48; j++)
				{
					table[50+i][j] = 1;
					for(int k = 0; k < 30; k++)
						if(!ar[30*j+k])
						{
							table[50+i][j] = 0;
							break;
						}
				}
				
			}


			//jjj is the required answer - i.e. the number of guards we are trying to assign to each slot
			for(int jjj = 1; jjj <= N+1; jjj++)
			{
				
				//Incrementing the capacities of edges from slots to the sink
				for(int i = 0; i < 48; i++)
					table[i][49]++;

				//cando is true is max-flow can saturate all slot-sink edges.
				boolean cando = true;

				//We need to keep track of parent pointer to infer the path after BFS is complete
				int parent[] = new int[table.length];
				
				
				
				//There can be at most 48 flow augmentations, since we increased the capacity by only that much
				for(int iii = 0; iii < 48; iii++)
				{
					
					Arrays.fill(parent, -1);
					
					//Adding source to the BFS queue
					parent[48] = -2;
					LinkedList<Integer> q = new LinkedList<Integer>();
					q.add(48);

					
					//Breadth-First-Search to find augmenting path
					while(!q.isEmpty())
					{
						int next = q.removeFirst();
						
						//If we found the sink, break
						if(next == 49) break;		
						
						for(int i = 0; i < table.length; i++)
							if(parent[i] == -1 && table[next][i] > 0)
							{
								parent[i] = next;
								q.add(i);
							}
					}

					//If sink wasn't reached, then max-flow cannot saturate all slot-sink edges
					if(parent[49] == -1)
					{
						cando = false;
						break;
					}

					//Otherwise, trace the path back using parent pointers to find augmenting path
					//During the same process, augment the flow (i.e. update residual capacities
					int curr = 49;
					while(parent[curr] >= 0)
					{
						table[curr][parent[curr]]++;
						table[parent[curr]][curr]--;
						curr = parent[curr];
					}

				}

				if(!cando)
				{
					out.println(""+(jjj-1));
					break;
				}
			}
			
		}
	}
}
