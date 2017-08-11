/*
 * Laicode_SearchInShiftedSortedArray.cpp

 Given a target integer T and an integer array A, A is sorted in ascending order first,
 then shifted by an arbitrary number of positions.

For Example, A = {3, 4, 5, 1, 2} (shifted left by 2 positions). Find the index i such
that A[i] == T or return -1 if there is no such index.

Assumptions

There are no duplicate elements in the array.
Examples

A = {3, 4, 5, 1, 2}, T = 4, return 1
A = {1, 2, 3, 4, 5}, T = 4, return 3
A = {3, 5, 6, 1, 2}, T = 4, return -1
Corner Cases

What if A is null or A is of zero length? We should return -1 in this case.

 */

#include <vector>

using namespace std;

int searchInShiftedSortedArrayI(vector<int> input, int target)
{
	if(input.empty()) return -1;

	int lhs = 0, rhs = input.size()-1;
	while(lhs <= rhs)
	{
		int mid = lhs + (rhs - lhs)/2;
		if(input[mid] == target) return mid;
		else if
	}
}



