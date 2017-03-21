/******************************************************************************/
/*
* Question: #447 Number Of Boomerangs
* Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) 
* such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
* Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are 
* all in the range [-10000, 10000] (inclusive).

Example:

Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]

*/
/*****************************************************************************/

#include <vector>
#include <unordered_map>

using namespace std;

int numberOfBoomerangs(vector<pair<int, int>>& points) 
{
	int count = points.size(), bCount = 0;
	for (int i = 0; i < count; i++)
	{
		unordered_map<int, int> table;
		for (int j = 0; j < count; j++)
		{
			if (j == i) continue;
			int diff = (points[i].first - points[j].first)*(points[i].first - points[j].first) +
				(points[i].second - points[j].second)*(points[i].second - points[j].second);
			table[diff]++;
		}
		for (auto it : table)
		{
			if (it.second >= 2) bCount += it.second * (it.second - 1);
		}
	}
	return bCount;
}