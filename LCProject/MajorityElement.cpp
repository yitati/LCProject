/******************************************************************************
* Question: #169 Majority Element
* company tag: eBay
* Given an array of size n, find the majority element. The majority element is the element that
* appears more than n/2 times.
* You may assume that the array is non-empty and the majority element always exist in the array.
*
*****************************************************************************/

#include <vector>

using namespace std;

// O(n) time and O(1) space
int majorityElement(vector<int>& nums)
{
	int count = 1;
	int champion = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == champion) { count++; continue; }
		else {
			count--;
			if (count == 0) { champion = nums[i]; count++; }
		}
	}
	return champion;
}
