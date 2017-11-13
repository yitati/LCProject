/*
 * Laicode_TotalOccurance.cpp
 *

Given a target integer T and an integer array A sorted in ascending order,
Find the total number of occurrences of T in A.

Examples

A = {1, 2, 3, 4, 5}, T = 3, return 1
A = {1, 2, 2, 2, 3}, T = 2, return 3
A = {1, 2, 2, 2, 3}, T = 4, return 0
Corner Cases

What if A is null? We should return 0 in this case.

 */

#include <vector>

using namespace std;

/*
 * find the first occurance
 */
int firstOccurance(vector<int>input, int target)
{
	int lhs = 0, rhs = input.size()-1;
	while(lhs + 1 < rhs)
	{
		int mid = lhs + (rhs-lhs)/2;
		if(target <= input[mid]) rhs = mid;
		else lhs = mid;
	}
	if(input[lhs] == target) return lhs;
	if(input[rhs] == target) return rhs;
	return -1;
}

/*
 * find the last occurance
 */
int lastOccurance(vector<int>input, int target)
{
	int lhs = 0, rhs = input.size()-1;
	while(lhs + 1 < rhs)
	{
		int mid = lhs + (rhs-lhs)/2;
		if(target < input[mid]) rhs = mid;
		else lhs = mid;
	}
	if(input[rhs] == target) return rhs;
	if(input[lhs] == target) return lhs;
	return -1;
}

/*
 * binary search find the first occurance, and find the last occurance.
 * then return the total occurance.
 */
int totalOccurrence(vector<int> input, int target)
{
  if(input.empty()) return 0;
	int first = firstOccurance(input, target);
	int last = lastOccurance(input, target);
	if (first == -1 || last == -1) return 0;
	return last-first+1;
}




