/*
 * robot-challenge.cpp
 *
 *  Created on: Oct 27, 2009
 *      Author: Brianna
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

#define MAX_SPACES 10000

//int doint()
int main()
{
    ifstream infile("files/robotchallenge.in");
    ofstream outfile("files/robotchallenge.out");
    
    int (*totalPenalty)[MAX_SPACES] = new int[MAX_SPACES][MAX_SPACES];
    
    while (true)
    {
          int numSpaces = 0;
          infile >> numSpaces;
          if (numSpaces == 0)
          {
             delete totalPenalty;
             return 0;
          }
             
          vector<int> spaceX, spaceY, penalty;
          
          for (int i = 0; i < numSpaces; i++)
          {
              int x, y, p;
              infile >> x >> y >> p;
              spaceX.push_back(x);
              spaceY.push_back(y);
              penalty.push_back(p);
          }
          
          // push the end point onto the vector and increase numSpaces
          spaceX.push_back(100);
          spaceY.push_back(100);
          penalty.push_back(0);
          numSpaces++;
          
          cout << numSpaces << endl;
          
          // calculate the cumulative penalties
          for (int i = 0; i < numSpaces; i++)
          {
              totalPenalty[i][i] = penalty[i];
              for (int j = i+1; j < numSpaces; j++)
              {
                  totalPenalty[i][j] = totalPenalty[i][j-1] + penalty[j];
              }
          }
          
          cout << "got total penalty" << endl;
          
          double bestScore[MAX_SPACES];
          for (int i = 0; i < numSpaces; i++)
          {
              // start by assuming we're starting at (0, 0) and stopping here
              bestScore[i] = sqrt(spaceX[i] * spaceX[i] + spaceY[i] * spaceY[i]) + 1;
              
              // add penalty if applicable
              if (i > 0)
                 bestScore[i] += totalPenalty[0][i-1];
              
              for (int j = 0; j < i; j++)
              {
                  double score = bestScore[j] + 1 + sqrt(
                         (spaceX[i] - spaceX[j]) * (spaceX[i] - spaceX[j]) +
                         (spaceY[i] - spaceY[j]) * (spaceY[i] - spaceY[j]));
                  if (j != i-1)
                     score += totalPenalty[j+1][i-1];
                  if (score < bestScore[i])
                     bestScore[i] = score;
              }
          }
          
          
          outfile << setprecision(3) << fixed;
          outfile << bestScore[numSpaces-1] << endl;
          
          
          
    }
    
    
}
