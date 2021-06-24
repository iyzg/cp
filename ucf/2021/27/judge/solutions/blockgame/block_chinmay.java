import java.util.*;
import java.io.*;

class Tokens
{
	char[][] config;
	int r, c, dir, size, before, after;
	Tokens(String s)
	{
		config = new char[6][];
		for(int i = 0; i < 6; i++) config[i] = s.substring(6*i, 6*(i+1)).toCharArray();
		r = 0;
		c = -1;
		dir = -1;
		size = -1;
		before = -1;
		after = -1;
	}

	void getNext()
	{
		c++;
		if(c == 6)
		{
			c=0;
			r++;
		}
		outer: for(; r<6; r++,c=0)
			for(; c < 6; c++)
			{
				if(Character.isLetter(config[r][c]))
				{
					if((r == 0 || config[r-1][c] != config[r][c]) && (c == 0 || config[r][c-1] != config[r][c]))
					{
						//System.out.println(r + " " + c);
						if(c < 5 && config[r][c+1] == config[r][c])
						{
							dir = 0;
							if(c < 4 && config[r][c+2] == config[r][c])
							{
								size = 3;
							}
							else
							{
								size = 2;
							}
							int k = c+size;
							after = 0;
							while(k < 6 && config[r][k]=='.')
							{
								after++;
								k++;
							}
							k = c-1;
							before = 0;
							while(k>=0 && config[r][k]=='.')
							{
								before++;
								k--;
							}
						}
						else if(r < 5 && config[r+1][c] == config[r][c])
						{
							dir = 1;
							if(r < 4 && config[r+2][c] == config[r][c])
							{
								size = 3;
							}
							else size = 2;
							int k = r+size;
							after = 0;
							while(k < 6 && config[k][c] == '.')
							{
								after++;
								k++;
							}
							k = r-1;
							before = 0;
							while(k>=0 && config[k][c]=='.')
							{
								before++;
								k--;
							}
						}
						//System.out.println(size + " " + before + " " + after);
						break outer;
					}
				}
			}
	}

	public String toString()
	{
		String out = "";
		for(int i = 0; i < 6; i++)
		{
			for(int j = 0; j < 6; j++)
				out += config[i][j];
			out+= "\n";
			
		}
		out += "\n";
		return out;
	}
	
	String move(int steps)
	{
		if(dir == 0)
		{
			String out = "";
			for(int i = 0; i < 6; i++)
				for(int j = 0; j < 6; j++)
				{
					if(i != r || j < c || j >= c+size+steps) out += config[i][j];
					else if(j < c+steps) out += '.';
					else out += config[r][c];
				}
			return out;
		}
		else
		{
			String out = "";
			for(int i = 0; i < 6; i++)
				for(int j = 0; j < 6; j++)
				{
					if(j != c || i < r || i >= r+size+steps) out += config[i][j];
					else if(i < r+steps) out += '.';
					else out += config[r][c];
				}
			return out;
			
		}
	}
	String moveback(int steps)
	{
		if(dir == 0)
		{
			String out = "";
			for(int i = 0; i < 6; i++)
				for(int j = 0; j < 6; j++)
				{
					if(i != r || j < c-steps || j >= c+size) out += config[i][j];
					else if(j >= c+size-steps) out += '.';
					else out += config[r][c];
				}
			return out;
		}
		else
		{
			String out = "";
			for(int i = 0; i < 6; i++)
				for(int j = 0; j < 6; j++)
				{
					if(j != c || i < r-steps || i >= r+size) out += config[i][j];
					else if(i >= r+size-steps) out += '.';
					else out += config[r][c];
				}
			return out;
			
		}
	}
}

public class block_chinmay {
	public static void main(String[] args) throws Exception{
		char C;
		int Crow;
		Scanner in = new Scanner(new File("blockgame.judge"));
		PrintStream out = new PrintStream(new File("block.out"));
		outer: while((C = in.next().charAt(0)) != '*')
		{
			Crow = -1;
			HashMap<String,Integer> seen = new HashMap<String,Integer>();
			LinkedList<String> q = new LinkedList<String>();
			String config = "";
			for(int i = 0; i < 6; i++) 
				{
					config += in.next();
					if(Crow < 0 && config.indexOf("" + C) >= 0) Crow = i;
				}

			
			q.add(config);
			seen.put(config, 0);

			while(!q.isEmpty())
			{
				String temp = q.pop();
				Tokens t = new Tokens(temp);
				//System.out.println(seen.get(temp) + "\n" + t + "");
				if(t.config[Crow][4] == C && t.config[Crow][5] == C)
				{
					out.println(seen.get(temp)==0?1:seen.get(temp));
					continue outer;
				}
				while(t.r < 6)
				{
					t.getNext();
					if(t.r >= 6) break;
					
					for(int s = t.after; s >= 1; s--)
					{
						String te = t.move(s);
						//System.out.println((new Tokens(te))+"");
						if(!seen.containsKey(te))
						{
							seen.put(te, seen.get(temp)+1);
							q.add(te);
						}
					}
					for(int s = 1; s <= t.before; s++)
					{
						String te = t.moveback(s);
						//System.out.println((new Tokens(te))+"");
						if(!seen.containsKey(te))
						{
							seen.put(te, seen.get(temp)+1);
							q.add(te);
						}						
					}
				}
			}
			out.println(-1);

		}
	}
}