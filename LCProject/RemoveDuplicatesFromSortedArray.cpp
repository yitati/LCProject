/******************************************************************************
* Question: #26 Remove Duplicates from Sorted Array
* company tag: Facebook
* Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
* Do not allocate extra space for another array, you must do this in place with constant memory.
* For example,
* Given input array nums = [1, 1, 2],
* Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
* It doesn't matter what you leave beyond the new length.
*****************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	if (nums.empty()) return 0;
	int n = nums.size();
	int insert = 0, search = insert+1;
	while (search < n)
	{
		if (nums[search] == nums[insert]) search++;
		else
		{
			nums[++insert] = nums[search++];
		}
	}
	return insert + 1;
}

/*
int main(int argc, char ** argv)
{
	int input[] = { 1,1,1,2,2,3,3,4,4,4,4,5,6,7,7,8,9,9,9,9 };
	vector<int> nums(input, input+sizeof(input) / sizeof(int));

	cout << removeDuplicates(nums) << endl;

	system("pause");

}
*/
