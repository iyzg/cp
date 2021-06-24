/*
ACM ICPC Southeast Regional 2009

Pool Table

Author: Yiu Yu Ho

Consider the pool table and reflect it along both horizontal and vertical axis for an
infinite number of times.  There will then be an infinite number of images of the target ball, 
a line L connecting the (real) cue ball of the pool table, and an image of a target ball is a 
possible path travelled from cue ball to target ball.  On the actual pool table, the number of 
reflections occurred equals the number of times L crosses boundaries of different pool table images.  

There are no animations here so use your imagination ;).
*/

import java.io.*;
import java.util.*;
import java.text.*;

public class poolYiu
{
	public Scanner in = new Scanner(System.in);
	public PrintStream out = System.out;

	public DecimalFormat fmt = new DecimalFormat("0.000");

	public final double T50 = 1e50;
	public final double tol = 1e-12;
	
	//(X, Y): dimension of pool table
	//(Sx, Sy): starting point (cue ball)
	//(Tx, Ty): target point
	public int X, Y, Sx, Sy, Tx, Ty, n;
	public double res;

	public void main()
	{
		int i, j, k, rx, ry;

		X = in.nextInt();
		while(X > 0)
		{
			Y = in.nextInt();
			Sx = in.nextInt(); Sy = in.nextInt();
			Tx = in.nextInt(); Ty = in.nextInt();
			n = in.nextInt();
			
			//We need n reflections, (rx, ry) is the number of times line L crosses 
			//(vertical, horizontal) boundaries respectively.
			//Thus, we need |rx| + |ry| = n
			res = T50;
			for(rx = -n; rx <= n; ++rx)
			{
				ry = n - Math.abs(rx);
				check(rx, ry);
				check(rx, -ry);
			}
			
			out.println(fmt.format(res + tol));
			X = in.nextInt();
		}
	}
	
	//Given (rx, ry), we know we meet the required number of reflections
	//Now we need to ensure that there are no pre-mature collisions with (other images of) 
	//the target ball, and keep track of minimum over all feasible solutions.
	public void check(int rx, int ry)
	{
		double dist;
		int x, y;
		
		//(x, y) is the location of target ball image
		x = reflect(rx, Tx, X);
		y = reflect(ry, Ty, Y);

		dist = dist(Sx, Sy, x, y);

		if(dist < res && free(Sx, Sy, x, y))
		{
			res = dist;
		}
	}
	
	//calculates the location of target ball imagine, given that it is reflected rx times 
	//(rx may be negative)
	public int reflect(int rx, int Tx, int X)
	{
		int x;
		if(rx >= 0)
		{
			x = Tx + (rx/2)*(X+X);
			if(rx%2 == 1) x += 2*(X-Tx);
		}
		else
		{
			//rx < 0
			x = Tx + (rx/2)*(X+X);
			if(rx%2 == -1) x -= 2*(Tx);
		}

		return x;
	}
	
	//check if travelling from (ax, ay) to (bx, by) will not hit any other taget ball image, this corresponds to 
	//the lack of pre-mature collision in the original setting, which means the given solution is feasible.
	public boolean free(int ax, int ay, int bx, int by)
	{
		int dx, dy;
		//a --> b
		dx = bx - ax;
		dy = by - ay;
		
		//This is partitioned into 4 cases, each case tests all target ball imagines of the 
		//form (Tx', Ty') + (2X * K1, 2Y * K2), for integers K1, K2.
		//The 4 cases together covers all target ball images.
		if(!OK(Tx,     Ty,     ax, ay, dx, dy)) return false;
		if(!OK(2*X-Tx, Ty,     ax, ay, dx, dy)) return false;
		if(!OK(Tx,     2*Y-Ty, ax, ay, dx, dy)) return false;
		if(!OK(2*X-Tx, 2*Y-Ty, ax, ay, dx, dy)) return false;

		return true;
	}
	
	//check if any points of the form (cx, cy) + (2X * K1, 2Y * K2) are on the segment (ax, ay) + p * (dx, dy) 
	//for integers K1, K2 and real p, where 0 < p < 1
	public boolean OK(int cx, int cy, int ax, int ay, int dx, int dy)
	{
		//Since this is now a boolean function, we can change our coordinate system without having to worry 
		//about transforming between coordinate systems at the end.
		if(dx == 0) return OK(cy, cx, ay, ax, dy, dx);
		if(dx < 0) return OK(-cx, cy, -ax, ay, -dx, dy);
		//dx > 0
		int low, high, K1, K2;
		double p;
		
		//lower and upper bounds for K1, base on the the x-values of the segment
		low = (ax - cx)/(X+X) - 10;
		high = (ax+dx-cx)/(X+X) + 10;
		
		for(K1 = low; K1 <= high; ++K1)
		{
			p = (double)(cx + K1*(X+X) - ax)/(dx);
			if(!(0+tol < p && p+tol < 1.0)) continue;

			//p strictly within (0, 1)
			
			//solve for K2, if it is an integer, then we have pre-mature collision
			if(isInteger((double)(ay+p*dy-cy)/(Y+Y))) return false;
		}

		return true;
	}

	public boolean isInteger(double x)
	{
		return eq(Math.IEEEremainder(x, 1.0), 0.0);
	}
	
	//distance between point (ax, ay) and (bx, by)
	public double dist(double ax, double ay, double bx, double by)
	{
		double dx, dy;
		dx = ax - bx;
		dy = ay - by;
		return Math.sqrt(dx*dx + dy*dy);
	}

	public boolean eq(double x, double y) { return Math.abs(x - y) < tol; }

	public static void main(String[] args)
	{
		(new poolYiu()).main();
	}
}
