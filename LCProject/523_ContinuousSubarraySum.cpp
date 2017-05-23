/******************************************************************************/
/*
* Question: #523 Continuous Subarray Sum
* Given a list of non-negative numbers and a target integer k, write a function to check 
* if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, 
* that is, sums up to n*k where n is also an integer. 
* Note:
* 1.The length of the array won't exceed 10,000.
* 2.You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
*/
/*****************************************************************************/

#include <vector>
#include <unordered_map>

using namespace std;

bool checkSubarraySum(vector<int>& nums, int k)
{
	unordered_map<int, int> visited;
	visited[0] = -1;
	int sum = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		sum += nums[i];
		if (k != 0) sum %= k;
		if (visited.count(sum))
		{
			if (i - visited[sum] > 1) return true;
		}
		else visited[sum] = i;
	}
	return false;
}