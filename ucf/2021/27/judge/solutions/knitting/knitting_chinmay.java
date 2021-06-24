import java.util.*;
import java.io.*;
public class knitting_chinmay {
	public static void main(String[] args) throws Exception{
		int N, M, K;
		Scanner in = new Scanner(new File("knitting.in"));
		PrintStream out = new PrintStream(new File("knitting.out"));
		while((N = in.nextInt()) > 0)
		{
			M = in.nextInt();
			K = in.nextInt();
			int ar[] = new int[K];
			for(int i = 0; i < K; i++) ar[i] = in.nextInt();
			
			int k = 0;
			
			int count = N;
			for(int i = 1; i < M; i++)
			{
				N += ar[k];
				k = (k+1)%K;
				count += N;
			}
			out.println(count);
		}
		out.close();
	}
}
