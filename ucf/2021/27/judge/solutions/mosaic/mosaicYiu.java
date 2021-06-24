/*
ACM ICPC Southeast Regional Contest 2009

Mosaic

Author: Yiu Yu Ho
*/

import java.io.*;
import java.util.*;

public class mosaicYiu
{
	public Scanner in = new Scanner(System.in);
	public PrintStream out = System.out;

	public int Mod = 1000000;

	public int rn, cn, lim;

	public void main()
	{
		int r, c, set;
		int S;

		cn = in.nextInt();
		while(cn > 0)
		{
			rn = in.nextInt();

			//We tile the rectangle in a row major order, as we proceed, we keep track of the interface between 
			//the completely tiled area and the completely un-tiled area, which should consist of cn+1 cells.
			//That is, if we are tiling cell (r, c), then cells before (r, c) in the row-major order must all be 
			//tiled (occupied) and cells after (r+1, c) in the row-major order must be empty (unoccupied), the 
			//status (tiled-ness) of cells in between (r, c) and (r+1, c), inclusive, are kept track by the bit mask. 
			lim = 1 << (cn+1);

			int[] cur, nxt;
			
			cur = new int[lim];
			cur[0] = 1 % Mod;

			for(r=0;r<rn;++r)
			for(c=0;c<cn;++c)
			{
				//cur retains information up to (r, c-1)
				//In the mask, the 0-th bit is (r, c), 1-st bit is (r, c+1), etc., and the cn-th bit is (r+1, c)
				nxt = new int[lim];

				for(set=0;set<lim;++set) if(cur[set] > 0)
				{
					if(in(0, set))
					{
						//already filled, move to the next tile inheriting the current state
						S = (set >> 1);
						nxt[S] = (nxt[S] + cur[set]) % Mod;
					}
					else
					{
						//not filled, try all 5 possible tilings
						if(c+1 < cn && !in(1, set) && !in(cn, set))
						{
							S = (set >> 1);
							S = on(0, S);
							S = on(cn-1, S);
							
							//xx
							//x.
							nxt[S] = (nxt[S] + cur[set]) % Mod;
							
							S = on(cn, S);

							//xx
							//xx
							nxt[S] = (nxt[S] + cur[set]) % Mod;
						}

						if(c+1 < cn && !in(cn, set))
						{
							S = (set >> 1);
							S = on(cn-1, S);
							S = on(cn, S);
							
							//x.
							//xx
							nxt[S] = (nxt[S] + cur[set]) % Mod;
						}

						if(c+1 < cn && !in(1, set))
						{
							S = (set >> 1);
							S = on(0, S);
							S = on(cn, S);
							
							//xx
							//.x
							nxt[S] = (nxt[S] + cur[set]) % Mod;
						}

						if(c > 0 && !in(cn-1, set) && !in(cn, set))
						{
							S = (set >> 1);
							S = on(cn-2, S);
							S = on(cn-1, S);
							
							//.x
							//xx
							nxt[S] = (nxt[S] + cur[set]) % Mod;
						}
					}
				}//end for set = 0 .. lim-1

				cur = nxt;
			}//end for r = 0 .. rn-1, c = 0 .. cn-1
			
			//At the end, we want every before (rn+1, 0) to be tiled, and in the interface there are no tiles.
			out.println(cur[0]);
			cn = in.nextInt();
		}
	}
	
	//Check if bit x is on (the corresponding cell is tiled)
	public boolean in(int x, int set)
	{
		return (set & (1<<x))!=0;
	}
	
	//Turns on bit x from set and return the new set
	public int on(int x, int set)
	{
		return set | (1 << x);
	}

	public static void main(String[] args)
	{
		long startTime = System.currentTimeMillis();
		(new mosaicYiu()).main();
		long endTime = System.currentTimeMillis();

		System.err.println("Time = " + (endTime - startTime) + "(ms)");
	}
}

