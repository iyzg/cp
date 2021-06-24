/*
ACM ICPC Southeast Regional Contest 2009

Guarding A Museum

Author: Yiu Yu Ho

This is a traditional supply and demand problem (transportation problem). For more information please reference 
Network Flows: Theory, Algorithms, and Applications
Ravindra K. Ahuja, Thomas L. Magnanti, James B. Orlin

Since the guards can only switch at half hours, we may consider the day as a partition 24 x 2 = 48 half hour 
slots total, where each slot requires some guard to be on duty.
Each guard provides exactly maxTime/30 supplies as s/he can guard at most that many slots, where maxTime is the 
maximum number of minutes s/he is able to be on duty, in addition, s/he can only guard the corresponding slots 
where she is completely available.  Each slot, has a demand of k units, where k is the number of guards the museum 
is trying to maintain.

The supply and demand problem is solved using network flow, see details below
*/

import java.io.*;
import java.util.*;

public class museumYiu
{
	public Scanner in = new Scanner(System.in);
	public PrintStream out = System.out;

	public int[][] G;
	public int Gn, n;

	public int Tmax = 24*60;
	public int slots = Tmax/30;
	
	public int sor, dst;

	public void main()
	{
		int i, j, k, x;
		int m;

		int start, end;
		boolean[] can;

		n = in.nextInt();
		while(n > 0)
		{
			//source, sink, n guards, slots number of slots
			//Gn is the number of vertices in the network
			Gn = 2 + n + slots;
			G = new int[Gn][Gn];
			
			//source is vertex 0 and sink (dst) is vertex 1
			sor = 0; dst = 1;

			for(i=0;i<n;++i)
			{
				k = in.nextInt();
				m = in.nextInt();
				
				//source --> i-th guard has capacity m/30, where m is the maximium number of 
				//minutes guard i is able to work.  This limits the number of times a guard is 
				//assigned to any slots.
				G[sor][guard(i)] = m/30;
				
				//read in time intervals, the union of time intervals are kept track with an array of 1440 cells,
				//one per minute
				can = new boolean[Tmax];
				for(j=0;j<k;++j)
				{
					//parse converts from HH:MM to [0, 1439]
					start = parse(in.next());
					end = parse(in.next());
					
					//start < end, the time interval is [start, end)
					if(start < end)
					{
						for(x=start;x<end;++x) can[x] = true;
					}
					else //start >= end
					{
						//start >= end, we break it down into [start, 1440) and [0, end)
						//warping around mid-night
						for(x=start;x<Tmax;++x) can[x] = true;
						for(x=0;x<end;++x) can[x] = true;
					}
				}
				
				//Guard i can work at a slot, if he can work during its entirety.
				//The work method checks that.
				for(x=0;x<Tmax;x+=30) if(work(can, x, x+30))
				{
					//capacity = 1, as the guard can only contribute 1 unit to the demand of a slot.
					G[guard(i)][slot(x/30)] = 1;
				}
			}//end for i = 0 .. n-1
			
			//Try k = 1
			for(j=0;j<slots;++j) G[slot(j)][dst]++;
			
			//There is a feasible solution for maintaining k guards as long as the maximum flow equals k * slots.
			int res = 0;
			while(flow() == slots)
			{
				++res;
				//check the next k, note that we do not need to reset our residual network because augmenting path 
				//algorithm (Ford-Fulkerson, Edmonds-Karp, etc) has no preference on how each (sor,dst)-path is selected
				for(j=0;j<slots;++j) G[slot(j)][dst]++;
			}

			out.println(res);

			n = in.nextInt();
		}//end while(n > 0)
	}//end public void main()

	//0 - sor, 1 - dst, [2 .. 2+n-1] - guards, [2+n .. 2+n+48-1] - slots
	public int guard(int i) { return 2+i; }
	public int slot(int j) { return 2+n+j; }
	
	//convert a time in HH:MM format to [0, 1439], an integer representing the number of 
	//minutes from mid-night
	public int parse(String T)
	{
		Scanner p = new Scanner(T);
		p.useDelimiter(":");

		int hr, min;
		hr = p.nextInt();
		min = p.nextInt();

		return hr*60+min;
	}
	
	//check if can[i..j) are all true
	public boolean work(boolean[] can, int i, int j)
	{
		while(i < j)
		{
			if(!can[i]) return false;
			++i;
		}
		return true;
	}
	
	//Network Flow code below
	public boolean[] visit;

	public int flow()
	{
		int ret = 0;
		int i, x, y;

		visit = new boolean[Gn];

		//get an augmentng path
		int[] path = dfs(sor, 0);
		while(path != null)
		{
			//augment
			for(i=0;i+1<path.length;++i)
			{
				x = path[i];
				y = path[i+1];
				G[x][y]--;
				G[y][x]++;
			}
			ret++;

			//get new path
			Arrays.fill(visit, false);
			path = dfs(sor, 0);
		}

		return ret;
	}//public int flow()
	
	//Depth first search, returns a path from sor to dst, where the current vertex is x, 
	//at position pos of the path
	public int[] dfs(int x, int pos)
	{
		if(visit[x]) return null;
		visit[x] = true;
		
		int[] p;
		if(x == dst)
		{
			p = new int[pos+1];
			p[pos] = x;
			return p;
		}
		
		int y;
		for(y=0;y<Gn;++y)
		{
			if(G[x][y] > 0)
			{
				p = dfs(y, pos+1);
				if(p != null)
				{
					p[pos] = x;
					return p;
				}
			}
		}
		return null;
	}//public int[] dfs(int x, int pos)

	public static void main(String[] args)
	{
		long startTime = System.currentTimeMillis();
		(new museumYiu()).main();
		long endTime = System.currentTimeMillis();

		System.err.println("Time = "+(endTime - startTime)+"(ms)");
	}
}
