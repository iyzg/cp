
import java.io.*;
import java.util.*;
import java.awt.*;
import java.text.*;
import java.math.*;

/**
 * Solution for The Ninja Way
 * 
 * This program will use a Greedy algorithm. First, it'll assume that the trees are
 * laid out right next to each other, as tightly as possible. Then, it'll find the 
 * positions of the smallest and largest trees - let's say s and t - and then try to 
 * stretch the gap between s and s+1 as far as possible, then the gap between s+1 and s+2, 
 * then s+2 and s+3, all the way up to t-1 and t. It will look at all pairs of trees that 
 * are adjacent height-wise (that the Ninjas would jump between) that span each of those gaps, 
 * to see how far the gaps can be stretched.
 * 
 * The only way the Greedy algorithm can fail is if stretching an early gap limits your
 * options of stretching a later gap. I'm not going to go through a convoluted argument,
 * but it's true. It's left as an exercise to the reader to confirm!
 */
class ninjaway
{
    public Scanner sc;
    public PrintStream ps;

    public String toString()
    {
        return "ninjaway";
    }
       
    /**
     * The main method
     */
    public void doit() throws Exception
    {
        sc = new Scanner( System.in ); // new Scanner( new File( "ninjaway.judge" ) );
        ps = System.out; // new PrintStream( new FileOutputStream( "ninjaway.solution" ) );
        
        for(;;)
        {
        	// Read in n & d, exit if at end
        	int n = sc.nextInt();
        	int d = sc.nextInt();
        	if( n==0 ) break;
        	
        	// The trees, in order of input
        	int trees[] = new int[n];
        	
        	// An array to sort the trees by height
        	int sorted[] = new int[n];
        	
        	// Read in the trees
        	for( int i=0; i<n; i++ )
        	{
        		trees[i] = sc.nextInt();
        		sorted[i] = trees[i];
        	}
        	Arrays.sort( sorted );
        	
        	// position[i] is the position, in the input order, of the ith shortest tree. 
        	// So, position[0] is the position of the shortest tree, and
        	// position[n-1] is the position of the tallest tree.
         	int position[] = new int[n];
         	for( int i=0; i<n; i++ )
        	{
        	    int p = Arrays.binarySearch( sorted, trees[i] );
        	    position[p] = i;
        	}
        	
         	// start and finish will be our limits - the positions of
         	// the shortest and tallest trees, with start<finish
        	int start = position[0];
        	int finish = position[n-1];
        	if( finish<start )
        	{
        		int t = start;
        		start = finish;
        		finish = t;
        	}
        	
        	// dist[i] is the distance between the ith shortest
        	// tree and the i+1st shortest tree. It's the distance
        	// the ninjas must jump to get from tree i to the next tree in height.
        	// We'll start with the assumption that the trees are packed 
        	// as tightly as possible. If this distance, under those conditions,
        	// is greater than D, then it's impossible to find a solution.
        	int dist[] = new int[n];
        	boolean failed = false;
        	for( int i=0; i<n-1; i++ )
        	{
        		dist[i] = Math.abs( position[i+1]-position[i] );
        		if( dist[i]>d ) failed=true;
        	}
        	
        	// This'll be our answer
        	int total;
        	
        	// if we failed, then the answer is -1
        	if( failed )
        	{
        	    total = -1;	
        	}
        	else
        	{      	
        		// OK, it gets a little confusing here. We're going to have two indexing schemes.
        		// i is going to represent height order (i==0 is the smallest tree), and
        		// j is going to represent order on the ground (j==0 is the first tree in the input)
        		// This will hold true throughout the rest of the code.
        		//
	        	// spans[i][j] is true if the space between trees i and i+1 spans gap j.
        		// That is, if the space between trees i and i+1 (in height order) crosses
        		// the gap between trees j and j+1 (on the ground), then span[i][j] is true.
	        	boolean spans[][] = new boolean[n][n];
	        	for( int i=0; i<n; i++ )
	        	{
	        	    Arrays.fill( spans[i], false );	
	        	}
	        	for( int i=0; i<n-1; i++ )
	        	{
	        		int lo = Math.min( position[i], position[i+1] );
	        		int hi = Math.max( position[i], position[i+1] );
	        		for( int j=lo; j<hi; j++ )
	        		{
	        			spans[i][j] = true;
	        		}
	        	}
	        	
	        	// At first, before stretching any gaps, this is the distance.
	        	total = finish-start;
	        	
	        	// Now, we'll go through all of the gaps between the start and the finish,
	        	// and stretch them as far as we can.
	        	for( int j=start; j<finish; j++ )
	        	{
	        		// Find the biggest distance of all (i,i+1) pairs
	        		// that cross this gap. That's a limiting condition. If
	        		// we stretch this gap too much, that distance is in danger of
	        		// getting to be >D.
	        	    int maxdist = 0;
	        	    for( int i=0; i<n-1; i++ ) if( spans[i][j] )
	        	    {
	        	    	if( dist[i]>maxdist )
	        	    	{
	        	    		maxdist=dist[i];
	        	    	}
	        	    }
	        	    
	        	    // The best we can do is to stretch that biggest
	        	    // gap to be D.
	        	    int stretch = d-maxdist;
	        	    
	        	    // Add in the amount of this stretch
	        	    total += stretch;
	        	    
	        	    // OK, stretch that gap! That means stretching ALL of
	        	    // the (i,i+1) pairs that span the gap!
	        	    for( int i=0; i<n-1; i++ ) if( spans[i][j] )
	        	    {
	        	    	dist[i] += stretch;
	        	    }
	        	}
        	}
        	
        	// That's it! Now, just print the total.
        	ps.println( total );
        }
    }

	public static void main(String[] args) throws Exception
	{
    	long starttime = System.currentTimeMillis();
        new ninjaway().doit();
        System.out.println( System.currentTimeMillis() - starttime );
	}
}
