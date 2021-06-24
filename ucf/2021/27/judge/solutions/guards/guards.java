import java.io.*;
import java.util.*;
import java.awt.*;
import java.text.*;
import java.math.*;

/**
 * Solution to Museum Guards
 * 
 * We'll frame this as a Max Flow problem, but with a twist. We'll start with a brief
 * discussion of Max Flow problems.
 * 
 * Consider a directional, weighted graph that has a special node called the 'Source', 
 * and another called the 'Sink'. Consider the weights to be a 'capacity'. Think of
 * each edge like a one-way pipe, and the 'capacity' is the most stuff you can push through that pipe.
 * (The internet is a series of tubes, right?) Well, the question is... How much stuff can you
 * push from the Source to the Sink, given the limited capacities of all the edges?
 * 
 * The solution technique for a Max Flow problem is called Ford-Fulkerson, and I'll only
 * give a brief outline of it here. 
 * 
 * First, for every edge A->B, create a dual edge, B->A, which starts with 0 capacity.
 * The way to think of A->B and its capacity is: How much capacity is available to use.
 * The way to think of B->A and its capacity is: How much capacity has been used, that I could give back if I had to.
 * That's why B->A starts out as 0 - because, at the beginning of the algorithm, you haven't done anything,
 * so you haven't used any capacity.
 * 
 * Now, find a path from the Source to the Sink, only traversing edges that have some capacity (that is, capacity>0),
 * and don't hit any node more than once. You can find this path any way you like, but Breadth-First Search
 * has become the standard. This program will use BFS, but DFS or any other method is fine.
 * 
 * When you've got a path, go back over the edges on the path, and find the one with the smallest
 * capacity. That's the most stuff you can push through that path, right? That's the weakest link.
 * Then, go back over the path again, and move that amount of capacity from each edge to its dual
 * (that is, subtract it from each edge, add it to each edge's dual). 
 * 
 * Keep doing this (finding paths, finding the min capacity, moving that capacity from each edge 
 * to its dual) until you can't find a path with >0 capacity. Then, you're done! The total amount
 * of capacity that you moved over all the paths you found is the Max Flow!
 * 
 * OK, so how do we see Museum Guards as a Max Flow problem? 
 * Well, the 'stuff' we'll flow through the system is guard-periods. Build two kinds of nodes,
 * for guards, and for time periods. Link the Source to each guard, with the capacity being the 
 * number of time periods that guard is able to work. Link a guard to a time period if the guard
 * is willing to work that time period, with capacity 1. Finally, link the time periods to the sink. 
 * What should the capacity for those edges be? Well, that's tough. We could set them all to n, 
 * and see how many guard-periods flow through - but we have no way of forcing the 
 * guard-periods to be balanced over the time periods. Some periods could be over-represented,
 * and some under-represented. The result wouldn't be meaningful. Hmmm....
 * 
 * Consider this: If we set the capacity of each of those links to some value x, 0<=x<=n, 
 * and we get a total flow of x*48 (48=number of 30 minute periods in a day), 
 * then we know we can cover all time periods with x guards. The only way to get
 * a total flow of x*48 is to get a full x from each of the 48 time periods. We can't get
 * any more from one time period (and less from another), because we've set the 
 * max capacity from each time period to the sink to x. That's our hook.
 * We just have to do repeated Ford-Fulkersons to find the largest value of x which leads to success.  
 */
class guards
{
    public Scanner sc;
    public PrintStream ps;
    
    // Program was written with different periods-per-hour possible.
    // We settled on 2 periods per hour (by half-hours), but this code
    // could have handled other cases.
    public static final int PERIODS_PER_HOUR = 2;
    public static final int PERIODS_PER_DAY = 24*PERIODS_PER_HOUR;
    public static final int MINUTES_PER_PERIOD = 60/PERIODS_PER_HOUR;
    public static final int MINUTES_PER_DAY = 24*60;

    public String toString()
    {
        return "guards";
    }
    
    /**
     * A Node in the Max Flow graph
     */
    public class Node
    {
    	// A list of edges
    	public LinkedList<Edge> edges;
    	
    	// Whether or not this node has been visited by the current search
    	public boolean visited;
    	
    	// A name, for debugging purposes only.
    	public String name;
    	
    	/**
    	 * Create a node.
    	 * 
    	 * @param n The Name of the node
    	 */
    	public Node( String n )
    	{
    		name = n;
    		edges = new LinkedList<Edge>();
    		visited = false;
    	}
    	
    	/**
    	 * Standard toString() method, to help with debugging.
    	 * 
    	 * @return A pretty string version of the node (which is just the name).
    	 */
    	public String toString()
    	{
    		return name;
    	}
    }
    
    /**
     * An Edge in the Max Flow graph.
     */
    public class Edge
    {
    	// Each edge has a capacity,
    	public int cap;
    	
    	// A destination,
    	public Node dest;
    	
    	// And a "dual" edge
    	public Edge dual;
    	
    	/**
    	 * Create an edge.
    	 * 
    	 * @param d The destination of this edge.
    	 */
    	public Edge( Node d )
    	{
    		cap = 0;
    		dest = d;
    		dual = null;
    	}
    }
    
    /**
     * A State in the BFS.
     */
    public class State
    {
    	// The node where we are
    	public Node node;
    	
    	// The edge that got us here
    	public Edge edge;
    	
    	// A link to the previous state
    	public State prevstate;
    	
    	/**
    	 * Create a State.
    	 * 
    	 * @param n The Node
    	 * @param e The Edge that got us here
    	 * @param p The previous State
    	 */
    	public State( Node n, Edge e, State p )
    	{
    		node = n;
    		edge = e;
    		prevstate = p;
    	}
    }
    
    /**
     * Create a link (and its dual) between nodes A and B.
     * 
     * @param a Node A
     * @param b Node B
     * @param capacity Capacity from A to B (it'll be 0 from B to A)
     */
    public void link( Node a, Node b, int capacity )
    {
    	// Create the edge from A to B, and its dual from B to A.
        Edge a2b = new Edge( b );	
        Edge b2a = new Edge( a );
        
        // Add them to their respective Nodes
        a.edges.add( a2b );
        b.edges.add( b2a );
        
        // They are duals of each other
        a2b.dual = b2a;
        b2a.dual = a2b;
        
        // Set their capacities
        a2b.cap = capacity;
        b2a.cap = 0;
    }
    
    /**
     * Parse a string of the form HH:MM and return the number
     * of minutes represented.
     * 
     * @param time A String time, like 02:34
     * @return The number of minutes represented by the String time
     */
    public int getMinutes( String time )
    {
    	String tokens[] = time.split( ":" );
    	int h = Integer.parseInt( tokens[0] );
    	int m = Integer.parseInt( tokens[1] );
    	return h*60 + m;
    }
    
    /**
     * Convert minutes to periods
     * 
     * @param minutes Minutes
     * @return Periods
     */
    public int minutesToPeriods( int minutes )
    {
    	return minutes * PERIODS_PER_HOUR / 60;
    }
    
    // The nodes - source, sink, guards, time periods.
    public Node source, sink, guards[], periods[];
    
    // We'll reuse this same queue for all of our BFS's.
    public LinkedList<State> queue = new LinkedList<State>();
    
    /**
     * Can we make a schedule such that every time period is covered by x guards?
     * 
     * @param x A number of guards to check
     * @return true if we can cover every time period with x guards, otherwise false.
     */
    public boolean cando( int x )
    {
        // Start by resetting the system. First, source to guards
    	for( Edge e : source.edges )
    	{
    		// We never get rid of capacity, we just move it from the edge to its dual.
    		// So here, we'll just move it back.
    		e.cap = e.cap+e.dual.cap;
    		e.dual.cap = 0;
    	}
    	
    	// Now, guards to periods
    	for( Node g : guards )
    	{
    		for( Edge e : g.edges )
    		{
    			// Guards have 2 kinds of edges - those to time periods,
    			// and those back to the source that are duals of edges from
    			// the source to the guard. We only want to reset the ones to time
    			// periods - we already reset the duals back at the source.
    		    if( e.dest != source )
    		    {
    		    	e.cap = 1;
    		    	e.dual.cap = 0;
    		    }
    		}
    	}
    	
    	// Finally, periods to sink
    	for( Node p : periods )
    	{
    		for( Edge e : p.edges )
    		{
    			// Periods have 2 kinds of edges - to the sink, and duals
    			// back to the guards. here, we're only interested in those
    			// that go to the sink.
    			if( e.dest == sink )
    			{
    				e.cap = x;
    				e.dual.cap = 0;
    			}
    		}
    	}
    	
    	// Total capacity
    	int totalcap = 0;
    		
    	// Now, go through Ford-Fulkerson
    	for(;;)
    	{
    		// Mark all of the nodes as unvisited - this is a fresh BFS.
    		// Source is the exception, since we're marking nodes when we put them
    		// on the queue rather than when we're taking them off.
    		source.visited = true;
    		for( Node g : guards )
    		{
    			g.visited = false;
    		}
    		for( Node p : periods )
    		{
    		    p.visited = false;	
    		}
    		sink.visited = false;
    		
    		// Start the BFS. Clear the queue, add the source
    		queue.clear();
    		queue.add( new State( source, null, null ) );
    		
    		// We want to remember the final state we ended up in.
    		// That's so we can do the part of Ford-Fulkerson where
    		// we trace our route, find the smallest capacity along the route,
    		// and use that capacity along the route.
    		State finalstate = null;
    		
    		// And, off we go with a BFS.
    		while( queue.size()>0 )
    		{
    			// Grab the next state
    		    State s = queue.removeFirst();
    		    
    		    // Did we reach the sink? Then we're done
    		    if( s.node == sink )
    		    {
    		    	finalstate = s;
    		    	break;
    		    }
    		    
    		    // Otherwise, go through this node's edges
		    	for( Edge e : s.node.edges )
		    	{
		    		// Look for edges that have capacity>0, that go
		    		// to nodes we haven't visited yet
		    		if( e.cap>0 && !e.dest.visited )
		    		{
		    			// Mark'em, and queue'em
		    			e.dest.visited = true;
		    			queue.add( new State( e.dest, e, s ) );
		    		}
		    	}
    		}
    		
    		// If we never reached the sink, then we're done.
    		if( finalstate==null ) break;
    		
    		// Figure out how much capacity this route used.
    		// This is a "weakest link" thing - you can't push through any more
    		// capacity than the smallest pipe will allow. 
    		// So, we go back through all of the edges we used, to
    		// find the smallest capacity.
    		int capused = Integer.MAX_VALUE;
    		for( State s=finalstate; s.edge!=null; s=s.prevstate )
    		{
    			if( s.edge.cap<capused ) capused = s.edge.cap;
    		}
    		
    		// Total capacity is increased by the capacity used on this route
    		totalcap += capused;
    		
    		// Modify the edges - remove the capacity used from each
    		// edge in the route, and put it on that edge's dual
    		for( State s=finalstate; s.edge!=null; s=s.prevstate )
    		{
    			s.edge.cap -= capused;
    			s.edge.dual.cap += capused;
    		}
    	}
    	    	
    	// Did we manage to fill all periods with n guards?
    	return totalcap == x*PERIODS_PER_DAY;
    }
           
    /**
     * The main method
     * @throws Exception
     */
    public void doit() throws Exception
    {
        sc = new Scanner( System.in ); // new Scanner( new File( "guards.judge" ) );
        ps = System.out; // new PrintStream( new FileOutputStream( "guards.solution" ) );
        
        // Create everything we can a priori.
        // The number of guards will vary, but the source, sink and time periods won't.
        source = new Node( "source" );
        sink = new Node( "sink" );
        periods = new Node[PERIODS_PER_DAY];
        for( int i=0; i<periods.length; i++ )
        {
        	periods[i] = new Node( "period" + i );
        }
        
        // willwork[i] == Is the current guard willing to work this minute of the day?
        boolean willwork[] = new boolean[MINUTES_PER_DAY];
        
        for(;;)
        {
        	// Read the number of guards, exit if done.
        	int n = sc.nextInt();
        	if( n==0 ) break;
        	
        	// Create the guards array
        	guards = new Node[n];
        	
        	// Clear out the last graph - we're going to build a new one
        	source.edges.clear();
        	sink.edges.clear();
        	for( Node p : periods )
        	{
        	    p.edges.clear();
        	    
        	    // The capacity we use here doesn't really matter.
        	    // We'll reset it with every call to cando().
        	    link( p, sink, 1 );
        	}
        	
        	// Read in info on the guards
        	for( int i=0; i<n; i++ )
        	{
        		// Number of time windows, time limit.
	        	int m = sc.nextInt();
	        	int k = sc.nextInt();
	        	
	        	// Time limit is in minutes - convert it to periods.
	        	k = minutesToPeriods(k);
	        		        	
	        	// Figure out what minutes the guard is willing to work.
	        	Arrays.fill( willwork, false );	        	
	        	for( int j=0; j<m; j++ )
	        	{
	        		// Read start & stop times
	        		String t1 = sc.next();
	        		String t2 = sc.next();
	        		
	        		// Convert to minutes
	        		int start = getMinutes(t1);	        			        		
	        		int stop = getMinutes(t2);
	        		
	        		// Account for wrap around midnight
	        		if( stop<=start ) stop += MINUTES_PER_DAY;
	        			        		
	        		// Mark those minutes that the guard is willing to work.
	        		for( int minute=start; minute<stop; minute++ )
	        		{
	        			willwork[minute%MINUTES_PER_DAY] = true;
	        		}
	        	}
	        	
	        	// Create a node for this guard, link it to the source
	        	guards[i] = new Node( "guard" + i );
	        	link( source, guards[i], k );
	        	
	        	// Determine which time periods the guard is willing to work
	        	for( int period=0; period<periods.length; ++period )
	        	{
	        		// Guard is only willing to work a time period if s/he
	        		// is willing to work EVERY MINUTE of that time period
	        		boolean willworkperiod = true;
	        		for( int minute = period*MINUTES_PER_PERIOD; minute<(period+1)*MINUTES_PER_PERIOD; ++minute )
	        		{
	        		    if( !willwork[minute] )
	        		    {
	        		    	willworkperiod = false;
	        		    	break;
	        		    }
	        		}
	        		
	        		// If they're willing, create the link!
	        		if( willworkperiod )
	        		{
	        		    link( guards[i], periods[period], 1 );	
	        		}
	        	}
        	}
        	
        	// Now, it's just a Binary Search 
        	// to look for the breakpoint where
        	// cando(x) is true, but cando(x+1) is false.
        	int lo = 0; // Guaranteed that cando(0) is true.
        	int hi = n+1; // Since we have only n guards, guaranteed that cando(n+1) is false
        	while( lo<hi-1 )
        	{
        		int mid = (lo+hi)/2;
        		if( cando(mid) )
        		{
        		    lo = mid;
        		}
        		else
        		{
        		    hi = mid;	
        		}
        	}
        	
        	// The Binary Search will end with lo==hi-1,
        	// cando(lo)==true, cando(hi)==cando(lo+1)==false.
        	// So, lo is our answer.
        	ps.println( lo );
        }
    }

	public static void main(String[] args) throws Exception
	{
		long starttime = System.currentTimeMillis();
		new guards().doit();
		System.out.println( System.currentTimeMillis() - starttime );
	}
}
