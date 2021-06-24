import java.io.*;
import java.util.*;
import java.awt.*;
import java.text.*;
import java.math.*;

/**
 * Solution to Block Game. 
 * 
 * It's just a Breadth-First Search, keeping track of previously seen states.
 */
class blockgame
{
    public Scanner sc;
    public PrintStream ps;

    public String toString()
    {
        return "blockgame";
    }
    
    // The change in i and j for each of the four directions.
    // d=0 is up, d=1 is right, d=2 is down, d=3 is left.
    public static final int di[] = { -1, 0, 1, 0 };
    public static final int dj[] = { 0, 1, 0, -1 };
    
    // The (fixed) board size.
    public int n=6, m=6;
      
    /**
     * This is a State in the Breadth-First Search. 
     * A State consists of the current configuration of the board, and the move number.
     */
    public class State
    {
    	// The board
    	public char board[][];
    	
    	// The move number
    	public int move;
    	
    	/**
    	 * Build a state.
    	 * 
    	 * @param b The Board
    	 * @param mm The Move Number
    	 */
    	public State( char b[][], int mm )
    	{
    		// Remember move number
    		move = mm;
    		
    		// Build a new board
    		board = new char[n][];
    		for( int i=0; i<b.length; i++ )
    		{
    			board[i] = Arrays.copyOf( b[i], b[i].length );
    		}
    	}
    	
    	/**
    	 * Retrieve the Board from a State.
    	 * 
    	 * @return This State's Board
    	 */
    	public char[][] getBoard()
    	{
    		return board;
    	}
    	
    	/**
    	 * Build a unique ID for this state.
    	 * This is going to be used to check for repeated states.
    	 * 
    	 * @return A unique ID for this state.
    	 */
    	public String getID()
    	{
    		StringBuffer buffer = new StringBuffer(100);
    		for( int i=0; i<board.length; i++ )
    		{
    		    buffer.append( board[i] );	
    		}
    		
    		return buffer.toString();
    	}
    }
    
    /**
     * Determine if (i,j) is on a board.
     * 
     * @param b A Board
     * @param i Row
     * @param j Column
     * @return true if Row i, Column j is on the board, otherwise false.
     */
    public boolean onboard( char b[][], int i, int j )
    {
    	return i>=0 && j>=0 && i<b.length && j<b[i].length;
    }
    
    /**
     * Determine if the piece at (i,j) can move in direction d.
     * 
     * @param b A Board
     * @param i Row
     * @param j Column
     * @param d Direction
     * @return true if the if the piece at (i,j) can move in direction d, otherwise false.
     */
    public boolean canmove( char b[][], int i, int j, int d )
    {
    	// 'up' is in direction d
    	int upi = i+di[d];
    	int upj = j+dj[d];
    	
    	// 'down' is in the direction opposite d
    	int dni = i-di[d];
    	int dnj = j-dj[d];
    	
    	// We can move if both 'up' and 'down' cells are on the board,
    	// if the 'up' cell is empty, and the 'down' cell belongs
    	// to the same piece as cell (i,j).
    	// Like this:
    	//
    	// .
    	// A
    	// A
    	return onboard( b, upi, upj ) && onboard( b, dni, dnj ) 
    	    && b[upi][upj]=='.' && b[dni][dnj]==b[i][j]; 
    }
            	
    /**
     * This is the main method. 
     * @throws Exception
     */
    public void doit() throws Exception
    {
        sc = new Scanner( System.in ); // new Scanner( new File( "blockgame.judge" ) );
        ps = System.out; // new PrintStream( new FileOutputStream( "blockgame.solution" ) ); 
        
        for(;;)
        {
        	// Read in the char of the special piece, exit if it's '*'
        	char ch = sc.next().charAt(0);
        	if( ch=='*' ) break;
        	
        	// Read in the board
        	char board[][] = new char[n][];
        	for( int i=0; i<n; i++ )
        	{
        		board[i] = sc.next().toCharArray();
        	}
        	
        	// Queue for BFS
        	LinkedList<State> queue = new LinkedList<State>();
        	
        	// This will record states we've seen
        	HashSet<String> seen = new HashSet<String>();
        	
        	// Put the first state on the queue, 
        	// and say that we've seen it
        	State state = new State( board, 0 );
        	queue.add( state );
        	seen.add( state.getID() );
        	
        	// This will hold the final answer
        	int solution = -1;
        	
        	// Keep going until the queue is empty,
        	// or until a solution is found
        	while( queue.size()>0 && solution<0 )
        	{
        		// Get the state at the top of the queue,
        		// and get its board
        	    state = queue.removeFirst();        		
        		char b[][] = state.getBoard();
        		
        		// Look to see if the special piece has
        		// been moved to the last row. If so, it can be
        		// moved off, and the board is solved.
        		for( int i=0; i<n; i++ )
        		{
        		    if( b[i][m-1]==ch )
        		    {
        		    	solution = state.move;
        		    	break;
        		    }
        		}
        		
        		// Go through the entire board, looking for pieces to move
        		for( int i=0; i<b.length; i++ ) for( int j=0; j<b[i].length; j++ ) if( b[i][j]!='.')
        		{
        			// Try all four directions
        			for( int d=0; d<4; d++ )
        			{
        				// If this piece can move in this direction...
        				if( canmove( b, i, j, d ) )
        				{
        					// i,j is where the piece is now
        					// ii, jj is where the piece will be as it moves
        					int ii = i;
        					int jj = j;
        					
        					// Make a copy of the board
        					char newb[][] = new char[n][m];
        					for( int k=0; k<n; k++ )
        					{
        						newb[k] = Arrays.copyOf( b[k], m );
        					}
        					
        					// Check to see if its of size 2 or 3
        					// (Actually, for 2, size=1, and for 3, size=2)
        					int i3 = i-2*di[d];
        					int j3 = j-2*dj[d];
        					int size = onboard( newb, i3, j3 ) && newb[i3][j3]==newb[ii][jj] ? 2 : 1;
        					
        					// While the piece can still move...
        					while( canmove( newb, ii, jj, d ) )
        					{
        						// Make the move
        						newb[ii+di[d]][jj+dj[d]] = newb[ii][jj];
        						newb[ii-size*di[d]][jj-size*dj[d]] = '.';
        						
        						// Build a new state
        						State newstate = new State( newb, state.move+1 );
        						String newid = newstate.getID();
        						
        						// If it hasn't been seen yet, add it to the queue
        						// put it in the 'seen' set.
        						if( !seen.contains( newid ) )
        						{
        							queue.add( newstate );
        							seen.add( newid );
        						}
        						
        						// Iterate, try again
        						ii += di[d];
        						jj += dj[d];
        					}
        				}
        			}
        		}        		
        	}  
        	
        	// Now here's a special case: what about this input?
        	//
        	// A
        	// ....AA
        	// ......
        	// ......
        	// ......
        	// ......
        	// ......
        	//
        	// The algorithm will return 0 - it takes no moves to get the 
        	// special piece to the edge of the board. But, it takes 1 move 
        	// to get it OFF the board!
        	ps.println( solution==0 ? 1 : solution );
        }
    }

	public static void main(String[] args) throws Exception
	{
		long starttime = System.currentTimeMillis();
		new blockgame().doit();
		System.out.println( System.currentTimeMillis() - starttime );
	}
}
