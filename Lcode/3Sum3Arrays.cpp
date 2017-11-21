/*
 * 3Sum3Arrays.cpp
 *

Given three arrays, determine if a set can be made by picking one element from each array that sums to the given target number.

Assumptions

The three given arrays are not null and have length of at least 1
Examples

A = {1, 3, 5}, B = {8, 2}, C = {3}, target = 14, return true(pick 3 from A, pick 8 from B and pick 3 from C)

 */

#include <vector>
#include <unordered_set>

using namespace std;

bool exist(vector<int> a, vector<int> b, vector<int> c, int target)
{
	unordered_set<int> unique;
	for(int i=0; i<a.size(); i++)
	{
		for(int j=0; j<b.size(); j++)
		{
			unique.insert(a[i] + b[j]);
		}
	}

	for(int num : c)
	{
		int complement = target - num;
		if(unique.count(complement)) return true;
	}

	return false;
}



