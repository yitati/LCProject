/*
 * Laicode_MajorityNumberII.cpp
 *

Given an integer array of length L, find all numbers that occur more than 1/3 * L times if any exist.

Assumptions

The given array is not null
Examples

A = {1, 2, 1, 2, 1}, return [1, 2]
A = {1, 2, 1, 2, 3, 3, 1}, return [1]
A = {1, 2, 2, 3, 1, 3}, return []

 */

#include <vector>
#include <algorithm>

using namespace std;

/*
 * for major elements that appears more that 1/3 of the time, we want to
 */
vector<int> majority(vector<int> array)
{
	int winner1 = 0, winner2 = 1, count1 = 0, count2 = 0;
	for(int num : array)
	{
		if(num == winner1) count1++;
		else if(num == winner2) count2++;
		else if(count1 == 0)
		{
			winner1 = num;
			count1++;
		}
		else if(count2 == 0)
		{
			winner2 = num;
			count2++;
		}
		else
		{
			count1--;
			count2--;
		}
	}

	count1 = 0;
	count2 = 0;
	for(int num : array)
	{
		if(num == winner1) count1++;
		if(num == winner2) count2++;
	}

	vector<int> result;
	if(count1 > array.size()/3) result.push_back(winner1);
	if(count2 > array.size()/3) result.push_back(winner2);

	sort(result.begin(), result.end());

	return result;
}

