import java.util.*;
import java.io.*;
import java.awt.*;

/**
 * Solution to Mosaic
 * 
 * The key to understanding this solution is to see a column of the mosaic
 * as a bitmap - with the bit set (=1) if there's a tile there, and unset (=0) if not.
 * Since there are at most 10 rows, that gives us 1023 possible bitmaps, which is
 * manageable. 
 * 
 * We're going to try to build a Mosaic, column by column. Since the pieces are 2x2,
 * we can't fill a column without leaving some residue in the next column. So, we're going
 * to need to figure out, for any bitmap j representing a residue from the last column, 
 * how many ways can we fill this column and leave a residue of bitmap k in the next column?
 * 
 * Here's an interesting thing - that number depends only on the number of rows. So, we can compute all
 * of that a priori, before we ever start reading the data, rather than doing it over and over 
 * for each data set.
 * 
 * Once we've got that figured out, then for each input, we need to fill the columns so
 * that we start with a bitmap of 0 (on the edge, no residue), go through m columns, and
 * end up with a bitmap of 0 (no residue - nothing hanging off the edge of the mosaic)
 */
public class mosaic 
{
    public Scanner sc;
    public PrintStream ps;
     
    public String toString()
    {
    	return "mosaic";
    }
    
    // step[i][k][k] is the number of ways, with i rows, of getting from bitmap j to bitmap k.
    public int step[][][] = new int[11][][];
    
    // lists[i][j] holds the same info as step[i][j][k]. But, since the step[][][] array
    // is sparse, it's more efficient to represent a row (step[i][j]) as a linked list,
    // where k is omitted if step[i][j][k]==0.
    public LinkedList<Point> lists[][] = new LinkedList[11][];
    
    // This is a global used by the fill() routine.
    // It holds the base value of j before we start trying to fill the column.
    public int base;
      
    /**
     * Figure out how many ways there are to fill a column, 
     * and the effect that has on the next column. Do it row by row.
     * 
     * @param i Total number of rows
     * @param j Bitmap so far on this column
     * @param k Bitmap so far on the next column
     * @param level Rows so far that we know are filled.
     */
    public void fill( int i, int j, int k, int level )
    {
    	// We've filled the whole column
    	if( level>=i )
    	{
    		// If we haven't gone over, record that
    		// we've found one more way of getting from base to k.
    		if( level==i && k<(1<<i) ) ++step[i][base][k];
    	}
    	else
    	{
    		// Bits that are 1, 2, and 3 spots ahead
    		int b1 = 1<<level;
    		int b2 = b1<<1;
    		int b3 = b2<<1;
    		
    		// Test those bits
    		boolean t1 = (j & b1) > 0;
    		boolean t2 = (j & b2) > 0;
    		boolean t3 = (j & b3) > 0;
    		
    		if( !t1 && !t2 && !t3 )
    		{
    			// Turn this: Into this:
    			//    ..         AA
    			//    ..         BA
    			//    ..         BB
     		    fill( i, j|b3|b2|b1, k|b3|b1|b2, level+3 );  
     		    
    			// Turn this: Into this:
    			//    ..         AA
    			//    ..         AB
    			//    ..         BB
     		    fill( i, j|b3|b2|b1, k|b3|b1|b2, level+3 );    			
    		}
    		
    		if( !t1 && !t2 )
    		{
    			// We've got this:
    			// ..
    			// ..
    			
    			// Try:
    			// XX
    			// XX
     		    fill( i, j|b2|b1, k|b1|b2, level+2 );
     		    
     		    // Try:
     		    // X.
     		    // XX
     		    fill( i, j|b1|b2, k|b1, level+2 );
     		    
     		    // Try: 
     		    // XX
     		    // X.
     		    fill( i, j|b1|b2, k|b2, level+2 );
    		}
    		else if( t1 && !t2 )
    		{
    			// We've got this:
    			// ..
    			// #.
    			
    			// Try:
    			// XX
    			// #X
    			fill( i, j|b2, k|b1|b2, level+2 );
    			
    			// Try doing nothing
    			fill( i, j, k, level+1 );
    		}
    		else if( !t1 && t2 )
    		{
    			// We've got this:
    			// #.
    			// ..
    			
    			// Try:
    			// #X
    			// XX
    			fill( i, j|b1, k|b1|b2, level+2 );
    		}
    		else if( t1 && t2 )
    		{
    			// All filled - move on
    			fill( i, j, k, level+1 );
    		}
    	}
    }
    
    /**
     * The main method.
     * @throws Exception
     */
    public void doit() throws Exception
    {
    	sc = new Scanner( System.in ); // new Scanner( new File( "mosaic.judge" ) );
    	ps = System.out; // new PrintStream( new FileOutputStream( "mosaic.solution" ) );
    	
    	// Compute steps[][][] and lists[][] a priori
    	for( int i=2; i<=10; i++ )
    	{
    		// p = 2^i
    		int p = 1<<i;
    		
    		// Create a pxp matrix 
    	    step[i] = new int[p][p];
    	    for( int j=0; j<p; j++ )
    	    {
    	    	Arrays.fill( step[i][j], 0 );
    	    }
    	    
    	    // Also create an array of linked lists
    	    lists[i] = new LinkedList[p];
    	    
    	    // Go through all possible bitmaps
    	    for( int j=0; j<p; j++ )
    	    {
    	    	// fill() will modify its second parameter - so, 
    	    	// we need to make the base bitmap available.
    	    	base = j;
    	    	
    	    	// Fill the step[i][j][] row - figure out
    	    	// all the bitmaps you can get to from j when
    	    	// there are i rows.
    	    	fill( i, j, 0, 0 );
    	    	
    	    	// The matrix will be sparse - so, turn it into a linked list.
    	    	lists[i][j] = new LinkedList<Point>();
    	    	for( int k=0; k<p; k++ ) if( step[i][j][k]>0 )
    	    	{
    	    		// Represent as a point, where x = k, and y = # of ways
    	    		// of getting from j to k.
    	    		lists[i][j].add( new Point( k, step[i][j][k]) );
    	    	}
    	    }
    	}
    	
    	for(;;)
    	{
    		// Read in n & m, exit if done
    		int n = sc.nextInt();
    		int m = sc.nextInt();
            if( n==0 && m==0 ) break;
            
            // p = 2^n, the number of possible bitmaps
            int p = 1<<n;
            
            // current[j] is the number of ways of achieving bitmap j
            // on the current column
            int current[] = new int[p];
            
            // next[k] is the number of ways of achieving bitmap k
            // on the next column
            int next[] = new int[p];
            
            // We'll start at the very beginning (a very good place to start)
            // with one bitmap of 0, and no others.
            Arrays.fill( next, 0 );
            next[0] = 1;
            
            // Go through all of the columns
            for( int i=0; i<m; i++ )
            {
            	// Swap current and next - last iterations' next[]
            	// is this iteration's current[]
            	int temp[] = current;
            	current = next;
            	next = temp;
            	
            	// Start afresh
            	Arrays.fill( next, 0 );
            	
            	// Go through all possible bitmaps, and use the
            	// linked lists to see what bitmaps we can go to next
            	for( int j=0; j<p; j++ ) if( current[j]>0 ) for( Point q : lists[n][j] )
            	{
            		// Remember how we build that point: q.x is k, and q.y is the number of ways
            		// to get from j to k.
            		//
            		// If there are current[j] ways of getting to bitmap j on the current column,
            		// and q.y ways of getting from there to bitmap q.x, then we've
            		// just found current[j]*q.y more ways of getting to bitmap q.x
            		// on the next column. So, add them in.
            	    next[q.x] += current[j] * q.y;
            	    
            	    // Mod to keep the numbers manageable.
            	    next[q.x] %= 1000000;
            	}
            }
            
            // We're done! How many ways were there of achieving bitmap 0
            // on the last iteration - that is, we nicely filled in the mosaic with
            // nothing hanging over?
            ps.println( next[0] );
            
    	}
    }
    
    public static void main( String args[] ) throws Exception
    {
    	long starttime = System.currentTimeMillis();
        new mosaic().doit();
        System.out.println( System.currentTimeMillis() - starttime );
    	
        /*
    	Random random = new Random();
    	for( int i=0; i<25; i++ )
    	{
    	    System.out.println( (random.nextInt(9)+2) + " " + (random.nextInt(501)+1));	
    	}
    	*/
    }
}
