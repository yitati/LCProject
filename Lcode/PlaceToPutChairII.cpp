/*
 * Laicode_PlaceToPutChairII.cpp

Given a gym with k pieces of equipment without any obstacles.  Let’s say we bought a chair
and wanted to put this chair into the gym such that the sum of the shortest path cost from
the chair to the k pieces of equipment is minimal. The gym is represented by a char matrix,
‘E’ denotes a cell with equipment, ' ' denotes a cell without equipment. The cost of moving
from one cell to its neighbor(left, right, up, down) is 1. You can put chair on any cell in the gym.

Assumptions

There is at least one equipment in the gym
The given gym is represented by a char matrix of size M * N, where M >= 1 and N >= 1,
it is guaranteed to be not null
​Examples

{ { 'E', ' ', ' ' },

  {  ' ', 'E',  ' ' },

  {  ' ',  ' ', 'E' } }

we should put the chair at (1, 1), so that the sum of cost from the chair to the two equipments
is 2 + 0 + 2 = 4, which is minimal.

 */

#include <vector>
#include <queue>
#include <climits>

using namespace std;

void updateCostFromEquipment(const vector<vector<char>>& gym,  vector<vector<int>>& cost, int xstart, int ystart) {
  vector<vector<int>> distance(gym.size(), vector<int>(gym[0].size(), INT_MAX));
  queue<pair<int, int>> toVisit;

  toVisit.push(pair<int, int>(xstart, ystart));
  distance[xstart][ystart] = 0;

  const static int dx[4] = {1, -1, 0, 0};
  const static int dy[4] = {0, 0, -1, 1};
  while (!toVisit.empty()) {
    pair<int, int> top = toVisit.front();
    toVisit.pop();
    for (int i=0; i<4; i++) {
      int x = top.first + dx[i];
      int y = top.second + dy[i];
      if (x > -1 && x < gym.size() && y > -1 && y < gym[0].size() &&
      distance[x][y] == INT_MAX) {
        toVisit.push(pair<int, int>(x, y));
        distance[x][y] = distance[top.first][top.second] + 1;
        cost[x][y] += distance[x][y];
      }
    }
  }
}

vector<int> placeToPutChairII(vector<vector<char>> gym) {
  vector<int> result;
  if (gym.size() == 0 && gym[0].size() == 0) return result;

  vector<vector<int>> cost(gym.size(), vector<int>(gym[0].size(), 0));
  for (int i=0; i<gym.size(); i++) {
    for (int j=0; j<gym[0].size(); j++) {
      if (gym[i][j] == 'E') {
        updateCostFromEquipment(gym, cost, i, j);
      }
    }
  }

  int minCost = INT_MAX;
  for (int i=0; i<gym.size(); i++) {
    for (int j=0; j<gym[0].size(); j++) {
      if (cost[i][j] < minCost) {
        result = {i, j};
        minCost = cost[i][j];
      }
    }
  }

  return result;
}

