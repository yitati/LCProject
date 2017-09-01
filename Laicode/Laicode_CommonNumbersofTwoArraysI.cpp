/*
 * Laicode_CommonNumbersofTwoArraysI.cpp
 *

Find all numbers that appear in both of the two unsorted arrays, return the common numbers
in increasing order.

Assumptions

Both arrays are not null.
There are no duplicate numbers in each of the two arrays respectively.
Exmaples

A = {1, 2, 3}, B = {3, 1, 4}, return [1, 3]
A = {}, B = {3, 1, 4}, return []

 */

#include <vector>
#include <algorithm>

using namespace std;

vector<int> commonI(vector<int> a, vector<int> b)
{
	vector<int> result;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int i=0, j=0;
	while(i < a.size() && j < b.size())
	{
		if(a[i] == b[j])
		{
			result.push_back(a[i]);
			i++;
			j++;
		}
		else if(a[i] < b[j]) i++;
		else j++;
	}
	return result;
}


