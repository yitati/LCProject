/*
 * Laicode_CommonNumbersOfTwoArraysII.cpp
 *
company tag: Facebook

Find all numbers that appear in both of two unsorted arrays.

Assumptions

Both of the two arrays are not null.
In any of the two arrays, there could be duplicate numbers.
Examples

A = {1, 2, 3, 2}, B = {3, 4, 2, 2, 2}, return [2, 2, 3] (there are both two 2s in A and B)

 */

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
 * for unsorted array, if we do sort, then the time complexity is O(nlogn + mlogm)
 * but if we use hashmap the time complexity will be O(m+n)
 */
vector<int> common(vector<int> a, vector<int> b)
{
	// store the common element and their frequencies
	unordered_map<int, int> freq;
	vector<int> result;
	for(int num : a)
	{
		freq[num]++;
	}
	for(int num : b)
	{
		if(freq.count(num))
		{
			result.push_back(num);
			freq[num]--;
			if(freq[num] == 0) freq.erase(num);
		}
	}

	// if the output needs order
	sort(result.begin(), result.end());
	return result;
}




