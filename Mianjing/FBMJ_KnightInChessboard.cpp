/*
 * FBMJ_KnightInChessboard.cpp
 *
 Given any source point and destination pont on a chess board, we need to find whether
 Knight can move to the destination or not.
 Check details of the knight movement https://www.interviewbit.com/problems/knight-on-chess-board/

 Note that a knight cannot go out of the board.

 If yes, then waht would be the minimum number of steps for the knight to move to the said point.
 If knight can not move from the source point to the destination point, then return -1.


 Input:
 N, M, x1, y1, x2, y2
 where N and M are size of chess board
 x1, y1 coordinates of source point
 x2, y2 coordinates of destination point

 Output:
 return minimum moves or -1

 *
 */

/*
 * the only change to other graph question is now the possible "neighbors" has 8
 * and we need to calculate the next possible neighbor location
 * we can use BFS solution
 */


#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// BFS solution
// this can be improved by using two-way bfs solution
int canKnightMove1(int N, int M, int x1, int y1, int x2, int y2)
{
	if(x1==x2 && y1==y2) return 0;
	vector<vector<bool>> visited(N, vector<bool>(M,false));
	queue<pair<int, int>> locQueue;

	locQueue.emplace(x1, y1);
	visited[x1][y1] = true;

	int step = 0;

	while(!locQueue.empty())
	{
		step++;
		int queueSize = locQueue.size();
		for(int i = 0; i < queueSize; i++)
		{
			int r = locQueue.front().first;
			int c = locQueue.front().second;
			locQueue.pop();
			for(int k = 0; k < 8; k++)
			{
				int x = r + dx[k];
				int y = c + dy[k];
				if(x < 0 || x >= N || y < 0 || y >= M || visited[x][y] == true)  continue;
				if(x == x2 && y == y2) return step;
				locQueue.emplace(x, y);
				visited[x][y] = true;
			}
		}
	}

	return -1;
}


/*
 * Follow - up
 * company tag: Facebook
 * 1. If the chessboard is infinate
 * 2. If there are some obstacles in the board and if there is any obstacle in the path, the knight
 * cannot take that move
 * 3. Returns bool indecating if the knight can reach the final point or not
 */

/*
 * 	Solution for follow - up
 * 	we need to come up and encapsule a validator helper funtion that could validate each move
 * 	of the knight such as
 */

// assume this is the function provided to check if this point is valid
bool isObstacle(int i, int j)
{
	return false;
}

bool isMoveValid(int r, int c, int k)
{
	int x = r + dx[k];
	int y = c + dy[k];

	// if any obstacle exists in two path
	// insert validate funtion here
}




