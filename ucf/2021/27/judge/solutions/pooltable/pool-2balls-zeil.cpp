/**
 * Sample solution for Pool Table
 *   Steven J Zeil, 9/19/2009
 */
#include <cmath>
#include <limits>
#include <iomanip>
#include <iostream>
#include <fstream>


using namespace std;


struct Point {
  int x;
  int y;

  Point (int xx = 0, int yy = 0)
    : x(xx), y(yy)
  {}
};


struct Line {
  Point p1;
  Point p2;

  Line() {}

  Line (Point thruPoint1, Point thruPoint2);
  
  double y(int x) const;
  double x(int y) const;

  bool strictlyContains (const Point& p) const;


};

Line::Line (Point thruPoint1, Point thruPoint2)
  : p1(thruPoint1), p2(thruPoint2)
{}

double Line::y (int x) const
{
  if (p1.x == p2.x)
    return numeric_limits<double>::max();
  else
    return (double)p1.y + ((double)(p2.y - p1.y) / (p2.x - p1.x)) * (x - p1.x);
} 

double Line::x (int y) const
{
  if (p1.y == p2.y)
    return numeric_limits<double>::max();
  else
    return  (double)p1.x + ( (double)(p2.x - p1.x) / (p2.y - p1.y)) * (y - p1.y);
} 


bool Line::strictlyContains (const Point& p) const
{
  if ((p.y - p1.y) * (p2.x - p1.x) == (p.x - p1.x) * (p2.y - p1.y))
    {
      // p is on the line. Is it between (and not on) the endpoints?
      return ((p.x - p1.x)*(p.x - p2.x) < 0) || ((p.y - p1.y)*(p.y - p2.y) < 0);
    }
  else
    return false;
}



  /*
   * Picture an infinite tiling of pool tables, with the (0,0) table
   * containing the first ball and all tables containing a copy of
   * the second ball. The trick is that the table tiles are formed by
   * REFLECTING an adjacent table along an x or y edge. (Two horizontal
   * or two vertical reflections, of course, cancel one another).
   * 
   * Any n-bank solution to the one-table problem can be modelled, in this
   * tiling, as a straight line from the first ball to the copy of a second
   * ball in some table n steps away from this one.
   */

// Compute the coordinates of a point p as reflected in the
// table (tableX,tableY) tiles away
Point reflectionInTableTile (int tableX, int tableY,
			     int w, int h, Point p)
{
  int x3 = tableX * w;
  if (tableX >= 0)
    {
      if (tableX % 2 == 0)
	x3 += p.x;
      else
	x3 += (w - p.x);
    }
  else
    {
      if (tableX % 2 == 0)
	x3 += p.x;
      else
	x3 += (w - p.x);
    }

  int y3 = tableY * h;
  if (tableY >= 0)
    {
      if (tableY % 2 == 0)
	y3 += p.y;
      else
	y3 += (h - p.y);
    }
  else
    {
      if (tableY % 2 == 0)
	y3 += p.y;
      else
	y3 += (h - p.y);
    }
  return Point(x3, y3);
}


int iabs (int x)
{
  return (x < 0) ? -x : x;
}



// Determine if a ball travelling from p1 to p3 would
// strike an "earlier" reflection of p2 (meaning that,
// on a real table, the 1st ball would strike the 2nd before
// completing the full set of bounces).
bool strikesEarly (Point p1, Point p2, Point p3, 
		   int tableX, int tableY, int w, int h)
{
  Line line13 (p1, p3);
  if (iabs(tableX) > iabs(tableY))
    {
      int dx = (tableX > 0) ? w : -w;
      for (int i = 0; i <= iabs(tableX); ++i)
	{
	  int x = p1.x + i*dx;
	  int tx = (tableX > 0) ? i : -i;
	  double y = line13.y(x);
	  int ty0 = (y - p1.y) / h;
	  for (int ty = ty0-1; ty <= ty0+1; ++ty)
	    { 
	      Point p2Reflected = reflectionInTableTile(tx, ty, w, h, p2);
	      if (line13.strictlyContains (p2Reflected))
		return true;
	    }
	}
      return false;
    }
  else
    {
      int dy = (tableY > 0) ? h : -h;
      for (int i = 0; i <= iabs(tableY); ++i)
	{
	  int y = p1.y + i*dy;
	  int ty = (tableY > 0) ? i : -i;
	  double x = line13.x(y);
	  int tx0 = (x - p1.x) / w;
	  for (int tx = tx0-1; tx <= tx0+1; ++tx)
	    { 
	      Point p2Reflected = reflectionInTableTile(tx, ty, w, h, p2);
	      if (line13.strictlyContains (p2Reflected))
		return true;
	    }
	}
      return false;
    }
}

double dist (Point p1, Point p2) 
{
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;

  return sqrt (dx * dx + dy * dy);
}





void solve (int w, int h, Point p1,  Point p2, int n)
{
  double minDist = -1.0;
  for (int tableX = -n; tableX <= n; ++tableX)
    {
      for (int d = -1; d <= 1; d +=2)
	{
	  int tableY = d * (n - iabs(tableX)); 
	  Point p3 = reflectionInTableTile(tableX, tableY, 
					   w, h, p2);
	  double d = dist (p1, p3);
	  if (minDist < 0.0 || d < minDist)
	    {
	      if (!strikesEarly (p1, p2, p3, tableX, tableY, w, h))
		{
		  //cerr << tableX << " " << tableY << " " << d << endl;
		  minDist = d;
		}
	    }
	}
    }
  if (minDist >= 0.0)
    cout << fixed << setprecision(3) << minDist << endl;
  else
    cout << "Not possible" << endl;
}




void poolTable (istream& in)
{
  int w, h;
  in >> w >> h;
  while (w > 0 && h > 0)
    {
      int x1, y1, x2, y2, n;
      in >> x1 >> y1 >> x2 >> y2 >> n;
      solve (w, h, Point(x1, y1), Point(x2, y2), n);
      in >> w >> h;
    }
}



int main (int argc, char** argv)
{
  // Program should normally read from standard in. But
  // for debugging purposes, it is sometimes easier to
  // give a file name on the command line.
  if (argc > 1)
    {
      ifstream in (argv[1]);
      poolTable (in);
    }
  else
    poolTable(cin);

  return 0;
}

