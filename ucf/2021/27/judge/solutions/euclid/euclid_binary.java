import java.io.*;
import java.util.*;
import java.awt.*;
import java.text.*;
import java.math.*;

class euclid_binary
{
    public Scanner sc;
    public PrintStream ps;

    public String toString()
    {
        return "euclid_binary";
    }
    
    // Return true if x is sufficiently close to 0
    public boolean z( double x )
    {
    	return x>-0.000001 && x<0.000001;
    }
    
    // Distance between two points
    public double dist( double x1, double y1, double x2, double y2 )
    {
    	double dx = x2-x1;
    	double dy = y2-y1;
    	return Math.sqrt( dx*dx + dy*dy );
    }
    
    // Area of a polygon
    public double polyarea( double xs[], double ys[] )
    {
    	int n = xs.length;
    	double area = (xs[0]-xs[n-1])*(ys[0]+ys[n-1]);
    	
    	for( int i=0; i<n-1; i++ )
    	{
    		area += (xs[i+1]-xs[i])*(ys[i+1]+ys[i]);
    	}
    	    	
    	return 0.5 * Math.abs( area );
    }
    
    public double ax, ay, bx, by, cx, cy, dx, dy, ex, ey, fx, fy;
    public double triarea;
    public double parax[] = new double[4]; 
    public double paray[] = new double[4]; 
    
    public double gx( double t )
    {
        return bx + t*(cx-ax);	
    }
    
    public double gy( double t )
    {
        return by + t*(cy-ay);	
    }
    
    public double hx( double t )
    {
        return ax + t*(cx-ax);	
    }
    
    public double hy( double t )
    {
        return ay + t*(cy-ay);	
    }
    
    public double f( double t )
    {
    	parax[2] = gx(t); paray[2] = gy(t);
    	parax[3] = hx(t); paray[3] = hy(t);
    	return polyarea( parax, paray ) - triarea;
    }
                
    public void doit() throws Exception
    {
        sc = new Scanner( new File( "euclid.judge" ) );
        ps = System.out;
        
        for(;;)
        {
        	ax = sc.nextDouble();
        	ay = sc.nextDouble();
        	bx = sc.nextDouble();
        	by = sc.nextDouble();
        	cx = sc.nextDouble();
        	cy = sc.nextDouble();
        	dx = sc.nextDouble();
        	dy = sc.nextDouble();
        	ex = sc.nextDouble();
        	ey = sc.nextDouble();
        	fx = sc.nextDouble();
        	fy = sc.nextDouble();
        	
        	if( z(ax) && z(ay) && z(bx) && z(by) && z(cx) && z(cy) ) break;
        	
        	double trix[] = new double[3];
        	double triy[] = new double[3];
        	trix[0] = dx; triy[0] = dy;
        	trix[1] = ex; triy[1] = ey;
        	trix[2] = fx; triy[2] = fy;
        	
        	triarea = polyarea( trix, triy );
        	        	
        	parax[0] = ax; paray[0] = ay;
        	parax[1] = bx; paray[1] = by;
        	
        	double lo = 0.0;
        	double hi = 1.0;
        	while( f(hi)<0.0 )
        	{
        		lo = hi; hi *= 10.0;
        	}
        	        	
        	while( !z(gx(lo)-gx(hi)) || !z(gy(lo)-gy(hi)) || !z(hx(lo)-hx(hi)) || !z(hy(lo)-hy(hi)) )
        	{
        	    double mid = (lo+hi)/2.0;
        	    if( f(mid)<0.0 )
        	    {
        	        lo = mid;
        	    }
        	    else
        	    {
        	    	hi = mid;
        	    }
        	}
        	
        	
        	ps.printf( "%.3f %.3f %.3f %.3f", gx(lo), gy(lo), hx(lo), hy(lo) );
        	ps.println();
        }
    }

	public static void main(String[] args) throws Exception
	{
		long starttime = System.currentTimeMillis();
		new euclid_binary().doit();
		System.out.println( System.currentTimeMillis() - starttime );
	}
}
