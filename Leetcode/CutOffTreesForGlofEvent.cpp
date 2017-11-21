/***********************************************************************************************************************************
 * Question #675 Cut Off Trees for Golf Event
 * company tag: Amazon
 * You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:
 * 0 represents the obstacle can't be reached.
 * 1 represents the ground can be walked through.
 * The place with number bigger than 1 represents a tree can be walked through, and this positive number represents the tree's height.
 * You are asked to cut off all the trees in this forest in the order of tree's height - always cut off the tree with lowest height first.
 * And after cutting, the original place has the tree will become a grass (value 1).
 * You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees.
 * If you can't cut off all the trees, output -1 in that situation.
 * You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.

Example 1:
Input:
[
 [1,2,3],
 [0,0,4],
 [7,6,5]
]
Output: 6
Example 2:
Input:
[
 [1,2,3],
 [0,0,0],
 [7,6,5]
]
Output: -1
Example 3:
Input:
[
 [2,3,4],
 [0,0,5],
 [8,7,6]
]
Output: 6
Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.
Hint: size of the given matrix will not exceed 50x50.
 **********************************************************************************************************************************/

#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

/*
 *  use priority queue to store all the locations for the tree and use bfs to find the shortest distance
 */
int shortestDist(vector<vector<int>>& forest, int sr, int sc, int er, int ec)
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    if(sr == er && sc == ec) return 0;

    queue<pair<int, int>> layer;
    unordered_set<int> visited;
    int row = forest.size(), col  = forest[0].size();
    int step = 0;

    layer.push(make_pair(sr, sc));
    visited.insert(sr*col + sc);

    while(!layer.empty())
    {
        int layerSize = layer.size();
        step++;
        for(int i=0; i<layerSize; i++)
        {
            auto curr = layer.front();
            layer.pop();
            for(int k=0; k<4; k++)
            {
                int x = curr.first + dx[k];
                int y = curr.second + dy[k];
                if(x == er && y == ec) return step;
                if(x <0 || x >= forest.size() || y < 0 || y >= forest[0].size() || visited.count(x*col + y)) continue;
                if(forest[x][y] == 0) continue;
                layer.push(make_pair(x, y));  // other cases
                visited.insert(x*col + y);
            }
        }
    }
    return -1;
}

int cutOffTree(vector<vector<int>>& forest)
{
    auto comp = [&](const pair<int, int>& lhs, const pair<int, int>& rhs) -> bool {
        return forest[lhs.first][lhs.second] > forest[rhs.first][rhs.second];
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);

    for(int i=0; i < forest.size(); i++)
    {
        for(int j=0; j < forest[0].size(); j++)
        {
            if(forest[i][j] > 1) minHeap.push(make_pair(i, j));
        }
    }

    int sr = 0, sc = 0;
    int dist = 0;

    while(!minHeap.empty())
    {
        auto end = minHeap.top();
        minHeap.pop();
        int step = shortestDist(forest, sr, sc, end.first, end.second);
        if(step == -1) return -1;
        else
        {
            dist += step;
        }
        sr = end.first;
        sc = end.second;
    }

    return dist;
}


