// euclid.cpp : Defines the entry point for the console application.
// Tom Hain, Sept 8, 2009
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

void main()
{
	for (double ax,ay,bx,by,cx,cy,dx,dy,ex,ey,fx,fy; cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy>>ex>>ey>>fx>>fy, ax!=0||ay!=0||bx!=0||by!=0||cx!=0||cy!=0||dx!=0||dy!=0||ex!=0||ey!=0||fx!=0||fy!=0; )
	{
		double	parallelogramArea = (by-ay)*(cx-ax) - (bx-ax)*(cy-ay), // z-component of cross product
				triangleArea = ((ex-dx)*(ey+dy) + (fx-ex)*(fy+ey) + (dx-fx)*(dy+fy))/2,
				u = abs(triangleArea/parallelogramArea);
		cout	<< fixed << setprecision(3) 
				<< bx + u*(cx-ax) << ' ' << by + u*(cy-ay) << ' '
				<< ax + u*(cx-ax) << ' ' << ay + u*(cy-ay) << endl;
	}
}

