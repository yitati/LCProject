/******************************************************************************/
/*
* Question: #45 Jump Game II
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
* Each element in the array represents your maximum jump length at that position.
* Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.

*/
/*****************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// the idea is to use dfs and update the minJump from every possible path
int jump(vector<int>& nums) 
{

	return 0;
}

/*
int main(int argc, char * * argv)
{
	//int input[] = { 2,3,1,1,4 }; // true
	int input[] = { 0 }; // true
	vector<int> nums(input, input + sizeof(input) / sizeof(int));

	cout << jump(nums) << endl;

	system("pause");
}
*/

