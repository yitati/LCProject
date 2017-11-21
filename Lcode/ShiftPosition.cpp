/*
 * Laicode_ShiftPosition.cpp

Given an integer array A, A is sorted in ascending order first then shifted by an arbitrary number of positions,
For Example, A = {3, 4, 5, 1, 2} (shifted left by 2 positions). Find the index of the smallest number.

Assumptions

There are no duplicate elements in the array
Examples

A = {3, 4, 5, 1, 2}, return 3
A = {1, 2, 3, 4, 5}, return 0
Corner Cases

What if A is null or A is of zero length? We should return -1 in this case.

 */

#include <vector>

using namespace std;

int shiftPosition(vector<int> input)
{
	if(input.empty()) return -1;
	int lhs = 0, rhs = input.size()-1;
	while(lhs < rhs - 1)
	{
		int mid = lhs + (rhs-lhs)/2;
		if(input[mid] < input[rhs])
		{
			rhs = mid;
		}
		else
		{
			lhs = mid;
		}
	}
	return input[lhs] < input[rhs] ? lhs : rhs;
}



