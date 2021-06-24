// minesweeper.cpp : Defines the entry point for the console application.
// Tom Hain, Sept 8, 2009
#include <iostream>
#include <vector>
using namespace std;

void main()
{
	for (int nRows, nCols; cin >> nRows >> nCols, nRows * nCols; )
	{
		vector<vector<char> > board(nRows+2, vector<char>(nCols+2, '.'));
		for (int i = 1; i < nRows+1; ++i)
			for (int j = 1; j < nCols+1; ++j)
				cin >> board[i][j];

		const int displ[][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
		for (int i = 1; i < nRows+1; ++i, cout << endl)
			for (int count, j = 1; count = 0, j < nCols+1; cout << static_cast<char>(board[i][j++]=='*'? '*': '0' + count))
				for (int k = 0; k < 8; ++k)
					count += (board[ i + displ[k][0] ][ j + displ[k][1] ] == '*'? 1 : 0);
	}
}

