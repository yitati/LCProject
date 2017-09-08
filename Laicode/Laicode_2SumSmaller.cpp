/*
 * Laicode_2SumSmaller.cpp
 *

Determine the number of pairs of elements in a given array that sum to a value smaller than the given target number.

Assumptions

The given array is not null and has length of at least 2
Examples

A = {1, 2, 2, 4, 7}, target = 7, number of pairs is 6({1,2}, {1, 2}, {1, 4}, {2, 2}, {2, 4}, {2, 4})

 */

#include <vector>
#include <algorithm>

using namespace std;

/*
 * fix lhs and find the rhs from right to left, then calculate the count
 */
int smallerPairs(vector<int> array, int target)
{
	if(array.size() < 2) return 0;
	sort(array.begin(), array.end());
	int count = 0;
	int lhs = 0, rhs = array.size()-1;
	while(lhs < rhs)
	{
		int sum = array[lhs] + array[rhs];
		if(sum < target) // we find a good rhs
		{
			count += rhs-lhs;
			lhs++;
		}
		else rhs--;
	}
	return count;
}

