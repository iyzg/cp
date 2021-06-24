/*
ACM ICPC Southeast Regional Contest 2009

Block Game

Author: Yiu Yu Ho
*/

import java.io.*;
import java.util.*;

public class blockYiu
{
	public Scanner in = new Scanner(System.in);
	public PrintStream out = System.out;

	public int oo = 987654321;

	public Map<String, Integer> cost;
	
	public void main()
	{
		int i, j, k, x, y, z;
		int C, len;
		String now, code;
		String special;
		char[][] g;
		boolean[] used;
		char A;
		int res;

		special = in.next();
		while(!"*".equals(special))
		{
			//read input grid
			g = new char[6][];
			for(i=0;i<6;++i) g[i] = in.next().toCharArray();
			
			//Queue for BFS (Breadth First Search)
			Queue<String> Q = new LinkedList<String>();
			//cost mapping from board state to number of moves applied
			cost = new HashMap<String, Integer>();
			
			res = oo;
			
			//initial state cost = 0
			code = cat(g);
			cost.put(code, 0);
			Q.offer(code);

BFS:
			while(!Q.isEmpty())
			{
				//get item from queue
				now = Q.poll();
				C = cost.get(now);
				
				//g = state in grid form
				g = parse(now);
				used = new boolean[26];
				
				//visit g/now's neighbors
				for(i=0;i<6;++i)
				for(j=0;j<6;++j) if(g[i][j] != '.')
				{
					A = g[i][j];
					
					//move each piece once, when it is first encountered in a row major order scan.
					//Thus, (i, j) is the left most cell of a horizontal piece or a top most cell 
					//of a vertical piece.
					if(used[A - 'A']) continue;
					used[A - 'A'] = true;
					
					//If this is the special piece, then answer is 1 step away, assume to the right
					//of the piece is clear (all '.')
					//Since we are using BFS with uniform cost (moving from state to state all cost 1),
					//this is optimal
					if(special.charAt(0) == A && clear(g, i, j+2))
					{
						res = C+1;
						break BFS;
					}

					if(j+1<6 && A == g[i][j+1])
					{
						//horizontal piece, len is the length of this piece (number of cells it has)
						len = (j+2 < 6 && A == g[i][j+2] ? 3 : 2);
						
						//moving to the right, so long as nothing in the way
						for(k=j+1;k+len-1<6 && g[i][k+len-1]=='.';++k)
						{
							//moving by erasing the first cell on the left 
							//and adding 1 more cell to the right
							g[i][k-1] = '.';
							g[i][k+len-1] = A;
							
							//calculate new state as a String, and check for cost (which is equivalent to 
							//checking if the state visited or not in BFS)
							code = cat(g);
							if(!cost.containsKey(code))
							{
								//Add to the queue if this is a new state
								cost.put(code, C+1);
								Q.offer(code);
							}
						}
						
						//restore back to original board (now)
						for(k=k+len-2;k>=0 && g[i][k]==A;--k) g[i][k] = '.';
						for(z=0;z<len;++z) g[i][j+z] = A;
						
						//try moving left, so long as nothing is in the way
						for(k=j-1;k>=0 && g[i][k]=='.';--k)
						{
							//same idea as above, except erasing right most piece and add to the left
							g[i][k+len] = '.';
							g[i][k] = A;
							
							//check visited (same as above)
							code = cat(g);
							if(!cost.containsKey(code))
							{
								cost.put(code, C+1);
								Q.offer(code);
							}
						}
						
						//restore, this is necessary because we will use the same 
						//board, g, for moving the other pieces
						for(++k;k<6 && g[i][k]==A;++k) g[i][k] = '.';
						for(z=0;z<len;++z) g[i][j+z] = A;
					}
					else
					{
						//vertical piece, everything is done analogously to the horizontal case
						len = (i+2 < 6 && A == g[i+2][j] ? 3 : 2);
						
						for(k=i+1;k+len-1<6 && g[k+len-1][j]=='.';++k)
						{
							g[k-1][j] = '.';
							g[k+len-1][j] = A;

							code = cat(g);
							if(!cost.containsKey(code))
							{
								cost.put(code, C+1);
								Q.offer(code);
							}
						}
						
						//restore
						for(k=k+len-2;k>=0 && g[k][j]==A;--k) g[k][j] = '.';
						for(z=0;z<len;++z) g[i+z][j] = A;

						for(k=i-1;k>=0 && g[k][j]=='.';--k)
						{
							g[k+len][j] = '.';
							g[k][j] = A;

							code = cat(g);
							if(!cost.containsKey(code))
							{
								cost.put(code, C+1);
								Q.offer(code);
							}
						}

						//restore
						for(++k;k<6 && g[k][j]==A;++k) g[k][j] = '.';
						for(z=0;z<len;++z) g[i+z][j] = A;
					}
				}
			}
			
			out.println(res < oo ? res : -1);
			special = in.next();
		}
	}
	
	//make sure g[i][j..5] are all '.'s
	//This is used to check for a clearing path of the special piece (to move it out)
	public boolean clear(char[][] g, int i, int j)
	{
		while(j < 6)
		{
			if(g[i][j] != '.') return false;
			++j;
		}
		return true;
	}
	
	//convert a char[][] board into a String for state storage (taking advantage of java String hashing) 
	public String cat(char[][] g)
	{
		StringBuffer ret = new StringBuffer("");
		for(int i=0;i<g.length;++i) ret.append(new String(g[i]));
		return ret.toString();
	}
	
	//convert a String state back to a char[][] board
	public char[][] parse(String s)
	{
		char[][] r = new char[6][];
		for(int i=0;i<6;++i) r[i] = s.substring(i*6, (i+1)*6).toCharArray();
		return r;
	}

	public static void main(String[] args)
	{
		long startTime = System.currentTimeMillis();
		(new blockYiu()).main();
		long endTime = System.currentTimeMillis();

		System.err.println("Time = " + (endTime - startTime) + "(ms)");
	}
}
