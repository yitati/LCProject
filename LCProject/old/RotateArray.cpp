/******************************************************************************/
/**
* Question: #189 Rotate Array
* Rotate an array of n elements to the right by k steps.
* For example, with n=7 and k=3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]
*
* Note:
* Try to come up as many solutions as you can, there are at least 3 different ways to solve
* this problem.
*
/*****************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class RotateArray {
public:
	// get a copy of the string
	void rotate1(vector<int>& nums, int k)
	{
		int i;
		int n = nums.size();
		if ((n == 0) || (k <= 0))
		{
			return;
		}
		// make a copy
		vector<int> numsCopy(n);
		for (i = 0; i < n; i++)
		{
			numsCopy[i] = nums[i];
		}
		// rotate element
		for (i = 0; i < n; i++)
		{
			nums[(i + k) % n] = numsCopy[i];
		}
	}

	// reverse until the array is done
	void rotate2(vector<int> nums, int k)
	{
		if (nums.empty()) return;
		k = k%nums.size();
		if (k == 0) return;

		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin()+k, nums.end());
	}
};

/*
int main(int argc, char * argv)
{
	RotateArray s;
	int i;
	vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
	int n = nums.size();
	s.rotate1(nums, 3);
	for (i = 0; i < n; i++)
	{
		cout << nums[i] << ' ';
	}
	cout << endl;
	system("pause");

	return 0;
}
*/