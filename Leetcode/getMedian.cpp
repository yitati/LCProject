#include <vector>
#include <algorithm>

using namespace std;

// 1. Using the std function 
float getMedian1(vector<int> input)
{
	int len = input.size();
	if (len % 2 == 1)
	{
		nth_element(input.begin(), input.begin() + len / 2, input.end());
		int mid = input[len / 2 - 1];
		return (float)mid;
	}
	else
	{
		nth_element(input.begin(), input.begin() + len / 2, input.end());
		nth_element(input.begin(), input.begin() + len/2 + 1, input.end());
		int mid1 = input[len / 2 - 1];
		int mid2 = input[len / 2];
		return 0.5 * (mid1 + mid2);
	}
}


// 2. Using quick selection

// divide the arrray into 3 parts
// [0, lower) - smaller than pivot
// [lower, equal) - equal to the pivot
// [equal, upper] - unknown area
// (upper, n-1} - larger than pivot
int getKthElement(vector<int> & nums, int lhs, int rhs, int k)
{
	if (lhs >= rhs) return nums[k - 1];
	int pivot = nums[lhs + (rhs - lhs) / 2];
	int lower = lhs, upper = rhs, equal = lhs;
	// similar to rainbowl sort
	while (equal <= upper)
	{
		if (nums[equal] < pivot)
		{
			swap(nums[lower++], nums[equal++]);
		}
		else if (nums[equal] == pivot)
		{
			equal++;
		}
		else
		{
			swap(nums[equal], nums[upper--]);
		}
	}

	if (k <= lower)
	{
		getKthElement(nums, 0, lower - 1, k);
	}
	else if (k >= upper)
	{
		getKthElement(nums, upper + 1, nums.size() - 1, k);
	}
	else return nums[k - 1];
}

float getMedian2(vector<int> input)
{
	if (input.size() % 2 == 1) return (float)getKthElement(input, 0, input.size() - 1, input.size() / 2);
	else
	{
		int mid1 = (float)getKthElement(input, 0, input.size() - 1, input.size()/2);
		int mid2 = (float)getKthElement(input, 0, input.size() - 1, input.size()/2 +1);
		return 0.5 *(mid1 + mid2);
	}
}




