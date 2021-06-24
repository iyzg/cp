/*
    Sample solution for The Ninja Way 
    Steven J Zeil
 */


#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <map>
#include <limits>
#include <list>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


struct Tree {
  int followingGap;  // number of spaces to next tree
  int height;
};

ostream& operator<< (ostream& out, const Tree& t)
{
  out << "(" << t.followingGap << "," << t.height << ")";
  return out;
}


int d;
int nTrees;
int shortestTreeOrd;
int tallestTreeOrd;

Tree* trees;

bool compareIndirectByHeight (int i, int j)
{
  return trees[i].height < trees[j].height;
}

/**
 * A constraint of the form
 *   a0 * d0 + a1 * d1 + ... + a[n-2]*d[n-2] <= c
 *   where the a[i] are either 0 or 1, d[i] is trees[i].followingGap,
 *   and c is a non-negative constant
 */
struct Constraint {
  bool* nonZeroVariables;
  int c;

  void addVariable (int treeOrdinal);
  bool containsVariable (int treeOrdinal) const;
  
  /**
   * "Slack" in a constraint is the difference obtained by
   *  subtracting the left-handside of the inequality from the
   *  right-hand side.
   */
  int slack() const;

  Constraint();
  ~Constraint();
};

ostream& operator<< (ostream& out, const Constraint& t)
{
  out << "[";
  for (int i = 0; i < nTrees; ++i)
    if (t.nonZeroVariables[i])
      out << i << ' ';
  out << " <= " << t.c << "]";
  return out;
}

Constraint::Constraint()
{
  nonZeroVariables = new bool[nTrees];
  fill (nonZeroVariables, nonZeroVariables+nTrees, false);
}

Constraint::~Constraint()
{
  delete [] nonZeroVariables;
}


void Constraint::addVariable (int treeOrdinal)
{
  nonZeroVariables[treeOrdinal] = true;
}

bool Constraint::containsVariable (int treeOrdinal) const
{
  return nonZeroVariables[treeOrdinal];
}

int Constraint::slack() const
{
  int diff = c;
  for (int i = 0; i < nTrees; ++i)
    if (nonZeroVariables[i])
      diff -= trees[i].followingGap;
  return diff;
}



void setUpConstraints (Constraint* constraints, int* byHeight)
{
  // constraints[i] describes the distance between trees[byHeight[i]] and
  // the next taller tree, trees[byHeight[i+1])
  for (int i = 0; i < nTrees-1; ++i)
    {
      Constraint& con = constraints[i];
      int startOrd = byHeight[i];
      int stopOrd = byHeight[i+1];
      con.c = d;
      for (int j = min(startOrd, stopOrd); j < max(startOrd, stopOrd); ++j)
	con.addVariable (j);
    }
}



bool solveConstraints (Constraint* constraints, int* byHeight)
{
  // For each tree between shortest and tallest
  for (int i = min(shortestTreeOrd, tallestTreeOrd); 
       i < max(shortestTreeOrd, tallestTreeOrd); ++i)
    {
      // Compute the slack of trees[i].followingGap as the minimum of the
      //   the slacks of all constraints involving this tree
      int slack = 10000000;
      for (int j = 0; j < nTrees-1; ++j) {
	if (constraints[j].containsVariable (i))
	    {
	      int s = constraints[j].slack();
	      //cerr << "Slack of constraint " << j << " is " << s << endl;
	      slack = min(slack, s);
	    }
      }
      if (slack < 0 || slack == 10000000)
	return false; // Cannot solve this system
      // cerr << "Slack of tree " << i << " is " << slack << endl;
      trees[i].followingGap += slack;
    }

  // Check to be sure none of the constraints are being violated
  for (int i = 0; i < nTrees-1; ++i)
    if (constraints[i].slack() < 0)
      return false;

  return true;
}



int solve()
{
  // Sort trees by height
  int* byHeight = new int[nTrees];
  for (int i = 0; i < nTrees; ++i)
    byHeight[i] = i;
  
  // copy (trees, trees+nTrees, ostream_iterator<Tree>(cerr, " ")); cerr << endl;

  sort (byHeight, byHeight+nTrees, compareIndirectByHeight);
  shortestTreeOrd = byHeight[0];
  tallestTreeOrd = byHeight[nTrees-1];

  // copy (byHeight, byHeight+nTrees, ostream_iterator<int>(cerr, " ")); cerr << endl;

  Constraint* constraints = new Constraint[nTrees-1];
  setUpConstraints (constraints, byHeight);
  // copy (constraints, constraints+nTrees-1, ostream_iterator<Constraint>(cerr, " ")); cerr << endl;

  bool OK = solveConstraints (constraints, byHeight);
  int distance = 0;
  if (OK)
    {
      for (int i = min(shortestTreeOrd, tallestTreeOrd); 
	   i < max(shortestTreeOrd, tallestTreeOrd); ++i)
	distance += trees[i].followingGap;
    }
  else
    distance = -1;
  delete [] byHeight;
  delete [] constraints;
  return distance;
}



void ninja (istream& in)
{
  while (true) 
    {
      in >> nTrees >> d;
      if (nTrees == 0)
	break;

      trees = new Tree[nTrees];
      for (int i = 0; i < nTrees; ++i)
	{
	  in >> trees[i].height;
	  trees[i].followingGap = 1;
	}
      cout << solve() << endl;
      delete [] trees;
    }
}


int main (int argc, char** argv)
{
  if (argc == 1)
    ninja(cin);
  else
    {
      ifstream in (argv[1]);
      ninja (in);
    }
  return 0;
}


