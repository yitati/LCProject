#include <vector>
#include <iostream>

using namespace std;

// three areas 
// [0, i) - all elements smaller than pivot
// [i, j) - unknow area
// [j, rhs] - all elements greater or equal to pivot

void QuickSort(vector<int> & nums, int lhs, int rhs)
{
	// first check if lhs == rhs
	if (lhs == rhs) return;
	int mid = lhs + (rhs - lhs) / 2;
	int pivot = nums[mid];
	int lower = lhs, upper = rhs - 1;

	// pivot now in the rhs 
	swap(nums[mid], nums[rhs]);

	while (lower <= upper)
	{
		if (nums[lower] < pivot) lower++;
		else if (nums[upper] >= pivot) upper--;
		else {
			swap(nums[lower], nums[upper]);
			lower++;
			upper--;
		}
	}

	// now lhs <= upper < lower <= rhs

	// swap back pivot
	swap(nums[lower], nums[rhs]);
	
	if(lhs < upper) QuickSort(nums, lhs, upper);
	if(lower < rhs) QuickSort(nums, lower + 1, rhs);
}

// Rainbow style has better performance especially when there is duplicates
// use rainbow sort idea, finally got 3 areas
// [0, i) - all < pivot
// [i, j] - all == pivot
//   - [i, k) - known == pivot
//   - [k, j] - unkown area, to be checked
// (j, n-1] - all > pivot
void QuickSortRainbow(vector<int> & nums, int lhs, int rhs)
{
	if (lhs == rhs) return;
	int n = nums.size();
	int mid = lhs + (rhs - lhs) / 2;
	int pivot = nums[mid];
	int i = lhs, j = rhs, k = lhs;
	while (k <= j)
	{
		if (nums[k] < pivot)
		{
			swap(nums[k++], nums[i++]);
		}
		else if (nums[k] > pivot)
		{
			swap(nums[k], nums[j--]);
		}
		else
		{
			k++;
		}
	}
	// while loop end - lhs <= i < j <=rhs
	if (lhs < i) QuickSortRainbow(nums, lhs, i-1);
	if (j < rhs) QuickSortRainbow(nums, j+1, rhs);
}

/*
int main(int argc, char* argv)
{
	int i;
	vector<int> nums;
	nums.push_back(7);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(8);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(6);

	int n = nums.size();
	//QuickSort(nums, 0, n-1);
	QuickSortRainbow(nums, 0, n - 1);
    
	for (i=0; i < n; i++)
	{
		cout << nums[i] << endl;
	}

	system("pause");
}
*/
