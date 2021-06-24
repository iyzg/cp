
import java.io.*;
import java.util.*;
import java.awt.*;
import java.text.*;
import java.math.*;

/**
 * Solution to Minesweeper
 */
class minesweeper
{
    public Scanner sc;
    public PrintStream ps;

    public String toString()
    {
        return "minesweeper";
    }
         
    /**
     * The main method
     * 
     * @throws Exception
     */
    public void doit() throws Exception
    {
        sc = new Scanner( System.in ); // new Scanner( new File( "minesweeper.judge" ) );
        ps = System.out; // new PrintStream( new FileOutputStream( "minesweeper.solution" ) ); 
        
        for(;;)
        {
        	// Read in rows, columns
        	int r = sc.nextInt();
        	int c = sc.nextInt();
        	
        	// Exit if at end
        	if( r==0 && c==0 ) break;
        	
        	// Read in the board
        	char board[][] = new char[r][];
        	for( int i=0; i<r; i++ )
        	{
        	    board[i] = sc.next().toCharArray();	
        	}
        	
        	// Go through the whole board, looking
        	// for empty spaces ('.')
        	for( int i=0; i<r; i++ ) for( int j=0; j<c; j++ ) if( board[i][j]=='.' )
        	{
        		// Count the number of adjacent mines
        		int count = 0;
        		for( int ii=i-1; ii<=i+1; ii++ ) for( int jj=j-1; jj<=j+1; jj++ )
        		{
        			// Be careful not to go off of the edge of the board!
        			if( ii>=0 && ii<r && jj>=0 && jj<c && board[ii][jj]=='*' )
        			{
        				++count;
        			}
        		}
        		
        		// Replace the '.' with the appropriate digit
        		board[i][j] = (char)('0'+count);
        	}
        	
        	// When done, print the board.
        	for( int i=0; i<r; i++ )
        	{
        		ps.println( new String( board[i] ) );
        	}
        }
    }

	public static void main(String[] args) throws Exception
	{
		long starttime = System.currentTimeMillis();
		new minesweeper().doit();
		System.out.println( System.currentTimeMillis() - starttime );
	}
}
