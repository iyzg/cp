import java.io.*;
import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import java.text.*;
import java.math.*;

/**
 * Solution to Robot Challenge using Dynamic Programming
 */
class robotchallenge
{
    public Scanner sc;
    public PrintStream ps;

    public String toString()
    {
        return "robotchallenge";
    }

    /**
     * The main method
     */
    public void doit() throws Exception
    {
        sc = new Scanner( System.in ); // new Scanner( new File( "robotchallenge.judge" ) );
        ps = System.out; // new PrintStream( new FileOutputStream( "robotchallenge.solution" ) );
        for(;;)
        {
        	// Read in n, exit if done
            int n = sc.nextInt();
            if( n==0 ) break;

            // We're going to add 2 points to the input.
            // The start (0,0) and the end (100,100)
            n += 2;
            int xs[] = new int[n];
            int ys[] = new int[n];
            int penalties[] = new int[n];

            // The start will be the first point, with a practically infinite penalty
            xs[0] = 0;
            ys[0] = 0;
            penalties[0] = 1000000000;

            // Read in the target points
            for( int i=1; i<n-1; i++ )
            {
                xs[i] = sc.nextInt();
                ys[i] = sc.nextInt();
                penalties[i] = sc.nextInt();
            }

            // The end will be the last point, with a practically infinite penalty
            xs[n-1] = 100;
            ys[n-1] = 100;
            penalties[n-1] = 100000000;

            // best[i] is the best possible score for the rest of the 
            // course if we stop at point i
            double best[] = new double[n];

            // It costs 1 second to stop at the final point (100,100)
            best[n-1] = 1.0;

            // Simple 1d Dynamic Programming
            for( int i=n-2; i>=0; i-- )
            {
            	// Keep a running total of the penalties
                int penalty = 0;
                
                // This is the worst possible value for best[i]
                best[i] = Double.MAX_VALUE;
                
                // What if we go straight from Target Point i to Target Point j?
                for( int j=i+1; j<n; j++ )
                {
                    // Since the robot moves at 1 m/s, the distance (in meters)
                    // is the same as the time (in seconds)
                    int dx = xs[j] - xs[i];
                    int dy = ys[j] - ys[i];
                    double distance = Math.sqrt( dx*dx + dy*dy );

                    // Cost for stopping at i, then going to j is
                    //     1.0 (for the one second stop at i)
                    //   + distance (from i to j)
                    //   + penalty (for skipping points between i and j)
                    //   + best[j] (the best we can do for the rest of the course stopping at j)
                    double cost = 1.0 + distance + penalty + best[j];
                    if( cost<best[i] ) best[i] = cost;

                    // OK, we're done with j.
                    // So, Add in the penalty for skipping j.
                    penalty += penalties[j];

                    // Break out if it's too big. The penalty will only increase,
                    // and if it gets too large, it can't possibly lead to a better cost.
                    // Why the +3.0? Look at how 'cost' is computed.
                    // We know 'penalty' will get 1 added to it (for the 1 second stop)
                    // and we know the points are unique, so the shortest possible
                    // distance is 1, and we know that best[j] will be at least 1.
                    if( penalty+3.0 >= best[i] ) break;
                }
            }

            // So, the answer is the best possible score from the start through the course.
            // We treated the start point (0,0) just like any other point - that means we
            // figured in stopping there for 1 second. But, that's not right - we shouldn't
            // stop at the starting spot at all. So, our answer is exactly 1 second too high.
            ps.printf( "%.3f", best[0]-1.0 );
            ps.println();
        }
    }
    
    public static Random random = new Random();
    
    public static void shuffle( Point a[] )
    {
    	for( int i=0; i<a.length; i++ )
    	{
    		int j = random.nextInt( a.length );
    		Point p = a[i];
    		a[i] = a[j];
    		a[j] = p;
    	}
    }
    
    public static double distance( Point p1, Point p2 )
    {
        int dx = p1.x - p2.x;
        int dy = p1.y - p2.y;
        return Math.sqrt( dx*dx + dy*dy );
    }

	public static void main(String[] args) throws Exception
	{
		/*
		// An array of points for shuffling
		Point a[] = new Point[99*99];
		int k=0;
		for( int x=1; x<=99; x++ ) for( int y=1; y<=99; y++ )
		{
		    a[k++] = new Point( x, y );	
		}
		
		// Snake-like walk, minimizing distance between points
		Point snake[] = new Point[99*99];
		k=0;
		for( int x=1; x<=99; x+= 2 )
		{
		    for( int y=1; y<=99; y++ )
		    {
		    	snake[k++] = new Point( x, y );
		    }
		    if( x<99 ) for( int y=99; y>=1; y-- )
		    {
		    	snake[k++] = new Point( x+1, y );
		    }
		}
		
		// Cross walk, crossing the arena as many times as possible
		Point cross[] = new Point[99*99];
		k = 0;
		int dn = snake.length-1;
		int up = 0;
		while( k<cross.length )
		{
			if( k%2==0 )
			{
			    cross[k++] = snake[dn--];
			}
			else
			{
			    cross[k++] = snake[up++];
			}
		}
		
		// Snake, penalty=1
		System.out.println( 1000 );
		for( int i=0; i<1000; i++ )
		{
		    System.out.println( snake[i].x + " " + snake[i].y + " 1" );	
		}
		// Snake, penalty=50
		System.out.println( 1000 );
		for( int i=0; i<1000; i++ )
		{
		    System.out.println( snake[i].x + " " + snake[i].y + " 50" );	
		}
		// Snake, penalty=100
		System.out.println( 1000 );
		for( int i=0; i<1000; i++ )
		{
		    System.out.println( snake[i].x + " " + snake[i].y + " 100" );	
		}
		// Snake, penalty=random
		System.out.println( 1000 );
		for( int i=0; i<1000; i++ )
		{
		    System.out.println( snake[i].x + " " + snake[i].y + " " + (random.nextInt(100)+1));	
		}
		
		// Cross, penalty=1
		System.out.println( 1000 );
		for( int i=0; i<1000; i++ )
		{
		    System.out.println( cross[i].x + " " + cross[i].y + " 1" );	
		}
		// Cross, penalty=50
		System.out.println( 1000 );
		for( int i=0; i<1000; i++ )
		{
		    System.out.println( cross[i].x + " " + cross[i].y + " 50" );	
		}
		// Cross, penalty=100
		System.out.println( 1000 );
		for( int i=0; i<1000; i++ )
		{
		    System.out.println( cross[i].x + " " + cross[i].y + " 100" );	
		}
		// Cross, penalty=random
		System.out.println( 1000 );
		for( int i=0; i<1000; i++ )
		{
		    System.out.println( cross[i].x + " " + cross[i].y + " " + (random.nextInt(100)+1));	
		}
		
		// Max number, penalty 1, order random
		shuffle(a);
		System.out.println( 1000 );
		for( int i=0; i<1000; i++ )
		{
			System.out.println( a[i].x + " " + a[i].y + " 1" );
		}
		
		// Max number, penalty 100, order random
		shuffle(a);
		System.out.println( 1000 );
		for( int i=0; i<1000; i++ )
		{
			System.out.println( a[i].x + " " + a[i].y + " 100" );
		}
		
		// Max number, penalty 50, order random
		shuffle(a);
		System.out.println( 1000 );
		for( int i=0; i<1000; i++ )
		{
			System.out.println( a[i].x + " " + a[i].y + " 50" );
		}
		
		// Max number, penalty random, order random
		shuffle(a);
		System.out.println( 1000 );
		for( int i=0; i<1000; i++ )
		{
			System.out.println( a[i].x + " " + a[i].y + " " + (random.nextInt(100)+1) );
		}
		
		// Ten more random cases
		for( k=0; k<10; k++ )
		{
			int n = random.nextInt( 1000 ) + 1;
			shuffle( a );
			System.out.println( n );
			for( int i=0; i<n; i++ )
			{
				System.out.println( a[i].x + " " + a[i].y + " " + (random.nextInt(100)+1) );
			}
		}
        */
		long starttime = System.currentTimeMillis();
		new robotchallenge().doit();
		System.out.println( System.currentTimeMillis() - starttime );

	}
}
