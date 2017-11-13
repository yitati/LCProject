/*
 * Laicode_FindMedianTwoArrays.cpp
 *
Given two arrays of integers, find the median value.

Assumptions

The two given array are not null and at least one of them is not empty
The two given array are not guaranteed to be sorted
Examples

A = {4, 1, 6}, B = {2, 3}, median is 3
A = {1, 4}, B = {3, 2}, median is 2.5

 */


#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int findKthInTwo(vector<int>& a, int ai, vector<int>& b, int bi, int k)
{
	if(ai >= a.size()) return b[k-1];
	if(bi >= b.size()) return a[k-1];
	if(k == 1) return min(a[ai], b[bi]);

	int aval = ai + k/2 -1 < a.size() ? a[ai+k/2-1] : INT_MAX;
	int bval = bi + k/2 -1 < b.size() ? b[bi+k/2-1] : INT_MAX;

	if(aval < bval)
	{
		return findKthInTwo(a, ai+k/2, b, bi, k-k/2);
	}
	else
	{
		return findKthInTwo(a, ai, b, bi+k/2, k-k/2);
	}
}

double median(vector<int> a, vector<int> b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int bothSize = a.size() + b.size();
	if(bothSize%2 == 1)
	{
		return (double)findKthInTwo(a, 0, b, 0, bothSize/2+1);
	}
	else
	{
		int ret1 = findKthInTwo(a, 0, b, 0, bothSize/2);
		int ret2 = findKthInTwo(a, 0, b, 0, bothSize/2 + 1);
		return 0.5 * (ret1 + ret2);
	}
}


