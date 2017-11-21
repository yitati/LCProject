/******************************************************************************/
/*
* Question: #108 Convert Sorted Array to Binary Search Tree
* Given an array where elements are sorted in ascending order, convert it to a heigh balanced BST.
*/
/*****************************************************************************/

#include <vector>
#include "../Leetcode/BST.h"

using namespace std;

// build tree from start to end
TreeNode * buildTreeFromArray(vector<int> & nums, int start, int end)
{
	if (start > end) return NULL;
	int mid = start + (end - start) / 2;
	TreeNode * root = new TreeNode(nums[mid]);
	root->left = buildTreeFromArray(nums, start, mid - 1);
	root->right = buildTreeFromArray(nums, mid + 1, end);
	return root;
}


TreeNode* sortedArrayToBST(vector<int>& nums) {
	return buildTreeFromArray(nums, 0, nums.size() - 1);
}

/*
int main(int argc, char ** argv)
{
	
	int input[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> num1(0);
	vector<int> nums2(1, 0);
	vector<int>nums3(input, input+sizeof(input) / sizeof(int));

	TreeNode * root = sortedArrayToBST(nums3);

	printPretty(root, 1, 0, cout);

	system("pause");
}
*/


