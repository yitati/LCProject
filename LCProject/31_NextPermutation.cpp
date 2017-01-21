/******************************************************************************/
/*
* Question: #31 Next Permutation
* Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
* If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
* The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
/*****************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// find the first element that is nums[j-1] < nums[j]
void nextPermutation(vector<int>& nums) 
{
	if (nums.size() < 2) return;
	int k = nums.size() - 1;
	int l, tmp;
	// find the first element that is smaller than its next
	while (k >= 1 && nums[k - 1] >= nums[k]) k--;
	// else find min value that is larger than nums[k-1]
	l = k;
	tmp = nums[k];
	while (l < nums.size() - 1 && nums[l + 1] > nums[k - 1]) l++;
	swap(nums[k - 1], nums[l]);
	sort(nums.begin() + k, nums.end());
}

/*
int main(int argc, char * * argv)
{
	int input[] = {1, 3, 2};
	vector<int> nums(input, input + sizeof(input) / sizeof(int));
	nextPermutation(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << "    ";
	}

	cout << endl;
	system("pause");
}
*/