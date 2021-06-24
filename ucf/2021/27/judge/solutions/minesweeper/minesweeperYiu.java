/*
ACM ICPC Southeast Regional Contest 2009

Minesweeper

Author: Yiu Yu Ho
*/

import java.io.*;
import java.util.*;

public class minesweeperYiu
{
	public Scanner in = new Scanner(System.in);
	public PrintStream out = System.out;

	public char[][] T;
	public int rn, cn;
	
	//8 directions
	public int[] dx = {-1,-1,-1, 0, 0, 1, 1, 1};
	public int[] dy = {-1, 0, 1,-1, 1,-1, 0, 1};

	public void main()
	{
		int i, j, k, cnt;
		int x, y;

		rn = in.nextInt();
		while(rn > 0)
		{
			cn = in.nextInt();
			
			//Read in grid
			T = new char[rn][];
			for(i=0;i<rn;++i)
			{
				T[i] = in.next().toCharArray();
			}

			for(i=0;i<rn;++i)
			for(j=0;j<cn;++j)
			if(T[i][j] == '.')
			{
				//Cell (i, j) is empty ('.'), now count the number of neighbors that are mines ('*')
				cnt = 0;
				for(k=0;k<dx.length;++k)
				{
					x = i+dx[k];
					y = j+dy[k];
					//Cell (x, y) is a neighbor of cell (i, j)
					if(valid(x, y) && T[x][y]=='*') ++cnt;
				}
				T[i][j] = (char)(cnt+'0');
			}

			for(i=0;i<rn;++i) out.println(new String(T[i]));

			rn = in.nextInt();
		}
	}
	
	//Check if a cell (x, y) is within the grid
	public boolean valid(int x, int y) { return 0<=x && x<rn && 0<=y && y<cn; }

	public static void main(String[] args)
	{
		long startTime = System.currentTimeMillis();
		(new minesweeperYiu()).main();
		long endTime = System.currentTimeMillis();

		System.err.println("Time = "+(endTime - startTime)+"(ms)");
	}
}
