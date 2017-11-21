/*
***** Basic question is longest consecutive 1 **************
Given a matrix that contains only 1s and 0s, find the largest X shape which contains only 1s, 
with the same arm lengths and the four arms joining at the central point.
Return the arm length of the largest X shape.

Assumptions
The given matrix is not null, has size of N * M, N >= 0 and M >= 0.

Examples

{ {0, 0, 0, 0},

{1, 1, 1, 1},

{0, 1, 1, 1},

{1, 0, 1, 1} }

the largest X of 1s has arm length 2.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

typedef enum 
{
	TR_TO_BL = 0,
	BL_TO_TR,
	TL_TO_BR,
	BR_TO_TL,
	TYPE_COUNT
} DIAGTYPE;

struct DiagLength
{
	int length[TYPE_COUNT];  // an array of 4 to put all the length
	DiagLength() { for (int i = 0; i < TYPE_COUNT; i++) length[i] = 0; }
	int minlen()
	{
		int minLen = INT_MAX;
		for (int i = 0; i < TYPE_COUNT; i++)
		{
			minLen = min(minLen, length[i]);
		}
		return minLen;
	}
};

// helper funtion that will fill the table with four different directions of diag length
inline void fillDiagonalPoints(const vector<vector<int>>& input, vector<vector<DiagLength>>& table, int x, int y, int typeId)
{
	int row = input.size();
	int col = input[0].size();
	static int dx[TYPE_COUNT] = { 1, -1, 1, -1 };
	static int dy[TYPE_COUNT] = { -1, 1, 1, -1 };
	int start = 0;
	while (x < row && x >= 0 && y < col && y >= 0)
	{
		start = (input[x][y] == 1 ? start + 1 : 0);
		table[x][y].length[typeId] = start;
		x += dx[typeId];
		y += dy[typeId];
	}
}

int largestXofOne(vector<vector<int> > input) 
{
	if (input.empty() || input[0].empty()) return 0;
	int row = input.size(), col = input[0].size();
	static int dx[TYPE_COUNT] = { 1, -1, 1, -1 };
	static int dy[TYPE_COUNT] = { -1, 1, 1, -1 };

	int x, y, start, maxX = 0;
	vector<vector<DiagLength>> table(row, vector<DiagLength>(col));

	for (int i = 0; i < row; i++)
	{
		fillDiagonalPoints(input, table, i, col - 1, TR_TO_BL);  // left to right
		fillDiagonalPoints(input, table, i, col - 1, BR_TO_TL);  // left to right
		fillDiagonalPoints(input, table, i, 0, TL_TO_BR);  // right to left
		fillDiagonalPoints(input, table, i, 0, BL_TO_TR);  // right to left
	}

	for (int j = 0; j < col; j++)
	{
		fillDiagonalPoints(input, table, 0, j, TR_TO_BL);  // top to bottom
		fillDiagonalPoints(input, table, 0, j, TL_TO_BR);  // top to bottom
		fillDiagonalPoints(input, table, row-1, j, BR_TO_TL);  // bottom to top
		fillDiagonalPoints(input, table, row-1, j, BL_TO_TR);  // bottom to top
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			maxX = max(maxX, table[i][j].minlen());
		}
	}

	return maxX;
}
