import java.util.*;
import java.io.*;
public class euclid_chinmay {
	static double dist(double x1, double y1, double x2, double y2)
	{
		return Math.sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	}
	
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(new File("euclid.in"));
		PrintStream out = new PrintStream(new File("euclid.out"));
		
		double eps = 1.0e-9;
		
		
		while(true)
		{
			double ax = in.nextDouble();
			double ay = in.nextDouble();
			double bx = in.nextDouble();
			double by = in.nextDouble();
			double cx = in.nextDouble();
			double cy = in.nextDouble();
			double dx = in.nextDouble();
			double dy = in.nextDouble();
			double ex = in.nextDouble();
			double ey = in.nextDouble();
			double fx = in.nextDouble();
			double fy = in.nextDouble();
			
			double A = dist(dx, dy, ex, ey);
			double B = dist(ex,ey,fx,fy);
			double C = dist(fx,fy,dx,dy);
			
			double S = (A+B+C)/2;
			double area = Math.sqrt(S*(S-A)*(S-B)*(S-C));
			
			if(area < eps) break;
			
			double alpha = area/Math.abs((cx-ax)*(by-ay) - (cy-ay)*(bx-ax));
			
			double hx = alpha*(cx-ax) + ax;
			double hy = alpha*(cy-ay) + ay;
			
			double gx = hx+bx-ax;
			double gy = hy+by-ay;
			
			out.printf("%.3f %.3f %.3f %.3f\n", gx, gy, hx, hy);
			
		}
	}
}
	