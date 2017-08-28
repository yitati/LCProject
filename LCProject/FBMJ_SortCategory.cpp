/*
 * Mianjing: Sort Category
 * Given an API
 * getCategory(int n) return one of the {L|M|H} three category
 * Question 1: Given an array of integers, each of the integer has a corresponding category,
 * sort the array by its category.
 * Question 2: If we have k category instead of 3, how do we sort integers by category here?
 *
 */

// TODO - confirm with BAOBAO about K category

#include <vector>
#include <algorithm>

using namespace std;

const int CategoryBase = 3;

int getCategory(int n)
{
	return rand()%CategoryBase;
}
/*
 * Question 1 - sort 3 category, this is very similar to sort colors
 * we need to use 3-way partition
 * [0, i) - all L
 * [i, k) - all M
 * [k, j] - all unknown
 * (j, n-1] - all H
 */
vector<int> sort3Category(vector<int>& nums)
{
	int low = 0, high = nums.size()-1, k = 0;
	while(k <= high)
	{
		if(getCategory(nums[k]) == 0)
		{
			swap(nums[low++], nums[k++]);
		}
		else if(getCategory(nums[k]) == 2)
		{
			swap(nums[k], nums[high--]);
		}
		else
		{
			k++;
		}
	}
	return nums;
}


/*
 * Question 2 - sort k categories.
 * It is actually using quick sort, choose a middle category and do the three way sort.
 * And in each half side, redo the three-way sort. Then we should be able to get the final.
 *
 */

// helper function that will do three way partition
// [0, i) - lower than mid
// [i, k) - equal to mid
// [k, j] - unknown
// (j, n-1] - larger than mid
void threeWayPartition(vector<int>& nums, int low, int high, int lhs, int rhs)
{
	if(high <= low) return;
	int mid = low + (high - low)/2;
	int i = lhs, j = rhs, k=lhs;
	while(k <= j)
	{
		if(getCategory(nums[k]) < mid)
		{
			swap(nums[k++], nums[i++]);
		}
		else if(getCategory(nums[k]) > mid)
		{
			swap(nums[k], nums[j--]);
		}
		else k++;
	}
	threeWayPartition(nums, low, mid-1, lhs, i-1);
	threeWayPartition(nums, mid+1, high, j+1, rhs);
}

// if the category ranges from
vector<int> sortKCategory(vector<int>& nums)
{

}




