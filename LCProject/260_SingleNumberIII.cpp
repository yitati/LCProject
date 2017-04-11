/*************************************************************/
/*
* Question: #137 Single Number III
* Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
* Find the two elements that appear only once. 
For example: 
Given nums = [1, 2, 1, 3, 2, 5], return [3, 5]. 
* Note:
* 1.The order of the result is not important. So in the above example, [5, 3] is also correct.
* 2.Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/
/***********************************************************/

#include <vector>

using namespace std;
// use bit manipulation, we xor all the numbers and what left is A^B
// then we found the first bit that result in 1 (which means A and B is different in this bit)
// then we seperate the numbers into two groups and find A and B from doing single number I
vector<int> singleNumber(vector<int>& nums)
{
	int bitXor = 0;
	vector<int> results(2, 0);
	for (int num : nums) bitXor ^= num;
	// get the mask with the last bit to be 1 !!!! important
	int mask = bitXor&(-bitXor);
	for (int num : nums)
	{
		if ((num & mask) == mask) results[0] ^= num;
		else results[1] ^= num;
	}
	return results;
}