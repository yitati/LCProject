/******************************************************************************
* Question: #75 Sort Colors
* company tag: Facebook
* Given an array with n objects colored red, white or blue, sort them so that objects of the same color are
* adjacent, with the colors in the order red, white and blue.
* Here, we will use the integers 0, 1 and 2 to represent the color red, white, and blue respectively.
* Note:
* You are not suppose to use the library's sort function for this problem.
*****************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// three way part
// [0, i) - 0
// [i, k) - 1
// [k, j] - unknown
// (j, n-1) - 2
void sortColors(vector<int>& nums) 
{
	int n = nums.size();
	int i = 0, j = n - 1, k = 0;
	while (k <= j)
	{
		if (nums[k] == 0)
		{
			swap(nums[k++], nums[i++]);
		}
		else if (nums[k] == 2) 
		{
			swap(nums[k], nums[j--]);
		}
		else 
		{
			k++;
		}
	}
}

/*
void main(int argc, char ** argv)
{
	vector<int> input(3);
	input[0] = 1;
	input[1] = 0;
	input[2] = 2;
	sortColors(input);
	for (int i = 0; i < 3; i++)
	{
		cout << input[i] << "   ";
	}
	cout << endl;
	system("pause");
}
*/
