/*
 * MoveZeros.cpp
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 */

#include <vector>

using namespace std;

/*
 * two pointers - move from two ends to middle, this will change the order of the non-zero elements
 * But this solution garentee the minimal swap
 */
void moveZerosTowards(vector<int>& nums)
{
	int n = nums.size(), i = 0, j = n-1;
	while(i <= j)
	{
		if(nums[i] != 0) i++;
		else if(nums[j] == 0) j--;
		else
		{
			swap(nums[i++], nums[j--]);
		}
	}
}

/*
 * two pointers - both move from left to right, this will make sure the order of number is correct
 */
void moveZerorKeepOrder(vector<int>& nums)
{
	int n = nums.size(), slow = 0, fast = 0;
	while(fast < nums.size())
	{
		if(nums[fast] != 0)
		{
			nums[slow++] = nums[fast++];
		}
		else fast++;
	}
	while(slow < nums.size())
	{
		nums[slow++] = 0;
	}
}
