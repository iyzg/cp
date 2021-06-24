import java.io.*;
import java.util.*;
import java.awt.*;
import java.awt.geom.*;
import java.text.*;
import java.math.*;

class robotchallenge_dijkstra
{
    public Scanner sc;
    public PrintStream ps;

    public String toString()
    {
        return "robotchallenge_dijkstra";
    }
    
    public class State implements Comparable<State>
    {
        public int node;
        public double cost;
        
        public State( int n, double c )
        {
        	node = n;
        	cost = c;
        }
        
        public int compareTo( State s )
        {
        	int result = Double.compare( cost, s.cost );
        	if( result==0 ) result = s.node - node;
        	
        	return result;
        }
    }

    public void doit() throws Exception
    {
        sc = new Scanner( new File( "robotchallenge.judge" ) );
        ps = System.out; //new PrintStream( new FileOutputStream( "robotchallenge.out" ) ); //System.out;
        PriorityQueue<State> queue = new PriorityQueue<State>();
                
        for(;;)
        {
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
            
            queue.clear();
            boolean visited[] = new boolean[n];
            Arrays.fill( visited, false );
            double answer = 0.0;
            
            queue.add( new State( 0, 0.0 )  );
            while( queue.size()>0 )
            {
            	State s = queue.poll();
             	if( !visited[s.node] )
            	{
            		visited[s.node] = true;
            		if( s.node==n-1 )
            		{
            		    answer = s.cost;
            		    break;
            		}
            		
            		double penalty = 0.0;
            		for( int i=s.node+1; i<n; i++ ) 
            	    {
            			if( !visited[i] )
	            		{
	            			int dx = xs[i]-xs[s.node];
	            			int dy = ys[i]-ys[s.node];
	            			double dist = Math.sqrt( dx*dx + dy*dy );
	            			double cost = s.cost + dist + penalty + 1.0;
	            			queue.add( new State( i, cost )  );
	            		}
            			penalty += penalties[i];
           	        }
            	}
            }
            
            ps.printf( "%.3f", answer );
            ps.println();

        }
    }
    
	public static void main(String[] args) throws Exception
	{
		long starttime = System.currentTimeMillis();
		new robotchallenge_dijkstra().doit();
		System.out.println( System.currentTimeMillis() - starttime );
	}
}
