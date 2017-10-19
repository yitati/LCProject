/******************************************************************************
* Question: #31 Next Permutation
* Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
* If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
* The replacement must be in-place, do not allocate extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

* Follow-up Question: Previous Permutation
* company tag: Facebook
* Given a list of integers, which denote a permutation.
* Find the previous permutation in ascending order.
*****************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// example 3214765
void nextPermutation(vector<int>& nums) 
{
    if(nums.size() < 2) return;
    int lhs = nums.size()-1;
    // find the first element that is smaller than its next, lhs-1 is the one to swap
    while(lhs >= 1 && nums[lhs-1] >= nums[lhs]) lhs--;
    if(lhs >= 1) // this is the corner case when it is already the last one
    {
        int rhs = lhs;
        while(rhs+1 < nums.size() && nums[rhs+1] > nums[lhs-1]) rhs++;
        swap(nums[lhs-1], nums[rhs]);
    }
    sort(nums.begin()+lhs, nums.end());
}


// company tag: Facebook
// similar problem, how to find the previous permutation?
void previousPermutation(vector<int>& nums)
{
	if(nums.size() < 2) return;
	int lhs = nums.size()-1;
	// find the first element that is larger than its next, lhs-1 is the one to swap
	while(lhs >= 1 && nums[lhs-1] <= nums[lhs]) lhs--;
	if(lhs >= 1) // corner case if it is already the first one, then we need to do reverse sort only
	{
		int rhs = lhs;
		while(rhs+1 < nums.size() && nums[rhs+1] < nums[lhs-1]) rhs++;
		swap(nums[rhs], nums[lhs-1]);
	}
	sort(nums.begin()+lhs, nums.end(), greater<int>());
}

/*
int main(int argc, char * * argv)
{
	int input[] = {1, 2, 3, 4};
	vector<int> nums(input, input + sizeof(input) / sizeof(int));
	//nextPermutation(nums);
	nums = previousPermuation(nums);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << "    ";
	}

	cout << endl;
	system("pause");
}
*/
