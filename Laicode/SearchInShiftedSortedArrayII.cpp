/*
 * Laicode_SearchInShiftedSortedArray.cpp

Given a target integer T and an integer array A, A is sorted in ascending order first, then shifted
by an arbitrary number of positions.

For Example, A = {3, 4, 5, 1, 2} (shifted left by 2 positions). Find the index i such that A[i] == T
or return -1 if there is no such index.

Assumptions

There could be duplicate elements in the array.
Examples

A = {3, 4, 5, 1, 2}, T = 4, return 1
A = {3, 3, 3, 1, 3}, T = 1, return 3
A = {3, 1, 3, 3, 3}, T = 1, return 1
​Corner Cases

What if A is null or A is of zero length? We should return -1 in this case.

 */

#include <iostream>
#include <vector>

using namespace std;

int searchInShiftedSortedArrayII(vector<int> input, int target)
{
	if(input.empty()) return -1;

  	int lhs = 0, rhs = input.size()-1;
  	while(lhs <= rhs)
  	{
  		int mid = lhs + (rhs - lhs)/2;
  		if(input[mid] == target) return mid;
  		else if(input[lhs] == input[mid] && input[rhs] == input[mid])
  		{
  			lhs++;
  			rhs--;
  		}
  		else if(input[mid] >= input[lhs])
  		{
  			if(target < input[mid] && target >= input[lhs]) rhs = mid-1;
  			else lhs = mid+1;
  		}
  		else
  		{
  			if(target > input[mid] && target <= input[rhs]) lhs = mid+1;
  			else rhs = mid-1;
  		}
  	}
  	return -1;
}




