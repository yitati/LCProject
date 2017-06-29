/******************************************************************************/
/*
* Question: #189 Rotate Array
* Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

* Note:
* Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/
/*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<int>& nums, int k)
{
	int n = nums.size();
	k = k % n;
	reverse(nums.begin(), nums.begin() + n - k);
	reverse(nums.begin() + n - k, nums.end());
	reverse(nums.begin(), nums.end());
}
