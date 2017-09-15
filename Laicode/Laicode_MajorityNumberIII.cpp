/*
 * Laicode_MajorityNumberIII.cpp
 *
Given an integer array of length L, find all numbers that occur more than 1/K * L times if any exist.

Assumptions

The given array is not null or empty
K >= 2
Examples

A = {1, 2, 1, 2, 1}, K = 3, return [1, 2]
A = {1, 2, 1, 2, 3, 3, 1}, K = 4, return [1, 2, 3]
A = {2, 1}, K = 2, return []
 */

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
 * keep an unordered_map to log the number and frequency, but keep a size k map would be enough
 */
vector<int> majority(vector<int>array, int k)
{
	// this is initial filtering map
	unordered_map<int, int> topk;
	int threshold = array.size()/k;

	for(int num : array)
	{
		if(topk.count(num)) topk[num]++;
		else
		{
			if(topk.size() < k) topk[num] = 1;
			else
			{
				// do the same as majority number I and II
				auto it = topk.begin();
				while(it != topk.end())
				{
					if(--it->second == 0)
					{
						it = topk.erase(it);
					}
					else it++;
				}
			}
		}
	}

	// second filtering
	unordered_map<int, int> winner;
	vector<int> majors;
	for(int num : array)
	{
		if(topk.count(num)) winner[num]++;
		// we want to count only once for each duplicate
		if(winner[num] == threshold + 1) majors.push_back(num);
	}

	sort(majors.begin(), majors.end());
	return majors;

}


