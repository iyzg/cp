/*
ACM ICPC Southeast Regional Contest 2009

Robot Challenge

Author: Yiu Yu Ho
*/

import java.io.*;
import java.util.*;
import java.text.*;

public class robotYiu
{
	public Scanner in = new Scanner(System.in);
	public PrintStream out = System.out;
	public DecimalFormat fmt = new DecimalFormat("0.000");

	public final double T50 = 1e50;
	public final double tol = 1e-12;

	public int n;
	public int[] x, y, p, psum;

	public void main()
	{
		int i, j, k;

		n = in.nextInt();
		while(n > 0)
		{
			x = new int[n+2];
			y = new int[n+2];
			p = new int[n+2];
			psum = new int[n+2];

			x[0] = y[0] = 0;
			//(x[i], y[i], p[i]) are target location and penality
			//psum[i] = p[0] + p[1] + ... + p[i]
			for(i=1;i<=n;++i)
			{
				x[i] = in.nextInt();
				y[i] = in.nextInt();
				p[i] = in.nextInt();
				psum[i] = psum[i-1] + p[i];
			}
			x[n+1] = y[n+1] = 100;
			psum[n+1] = psum[n];
			
			//cost[i]: the optimal cost of starting at (0, 0) visiting/skipping target points {1, 2, ..., i-1} and 
			//visiting (and stopping for a second at) target point (x[i], y[i])
			double[] cost = new double[n+2];
			Arrays.fill(cost, T50);
			cost[0] = 0.0;

			for(i=1;i<=n+1;++i)
			{
				//last point may be point i-1
				cost[i] = cost[i-1] + dist(i-1, i) + 1.0;

				//try other possibilities, j, as the last point
				for(j=i-2;j>=0;--j)
				{
					//If the previous point is j, then the penality is p[j+1] + p[j+2] + ... + p[i-1]
					cost[i] = Math.min(cost[i], cost[j] + dist(j, i) + 1.0 + psum[i-1] - psum[j]);
					if(cost[i] < psum[i-1] - psum[j]) break;
				}
			}

			out.println(fmt.format(cost[n+1] + tol));

			n = in.nextInt();
		}
	}
	
	//distance between point (x[i], y[i]) and (x[j], y[j])
	public double dist(int i, int j)
	{
		double dx, dy;
		dx = x[i] - x[j];
		dy = y[i] - y[j];
		return Math.sqrt(dx*dx + dy*dy);
	}

	public static void main(String[] args)
	{
		long startTime = System.currentTimeMillis();
		(new robotYiu()).main();
		long endTime = System.currentTimeMillis();

		System.err.println("Time = " + (endTime - startTime) + "(ms)");
	}
}
