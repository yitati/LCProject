/*
 * Laicode_PlaceToPutChair.cpp

Given a gym with k pieces of equipment and some obstacles.  We bought a chair and wanted
to put this chair into the gym such that  the sum of the shortest path cost from the chair
to the k pieces of equipment is minimal. The gym is represented by a char matrix,
‘E’ denotes a cell with equipment,
‘O’ denotes a cell with an obstacle,
'C' denotes a cell without any equipment or obstacle.
You can only move to neighboring cells (left, right, up, down)
if the neighboring cell is not an obstacle. The cost of moving
from one cell to its neighbor is 1. You can not put the chair
on a cell with equipment or obstacle.

Assumptions

There is at least one equipment in the gym
The given gym is represented by a char matrix of size M * N,
where M >= 1 and N >= 1, it is guaranteed to be not null
It is guaranteed that each 'C' cell is reachable from all 'E' cells.
If there does not exist such place to put the chair, just return null (Java) empty vector (C++)
Examples

{ { 'E', 'O', 'C' },

  {  'C', 'E',  'C' },

  {  'C',  'C',  'C' } }

we should put the chair at (1, 0), so that the sum of cost from the chair to the
two equipment is 1 + 1 = 2, which is minimal.

 */

#include <vector>
#include <queue>
#include <climits>

using namespace std;

/*
 * loop through each of the equipment place and BFS search all the distance to chair
 * keep one common distance table to mark all distance to every equipment
 * ! one thing to mark is that for each equipment there should be one seperate table to
 * mark visited
 */

/*
 * BFS search to calculate the steps to each spot in they gym from pointed equipment
 */
void fillDistFromOneSpot(vector<vector<char>>gym, int r, int c, vector<vector<int>>& dist)
{
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	vector<vector<bool>> visit(gym.size(), vector<bool>(gym[0].size(), false));
	queue<pair<int, int>> pos;
	pos.emplace(r, c);
	int step = 0;
	while(!pos.empty())
	{
		int levelSize = pos.size();
		step++;
		for(int i=0; i<levelSize; i++)
		{
			auto curr = pos.front();
			pos.pop();
			for(int k=0; k<4; k++)
			{
				int x = curr.first+dx[k];
				int y = curr.second+dy[k];
				if(x < 0 || x >= gym.size() || y < 0 || y >= gym[0].size() || gym[x][y] == 'O' || visit[x][y]) continue;
				visit[x][y] = true;
				dist[x][y] += step;
				pos.emplace(x, y);
			}
		}
	}
}

vector<int> placeToPutChair(vector<vector<char>> gym)
{
	vector<int> chair;
	if(gym.empty() || gym[0].empty()) return chair;
	int row = gym.size(), col = gym[0].size();
	vector<vector<int>> dist(row, vector<int>(col, 0));
	// push all equipment position to the queue
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(gym[i][j] == 'E')
			{

				fillDistFromOneSpot(gym, i, j, dist);
			}
		}
	}
	// calculate the shortest distance
	int minDist = INT_MAX;
	pair<int, int> result(-1, -1);
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(gym[i][j] == 'C')
			{
				if(dist[i][j] < minDist)
				{
					minDist = dist[i][j];
					result.first = i;
					result.second = j;
				}
			}
		}
	}

  if(result.first != -1)
  {
    chair.push_back(result.first);
    chair.push_back(result.second);
  }
	return chair;
}




