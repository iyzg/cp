/*
ACM ICPC Southeast Regional Contest 2009

Euclid

Author: Yiu Yu Ho
*/

import java.io.*;
import java.util.*;
import java.text.*;

public class euclidYiu
{
	public Scanner in = new Scanner(System.in);
	public PrintStream out = System.out;
	public DecimalFormat fmt = new DecimalFormat("0.000");

	public double tol = 1e-12;

	private class Pair
	{
		public double x, y;

		public Pair(double xx, double yy) { x = xx; y = yy; }
		public double Across(Pair u) { return Math.abs(x * u.y - y * u.x); }

		public Pair add(Pair u) { return new Pair(x + u.x, y + u.y); }
		public Pair subtract(Pair u) { return new Pair(x - u.x, y - u.y); }
		public Pair multiply(double s) { return new Pair(s*x, s*y); }
	}

	public Pair A, B, C, D, E, F, G, H;
	public Pair AB, AC, DE, DF;

	public void main()
	{
		int i;
		double[] v;
		double low, high, t, area;
		
		v = new double[12];
		for(i=0;i<12;++i) v[i] = in.nextDouble();

		while(!allZero(v))
		{
			A = new Pair(v[0], v[1]);
			B = new Pair(v[2], v[3]);
			C = new Pair(v[4], v[5]);

			D = new Pair(v[6], v[7]);
			E = new Pair(v[8], v[9]);
			F = new Pair(v[10], v[11]);
			
			//AB = B - A, AC = C - A.
			//They are vectors
			AB = B.subtract(A);
			AC = C.subtract(A);
			
			DE = E.subtract(D);
			DF = F.subtract(D);
			
			//cross product of 2 vectors gives the area of the parallelogram with 
			//adjacent sides equal to the 2 vectors.  
			//See any calculus or computational geometry book for details
			area = DE.Across(DF)/2.0;
			
			//Binary search for the answer: 
			//Let H = A + t * AC, and then the length of AH is determined by parameter t, 
			//whereas the area of ABGH depends on the length of H, so binary search on t

			//First, get proper lower and upper bounds on t
			low = 0.0;
			high = 1.0;

			while(f(high) < area)
			{
				//The value of high is too small, so it can be a lower bound,
				//and we increase its value exponentially until it gets to an upper bound
				low = high;
				high += high;
			}
			
			//Phase 2, regular binary search
			for(i=0;i<100;++i)
			{
				t = (low + high)/2.0;
				if(f(t) < area) low = t;
				else high = t;
			}
			
			//Get t, then plug in for H and G
			t = (low + high)/2.0;
			
			H = A.add(AC.multiply(t));
			G = B.add(AC.multiply(t));
			
			out.println(fmt.format(G.x + tol)+" "+fmt.format(G.y + tol)
				   +" "+fmt.format(H.x + tol)+" "+fmt.format(H.y + tol));

			for(i=0;i<12;++i) v[i] = in.nextDouble();
		}
	}
	
	//Calculates the area of ABGH, given parameter t, defined above.
	public double f(double t)
	{
		return AC.multiply(t).Across(AB);
	}
	
	//check for termination
	public boolean allZero(double[] v)
	{
		for(int i=0;i<v.length;++i)
		if(!eq(v[i], 0.0)) return false;

		return true;
	}

	public boolean eq(double x, double y) { return Math.abs(x - y) < tol; }

	public static void main(String[] args)
	{
		long startTime = System.currentTimeMillis();
		(new euclidYiu()).main();
		long endTime = System.currentTimeMillis();

		System.err.println("Time = " + (endTime - startTime) + "(ms)");
	}
}

