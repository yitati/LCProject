/******************************************************************************/
/*
* Question: #220 Contains Duplicates III
* Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute 
* difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k. 
*/
/*****************************************************************************/

#include <vector>
#include <set>

using namespace std;


// Review multiset.lower_bound
// Review distance(iterator begin, iterator end)
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
	// keep a window set to record all numbers from nums[i-k, i]
	// so every num inside window will satisfy i-j <= k
	// then we will look for the proper nums[j] inside window
	// which should satisfy nums[j]-t <= byns[i] << nums[j]+t (j should be in range [i-k, i])
 	multiset<long long> window;
 	for(int i=0; i<nums.size(); i++)
 	{
 		long long lhs = (long long) nums[i] - t;
 		long long rhs = (long long) nums[i] + t;

 		auto left = window.lower_bound(lhs);
 		auto right = window.lower_bound(rhs + 1);
 		if(left != window.end() && distance(left, right) > 0) return true;

 		window.insert(nums[i]);
 		if(i - k >= 0)
 		{
 			auto it = window.find(nums[i-k]);
 			window.erase(*it);
 		}
 	}
 	return false;
}
