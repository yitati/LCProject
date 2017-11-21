/*
 * SkylineProblem.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: JoanneY1
 */

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;


/*
 * scan the horizontal left and right boundries, but we need to keep the highest one so far
 * and make sure that when one height ends, we need to remove that from the height set
 * use a set to store all "active" heights, and use stack to store the heightest one each time
 */
vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings)
{
	vector<pair<int, int>> lines;
	// we need to use start point to overlap end point, so here lhs value should be negative
	for(auto& building : buildings)
	{
		lines.emplace_back(building[0], -building[2]);    // collect the left point and the height
		lines.emplace_back(building[1], building[2]);   // collect the right point and the negative height
	}
	sort(lines.begin(), lines.end());  // sort it by horizontal order
	multiset<int> height;
	vector<pair<int, int>> results;

	for(auto& it : lines)
	{
		if(it.second < 0)  // when there is a left point, need to enqueue
		{
			if(results.empty() || (-it.second) > results.back().second)  // new highest point
			{
				results.emplace_back(it.first, -it.second);
			}
			height.insert(-it.second);
		}
		else   // when there is a right point, we need to pop it out
		{
			height.erase(height.find(it.second));   // erase only one occurance
			if(height.empty()) results.emplace_back(it.first, 0);   // one corner case is 0 !!!
			else if(results.back().second > *height.rbegin())
			{
				results.emplace_back(it.first, *height.rbegin());
			}
		}
	}

	return results;
}
