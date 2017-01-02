/******************************************************************************/
/*
* Question: #80 Remove Duplicates from Sorted Array II
* Follow up for "Remove Duplicates":
* What if duplicates are allowed at most twice?
* For example,
* Given sorted array nums = [1, 1, 1, 2, 2, 3],
* Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
* It doesn't matter what you leave beyond the new length.
*/
/*****************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicatesII(vector<int>& nums) {
	if (nums.size() < 2) return nums.size();
	bool flag = false;
	int n = nums.size();
	int insert = 0, search = insert + 1;
	while (search < n)
	{
		if (nums[search] == nums[insert])
		{
			if (flag == true)
			{
				search++;
			}
			else
			{
				flag = true;
				nums[++insert] = nums[search++];
			}
		}
		else
		{
			flag = false;
			nums[++insert] = nums[search++];
		}
	}
	return insert + 1;
}

/*
int main(int argc, char ** argv)
{
	int input1[] = { 1,1,1,2,2,3,3,4,4,4,4,5,6,7,7,8,9,9,9,9 };
	vector<int> nums1(input1, input1+sizeof(input1) / sizeof(int));
	vector<int> nums2;

	cout << removeDuplicatesII(nums1) << endl;
	cout << removeDuplicatesII(nums2) << endl;

	system("pause");

}
*/
