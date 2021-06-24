/*
ACM ICPC Southeast Regional 2009

The Ninja Way

Author: Yiu Yu Ho
*/

import java.io.*;
import java.util.*;

public class ninjawayYiu
{
	public final int oo = 1000000000 + 1000;

	public Scanner in = new Scanner(System.in);
	public PrintStream out = System.out;

	public int n, D;
	public Tree[] v;
	public int[] L, R;

	private class Tree implements Comparable<Tree>
	{
		//i: index of the tree with respect to input order
		//h: height of the tree
		public int i, h;
		public Tree(int ii, int hh) { i = ii; h = hh; }
		public int compareTo(Tree u) { return h - u.h; }
	}

	public void main()
	{
		int i, j, k, x;

		n = in.nextInt();
		while(n > 0)
		{
			D = in.nextInt();

			v = new Tree[n];

			//(L[i], R[i]) are the leftmost and rightmost location tree i can be at
			L = new int[n];
			R = new int[n];
			
			for(i=0;i<n;++i)
			{
				v[i] = new Tree(i, in.nextInt());
				L[i] = -oo;
				R[i] = oo;
			}
			
			//sort by height
			Arrays.sort(v);

			//The shortest tree is fixed at position 0
			L[v[0].i] = R[v[0].i] = 0;

			boolean done, poss;
			
			done = false;
			poss = true;

			while(!done && poss)
			{
				done = true;

				//update base on input order
				for(i=0;i+1<n;++i) if(L[i]+1 > L[i+1])
				{
					L[i+1] = L[i]+1;
					done = false;
				}
				

				for(i=n-1;i-1>=0;--i) if(R[i]-1 < R[i-1])
				{
					R[i-1] = R[i]-1;
					done = false;
				}

				//update base on sorted order
				for(x=0;x+1<n;++x)
				{
					i = v[x].i;
					j = v[x+1].i;
					if(L[i] - D > L[j])
					{
						L[j] = L[i] - D;
						done = false;
					}

					if(R[i] + D < R[j])
					{
						R[j] = R[i] + D;
						done = false;
					}
				}
				
				//I am doing this in both directions to make sure propagation in both directions 
				//are handled quickly, in the hope to reduce the number of iterations of the while-loop.
				//It works ;)
				for(x=n-1;x-1>=0;--x)
				{
					i = v[x].i;
					j = v[x-1].i;

					if(L[i] - D > L[j])
					{
						L[j] = L[i] - D;
						done = false;
					}

					if(R[i] + D < R[j])
					{
						R[j] = R[i] + D;
						done = false;
					}
				}

				for(i=0;i<n;++i) if(L[i] > R[i]) poss = false;
			}//end while !done and poss
			
			if(poss)
			{
				i = v[n-1].i;
				//Note that because of input order constraint, L[i] and R[i] are either both negative 
				//or both positive
				out.println(Math.max(Math.abs(L[i]), Math.abs(R[i])));
			}
			else
			{
				out.println(-1);
			}

			n = in.nextInt();
		}//while n > 0
	}//end public void main()



	public static void main(String[] args)
	{
		long startTime = System.currentTimeMillis();
		(new ninjawayYiu()).main();
		long endTime = System.currentTimeMillis();

		System.err.println("Time = "+(endTime - startTime)+"(ms)");
	}
}
