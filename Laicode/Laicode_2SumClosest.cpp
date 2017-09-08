/*
 * Laicode_2SumClosest.cpp
 *

Find the pair of elements in a given array that sum to a value that is closest to
the given target number. Return the values of the two numbers.

Assumptions

The given array is not null and has length of at least 2
Examples

A = {1, 4, 7, 13}, target = 7, closest pair is 1 + 7 = 8, return [1, 7].

 */

#include <vector>
#include <climits>

using namespace std;

vector<int> solve(vector<int> array, int target)
{
	vector<int> result(2, -1);
	if(array.size() < 3) return result;
	// we need to save closest result and min diff
	int diff = INT_MAX;
	int lhs = 0, rhs = array.size()-1;
	sort(array.begin(), array.end());
	while(lhs < rhs)
	{
		int sum = array[lhs] + array[rhs];
		if(sum == target)
		{
			result[0] = array[lhs];
			result[1] = array[rhs];
			return result;
		}
		else
		{
			if(abs(sum-target) < diff)
			{
				diff = abs(sum-target);
				result[0] = array[lhs];
				result[1] = array[rhs];
			}
			if(sum < target) lhs++;
			else rhs--;
		}
	}
	return result;
}

