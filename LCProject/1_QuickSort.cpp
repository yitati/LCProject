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
	QuickSort(nums, 0, n-1);
    
	for (i=0; i < n; i++)
	{
		cout << nums[i] << endl;
	}

	system("pause");
}
*/