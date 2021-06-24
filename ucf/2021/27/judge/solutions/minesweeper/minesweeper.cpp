/*
 * minesweeper.cpp
 *
 *  Created on: Oct 27, 2009
 *      Author: Brianna
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile("files/minesweeper.in");
    ofstream outfile("files/minesweeper.out");
    
	while (true)
	{
		int rows, cols;
		infile >> rows >> cols;
		if (rows == 0) return 0;

		vector<string> board;
		for (int i = 0; i < rows; i++)
		{
			string row;
			infile >> row;
			board.push_back(row);
		}

		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < cols; c++)
			{
				if (board[r][c] == 'm')
					continue;

				int mines = 0;

				for (int newRow = r - 1; newRow <= r + 1; newRow++)
					for (int newCol = c - 1; newCol <= c + 1; newCol++)
					{
						if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols)
							continue;

						if (board[newRow][newCol] == 'm')
							mines++;

					}
				board[r][c] = (char)('0' + mines);
			}
		}

		for (int i = 0; i < rows; i++)
			outfile << board[i] << endl;

	}

}
