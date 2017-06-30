/******************************************************************************/
/*
* Question: #42 Trapping Rain Water
* Given n non-negative integers representing an elevation map where the width of each bar is 1, 
* compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*/
/*****************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// First of all, the water can be trapped is depending on max height from left of the point (inclusively) 
// and max height right of the point (inclusively) and potential trapped water volume is min(leftMax, rightMax) - x
// Then this problem turns into the question to look for the leftMax and rightMax of every point

int trap_twoMaxArray(vector<int>& height) 
{
	int n = height.size();
	if (n == 0 || n == 1) return 0;

	vector<int> leftMax(n, 0);
	vector<int> rightMax(n, 0);
	int i;
	int sum = 0;

	leftMax[0] = height[0];
	rightMax[n - 1] = height[n - 1];

	for (i = 1; i < n - 1; i++)
	{
		leftMax[i] = max(leftMax[i - 1], height[i]);
	}

	for (i = n - 2; i > 0; i--)
	{
		rightMax[i] = max(rightMax[i + 1], height[i]);
	}

	for (i = 1; i < n - 1; i++)
	{
		sum += min(leftMax[i], rightMax[i]) - height[i];
	}

	return sum;
}

// to optimize the above solution, what we need is not maxLeft or maxRight, but the min value between them
// so here is one idea - we want to update the min value of both, to move it left or right so the min value can update
// and here is the solution

int trap_updateShorterHeight(vector<int>& height)
{
	int n = height.size();
	if (n == 0 || n == 1) return 0;

	int lhs = 0, rhs = n - 1;
	int leftMax = 0, rightMax = 0;
	int sum = 0;

	while (lhs <= rhs)
	{
		leftMax = max(leftMax, height[lhs]);
		rightMax = max(rightMax, height[rhs]);
		if (leftMax < rightMax) // move lhs to left
		{
			sum += min(leftMax, rightMax) - height[lhs];
			lhs++;
		}
		else
		{
			sum += min(leftMax, rightMax) - height[rhs];
			rhs--;
		}
	}
	return sum;
}

/*
int main(int argc, char * * argv)
{
	int input[] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	vector<int> nums(input, input + sizeof(input) / sizeof(int));

	cout << trap_updateShorterHeight(nums) << endl;

	system("pause");
}
*/