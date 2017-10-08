/*
 * Monotonic.cpp
 * company tag: Facebook
 * http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=294881&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3046%5D%5Bvalue%5D%3D2%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311
 * 给一个数组array，判断该数组是否是单调的。如果数字都相同为true。
 *
 */

#include <vector>

using namespace std;

bool isMonotonic(vector<int>& nums)
{
	int flag = 0;
	if(nums.empty() || nums.size() < 2) return false;
	if(nums[0] > nums[1])
	{
		flag = -1;
	}
	else if(nums[0] < nums[1])
	{
		flag = 1;
	}
	else
	{
		flag = 0;
	}

	for(int i=2; i<nums.size(); i++)
	{
		if(nums[i] > nums[i-1] && flag != 1) return false;
		if(nums[i] < nums[i-1] && flag != -1) return false;
		if(nums[i] == nums[i-1] && flag != 0) return false;
	}

	return true;
}


