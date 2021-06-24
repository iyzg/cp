import java.io.*;
import java.util.*;
import java.awt.*;
import java.text.*;
import java.math.*;

/**
 * Solution to Knitting
 */
class knitting
{
    public Scanner sc;
    public PrintStream ps;

    public String toString()
    {
        return "knitting";
    }
        
    /**
     * The main method
     */
    public void doit() throws Exception
    {
        sc = new Scanner( System.in ); // new Scanner( new File( "knitting.judge" ) );
        ps = System.out; // new PrintStream( new FileOutputStream( "knitting.solution" ) ); 
        
        for(;;)
        {
        	// Read n, m, k
        	int n = sc.nextInt();
        	int m = sc.nextInt();
        	int k = sc.nextInt();
        	
        	// Exit if at the end
        	if( n==0 && m==0 && k==0 ) break;
        	
        	// Read in an array of the differences
        	int diffs[] = new int[k];
        	for( int i=0; i<k; i++ )
        	{
        		diffs[i] = sc.nextInt();
        	}
        	
        	// The numbers are small enough that we don't need any fancy math.
        	// Just iterate through all of the rows of the project.
        	int total = 0;
        	int row = n;
        	for( int i=0; i<m; i++ )
        	{
        		// Add in this row
        		total += row;
        		
        		// Size of next row
        		row += diffs[i%k];
        	}
        	
        	// And, print the result.
        	ps.println( total );
        }
    }

	public static void main(String[] args) throws Exception
	{
		long starttime = System.currentTimeMillis();
		new knitting().doit();
		System.out.println( System.currentTimeMillis() - starttime );
	}
}
