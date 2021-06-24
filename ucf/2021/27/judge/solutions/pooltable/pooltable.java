import java.io.*;
import java.util.*;
import java.awt.*;
import java.text.*;
import java.math.*;

/**
 * Solution to Pool Table
 * 
 * This solution won't try to compute reflections. Instead, it'll set up 
 * a coordinate system of reflected pool tables, like this:
 * 
 * +-------+-------+-------+-------+
 * | t     |     t | t     |     t |
 * |       |       |       |       |
 * +-------+-------+-------+-------+
 * |       |       |       |       |
 * | t     |     t | t     |     t |
 * +-------+=======+-------+-------+
 * | t     [     T ] t     |     t |
 * |       [ C     ]       |       |
 * +-------+=======+-------+-------+
 * |       |       |       |       |
 * | t     |     t | t     |     t |
 * +-------+-------+-------+-------+
 * 
 * Here, C is the Cue, T is the Target, and the t's represent the Target's image 
 * in reflections of the pool table.
 * 
 * So, if we have to bounce off 5 edges before hitting the target, then we look at
 * the reflection of the table that's 5 up and 0 over, and then 4 up and 1 over, 
 * 3 up and 2 over, and so on. We have to go all the way around, so we also have
 * to check -2 up and 3 over, 1 up and -4 over, and so on. Then, we have to check
 * lesser reflections, to see of there's any reflection of the Target that's between
 * our desired Target and the Cue, meaning that the Cue would hit the Target before
 * hitting the required number of Edges.
 */
class pooltable
{
    public Scanner sc;
    public PrintStream ps;

    public String toString()
    {
        return "pooltable";
    }
    
    /**
     * Distance between two points (x1,y1) and (x2,y2).
     * 
     * @param x1
     * @param y1
     * @param x2
     * @param y2
     * @return The distance between (x1,y1) and (x2,y2)
     */
    public double distance( int x1, int y1, int x2, int y2 )
    {
    	double dx = x2-x1;
    	double dy = y2-y1;
    	return Math.sqrt( dx*dx + dy*dy );
    }
    
    /**
     * Determine if points (ax,ay), (bx,by) and (cx,cy) lie on the same line.
     * 
     * @param ax
     * @param ay
     * @param bx
     * @param by
     * @param cx
     * @param cy
     * @return true if (ax,ay), (bx,by) and (cx,cy) lie on the same line, otherwise false
     */
    public boolean collinear( int ax, int ay, int bx, int by, int cx, int cy )
    {
    	boolean result = false;
    	
    	if( ay==by )
    	{
	    	// Check if they all have the same Y coord
    		result = (by==cy);
    	}
     	else if( ax==bx )
    	{
	    	// Check if they all have the same X coord
   		    result = (bx==cx);
    	}
    	else
    	{
    		// They're collinear if A-B has the same slope as B-C
    		//
    		//          by-ay   cy-by
    		// That is, ----- = -----
    		//          bx-ax   cx-bx
    		//
    		// Cross multiply so we can keep things all in integers, and we get this:
    		result = ((by-ay)*(cx-bx) == (cy-by)*(bx-ax));
    	}
    	
    	return result;
    }
    
    /**
     * Determine if point (x2,y2) lies between points (x1,y1) and (x3,y3).
     * 
     * @param x1 
     * @param y1 
     * @param x2 
     * @param y2 
     * @param x3 
     * @param y3 
     * @return true if (x2,y2) lies between (x1,y1) and (x3,y3), otherwise false
     */
    public boolean between( int x1, int y1, int x2, int y2, int x3, int y3 )
    {    	
    	// Is x2 between x1 and x3?
    	boolean xbetween = (x1<x3) ? (x1<=x2 && x2<=x3) : (x3<=x2 && x2<=x1);
    	
    	// Is y2 between y1 and y3?
    	boolean ybetween = (y1<y3) ? (y1<=y2 && y2<=y3) : (y3<=y2 && y2<=y1);
    	
    	// Are both coordinates in the right range, AND the points lie on the same line?
    	return xbetween && ybetween && collinear( x1, y1, x2, y2, x3, y3 );
    }
    
    // Input parameters: w=width, l=length, (xc,yc)=Cue position,
    // (xb,yb)=Target ball position, nbounces=number of times it must bounce off the edge.
    public int w, l, xc, yc, xb, yb, nbounces;    
    
    // Remember the best (smallest) distance. This will be our final answer.
    public double best;
    
    /**
     * Compute the X coordinate of the target ball on
     * a reflected pool table that's 'over' over.
     * 
     * @param over How many reflections over
     * @return The x coordinate
     */
    public int x( int over )
    {
        return over*l + ((over&1)==0?xb:l-xb);	
    }
    
    /**
     * Compute the Y coordinate of the target ball on
     * a reflected pool table that's 'up' up.
     * 
     * @param over How many reflections up
     * @return The y coordinate
     */
    public int y( int up )
    {
        return up*w + ((up&1)==0?yb:w-yb);	
    }
    
    /**
     * Check the reflection of the Target ball on a reflected pool table
     * that's 'up' up and 'over' over. First, see if there are any lesser reflections
     * that would get in the way. If not, compute the distance between
     * the Cue and the reflected Target, and remember it if it's the smallest.
     * 
     * @param up Number of reflected pool tables up
     * @param over Number of reflected pool tables over
     */
    public void check( int up, int over )
    {
    	// Compute (x,y) position of the Target ball's reflection here.
    	int xr = x(over);
    	int yr = y(up);
    	    	
    	// Compute min and max of up and over.
    	// We'll iterate over all of these to try to find lesser reflections
    	// that block our path.
    	int uplo = Math.min( up, 0 );
    	int uphi = Math.max( up, 0 );
    	int overlo = Math.min( over, 0 );
    	int overhi = Math.max( over, 0 );
    	    	
    	// Is the shot from the Cur to this reflection of the Target
    	// blocked by an earlier reflection of the Target?
    	boolean unblocked = true;
    	
    	// Iterate over the entire space from [0,0] to [up,over].
    	// Yeah, that's a lot more than you really need to check, but
    	// the numbers are small enough that it'll be fast enough,
    	// and we won't have to worry about debugging a tricky algorithm.
    	for( int u=uplo; u<=uphi && unblocked; u++ ) 
    	for( int o=overlo; o<=overhi && unblocked; o++ )
    	{
    		// Ignore the reflection that we're actually checking
	        if( u!=up || o!=over )
	    	{
	        	// Does the Target reflection here block the path
	        	// between the Cue and the Target reflection we're really interested in?
	    	    unblocked = !between( xc, yc, x(o), y(u), xr, yr );
	    	}
    	}
    	
    	// If there's a clear shot
		if( unblocked ) 
		{
			// Remember this if it is the minimum distance we've seen so far.
			best = Math.min( best, distance( xc, yc, xr, yr ) );       			
		}
    }
        
    public void doit() throws Exception
    {
        sc = new Scanner( System.in ); // new Scanner( new File( "pooltable.judge" ) );
        ps = System.out; // new PrintStream( new FileOutputStream( "pooltable.solution" ) );
        
        for(;;)
        {
        	// Read Length and Width, exit if done.
        	l = sc.nextInt();
        	w = sc.nextInt();
        	if( l==0 || w==0 ) break;
        	
        	// Read the rest of the input
        	xc = sc.nextInt();
        	yc = sc.nextInt();
        	xb = sc.nextInt();
        	yb = sc.nextInt();
        	nbounces = sc.nextInt();
        	  
        	// Worst possible value for 'best'
        	best = Double.MAX_VALUE;
        	
        	// Go through all possible values for 'up'
        	for( int up = 0; up<=nbounces; up++ )
        	{
        		// up + over = nbounces
        		int over = nbounces - up;
        		
        		// Check all four quadrants
           		check( up, over );
           		check( -up, over );
           		check( up, -over );
           		check( -up, -over );
         	}
        	
        	// Print the answer
        	ps.printf( "%.3f", best );
        	ps.println();
        }
    }

	public static void main(String[] args) throws Exception
	{
    	long starttime = System.currentTimeMillis();
        new pooltable().doit();
        System.out.println( System.currentTimeMillis() - starttime );
	}
}
