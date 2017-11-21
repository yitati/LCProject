/*************************************************************/
/*
* Question: #137 Single Number II
* Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one. 
* Note:
* Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
*/
/***********************************************************/

#include <vector>

using namespace std;

int singleNumberII(vector<int>& nums)
{
	int result = 0;
	for (int i = 31; i >= 0; i--)
	{
		int digitI = 0;
		for (int num : nums)
		{
			digitI += ((num >> i) & 1);
		}
		result |= ((digitI % 3) << i);
	}
	return result;
}

int singleNumberII2(vector<int> & nums)
{
	int one = 0, two = 0, three = 0;
	for (int num : nums)
	{
		two |= num & one;
		one ^= num;
		three = one & two;

		one &= ~three;
		two &= ~three;
	}
	return one;
}