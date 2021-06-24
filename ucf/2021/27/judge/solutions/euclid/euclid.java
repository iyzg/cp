import java.io.*;
import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import java.text.*;
import java.math.*;

/**
 * Solution to Euclid 
 * 
 * This version finds a closed-form solution, using mainly trig.
 */
class euclid
{
    public Scanner sc;
    public PrintStream ps;

    public String toString()
    {
        return "euclid";
    }
    
    /**
     * Determine if a double is sufficiently close to zero to be considered zero.
     * 
     * @param x A double to check
     * @return true if x is sufficiently close to zero, otherwise false.
     */
    public boolean z( double x )
    {
    	return x>-0.000001 && x<0.000001;
    }
    
    /**
     * Distance between points (x1,y1) and (x2,y2).
     * 
     * @param x1
     * @param y1
     * @param x2
     * @param y2
     * @return The distance between the points
     */
    public double dist( double x1, double y1, double x2, double y2 )
    {
    	double dx = x2-x1;
    	double dy = y2-y1;
    	return Math.sqrt( dx*dx + dy*dy );
    }
    
    /**
     * Compute the area of triangle (x1,y1)-(x2,y2)-(x3,y3) using Heron's formula.
     * 
     * @param x1
     * @param y1
     * @param x2
     * @param y2
     * @param x3
     * @param y3
     * @return The area of the triangle.
     */
    public double heron( double x1, double y1, double x2, double y2, double x3, double y3 )
    {
    	double d1 = dist( x1, y1, x2, y2 );
    	double d2 = dist( x2, y2, x3, y3 );
    	double d3 = dist( x1, y1, x3, y3 );
    	
    	double s = (d1 + d2 + d3) / 2.0;
    	
    	return Math.sqrt( s * (s-d1) * (s-d2) * (s-d3) );
    }
                
    /**
     * The main method.
     * @throws Exception
     */
    public void doit() throws Exception
    {
        sc = new Scanner( System.in ); // new Scanner( new File( "euclid.judge" ) );
        ps = System.out; // new PrintStream( new FileOutputStream( "euclid.solution" ) );
        
        for(;;)
        {
        	// Read in the twelve inputs
        	double ax = sc.nextDouble();
        	double ay = sc.nextDouble();
        	double bx = sc.nextDouble();
        	double by = sc.nextDouble();
        	double cx = sc.nextDouble();
        	double cy = sc.nextDouble();
        	double dx = sc.nextDouble();
        	double dy = sc.nextDouble();
        	double ex = sc.nextDouble();
        	double ey = sc.nextDouble();
        	double fx = sc.nextDouble();
        	double fy = sc.nextDouble();
        	
        	// Only need to check these six, 
        	// since the problem statement promises that A, B and C will
        	// not be collinear.
        	if( z(ax) && z(ay) && z(bx) && z(by) && z(cx) && z(cy) ) break;
        	
        	// A bit of notation - if points A, B and C form a triangle, then:
        	// Let A represent the angle at point A (same for B and C)
        	// Let a represent the distance of the edge OPPOSITE point A.
        	// That is, a = distance(BC), b = distance(AC), c = distance(AB).
        	
        	// Consider ABC to be a triangle.
        	// Compute distances of the lines opposite the points 
        	double c = dist( ax, ay, bx, by ); 
        	double b = dist( ax, ay, cx, cy );
        	double a = dist( bx, by, cx, cy );
        	
        	// Use the Law of Cosines to get angle A
        	// Law of Cosines sez that a*a = b*b + c*c - 2*b*c*cos(A)
        	// (where distances are notated as above - a is BC, b is AC and c is AB)
        	// So, solve for cos(A), we get this:
        	double cosine = (c*c+b*b-a*a) / (2.0*c*b);
        	        	
        	// Use Heron's formula to get the area of triangle DEF
        	double area = heron( dx, dy, ex, ey, fx, fy );
        	        	
        	// Now, compute the height of the parallelogram
        	// The area of a parallelogram is the same as that of a rectangle - base*height
        	//        C
        	//       /
        	//      H--------------------G
        	//     /|                   /
        	//    / |                  /
        	//   /  |height           /
        	//  /   |                /
        	// A----+---------------B
        	// Well, we know the base - that's AB (length is c).
        	double height = area / c;
        	
        	// Now we know the height, we have to figure out how far along
        	// ray AC to put point H.
        	//        C
        	//       /
        	//      H
        	//     /|
        	//    / |
        	//   /  |height
        	//  /   | 
        	// A----+---------------B
        	
        	
        	// Now, use the Law of Sines to get the distance along ray AC that H must be.
        	// Law of Sines sez that in a triangle, a/sin(A) = b/sin(B) = c/sin(C).
        	// (same notation as described above)
        	// Well, we've got a little right triangle here. So...
        	// 
        	// dist(AH)/sin(pi/2) = height/sin(A)
        	// 
        	// Well, sin(pi/2) = 1, and sin(A) = sqrt(1-cos(A)^2)
        	double dist = height / Math.sqrt( 1.0 - cosine*cosine );
        	
        	// Find how far along as a ratio
        	double ratio = dist / b;
        	
        	// Now we know the diff - how far along we should go in each direction
        	double diffx = ratio*(cx-ax);
        	double diffy = ratio*(cy-ay);
        	
        	// And we know H
        	double hx = ax + diffx;
        	double hy = ay + diffy;
        	
        	// And we know G
        	double gx = bx + diffx;
        	double gy = by + diffy;
        	
        	// A little something the judges used to screen out
        	// test cases which produced values that we considered too big.
        	if( Math.abs(gx)<1000000.0 && Math.abs(gy)<1000000.0 
        		&& Math.abs(hx)<1000000.0 && Math.abs(hx)<1000000.0 )
        	{
        	    ps.printf( "%.3f %.3f %.3f %.3f", gx, gy, hx, hy );
        	    ps.println();
        	}
        	else
        	{
        		ps.println( "PANIC: Results too big" );
        	}
        }
    }
    
    public static boolean collinear( double ax, double ay, double bx, double by, double cx, double cy )
    {
    	return Math.abs( Math.atan2(ay-by,ax-bx) - Math.atan2(by-cy,bx-cx) ) < 0.0001;
    }

	public static void main(String[] args) throws Exception
	{
		/*
		Point points[] = 
		{
			new Point( -1, 10),
			new Point( 0, 10 ),
			new Point( 1, 10 ),
			new Point( 10, 1 ),
			new Point( 10, 0 ),
			new Point( 10, -1 ),
			new Point( 1, -10 ),
			new Point( 0, -10 ),
			new Point( -1, -10 ),
			new Point( -10, -1 ),
			new Point( -10, 0 ),
			new Point( -10, 1 )
		};
		
		for( Point p : points ) for( Point q : points )
		{
			if( p!=q && !collinear( p.x, p.y, 0.0, 0.0, q.x, q.y ) )
			{
				System.out.println( "0 0 " + p.x + " " + p.y + " " + q.x + " " + q.y + " 20 20 30 25 25 15" );
			}
		}
		
		Random random = new Random();
		
		for( int i=0; i<1000; i++ )
		{
		    double ax = random.nextDouble()*2000.0 - 1000.0;
		    double ay = random.nextDouble()*2000.0 - 1000.0;
		    double bx = random.nextDouble()*2000.0 - 1000.0;
		    double by = random.nextDouble()*2000.0 - 1000.0;
		    double cx = random.nextDouble()*2000.0 - 1000.0;
		    double cy = random.nextDouble()*2000.0 - 1000.0;
		    double dx = random.nextDouble()*2000.0 - 1000.0;
		    double dy = random.nextDouble()*2000.0 - 1000.0;
		    double ex = random.nextDouble()*2000.0 - 1000.0;
		    double ey = random.nextDouble()*2000.0 - 1000.0;
		    double fx = random.nextDouble()*2000.0 - 1000.0;
		    double fy = random.nextDouble()*2000.0 - 1000.0;
		    if( !collinear( ax, ay, bx, by, cx, cy ) && !collinear( dx, dy, ex, ey, fx, fy ) )
		    {
		        System.out.printf( "%.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f", 
		        		ax, ay, bx, by, cx, cy, dx, dy, ex, ey, fx, fy);
		        System.out.println();
		    }
		}
		*/
		long starttime = System.currentTimeMillis();
		new euclid().doit();
		System.out.println( System.currentTimeMillis() - starttime );
	}
}
