import java.util.*;
import java.io.*;
public class mines_chinmay {
	public static void main(String[] args) throws Exception{
		int N, M;
		int d[][] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
		Scanner in = new Scanner(new File("mines.in"));
		PrintStream out = new PrintStream(new File("mines.out"));
		while((M = in.nextInt()) > 0)
		{
			
			N = in.nextInt();
			boolean mine[][] = new boolean[M][N];
			for(int j = 0; j < M; j++)
				{
				
					String temp = in.next();
					for(int i = 0; i < N; i++)
						mine[j][i] = temp.charAt(i)=='*'?true:false;
					
				}
			
			int table[][] = new int[M][N];
			for(int i = 0; i < M; i++) Arrays.fill(table[i], 0);
			for(int i = 0; i < M; i++)
				for(int j = 0; j < N; j++)
					if(mine[i][j])
				{
					for(int k = 0; k < 8; k++)
					{
						if(i+d[k][0] >= 0 && i+d[k][0] < M && j+d[k][1] >= 0 && j+d[k][1] < N)
							table[i+d[k][0]][j+d[k][1]]++;
					}
				}
			
			for(int i = 0; i < M; i++)
			{
				for(int j = 0; j < N; j++)
					out.print(mine[i][j]?"*":(""+table[i][j]));
				out.println();
			}
		}
	}

}
