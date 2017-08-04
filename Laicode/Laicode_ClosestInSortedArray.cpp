/*
Given a target integer T and an integer array A sorted in ascending order,
find the index i in A such that A[i] is closest to T.

Assumptions
There can be duplicate elements in the array, and we can return any of the indices with same value.

Examples
A = {1, 2, 3}, T = 2, return 1
A = {1, 4, 6}, T = 3, return 1
A = {1, 4, 6}, T = 5, return 1 or 2
A = {1, 3, 3, 4}, T = 2, return 0 or 1 or 2

Corner Cases
What if A is null or A is of zero length? We should return -1 in this case.
*/

#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int closestInSortedArray(vector<int> input, int target)
{
	int res = -1, lhs = 0, rhs = input.size() - 1, closest = INT_MAX;
	while (lhs <= rhs)
	{
		int mid = lhs + (rhs - lhs) / 2;
		if (input[mid] == target) return mid;
		else
		{
			if (abs(input[mid] - target) < closest)
			{
				closest = abs(input[mid] - target);
				res = mid;
			}
			if (input[mid] < target) lhs = mid + 1;
			else rhs = mid - 1;
		}
	}
	return res;
}
