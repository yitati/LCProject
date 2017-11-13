/*
 * CommonElementsIn3SortedArrays.cpp

Find all common elements in 3 sorted arrays.

Assumptions

The 3 given sorted arrays are not null
There could be duplicate elements in each of the arrays
Examples

A = {1, 2, 2, 3}, B = {2, 2, 3, 5}, C = {2, 2, 4}, the common elements are [2, 2]

 */


#include <vector>
#include <algorithm>

using namespace std;

// three pointers
vector<int> common3Array(vector<int> a, vector<int> b, vector<int> c)
{
	int i = 0, j = 0, k = 0;
	vector<int> result;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	while(i < a.size() && j < b.size() && k < c.size())
	{
		if(a[i] == b[j] && a[i] == c[k]) {
			result.push_back(a[i]);
			i++;
			j++;
			k++;
		}
		else if(a[i] < b[j] || a[i] < c[k]) i++;
		else if(b[j] < a[i] || b[j] < c[k]) j++;
		else if(c[k] < a[i] || c[k] < b[j]) k++;
	}
	return result;
}
