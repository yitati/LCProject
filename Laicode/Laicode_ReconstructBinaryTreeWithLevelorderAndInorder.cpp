/*
 * Laicode_ReconstructBinaryTreeWithLevelorderAndInorder.cpp

Given the levelorder and inorder traversal sequence of a binary tree, reconstruct the original tree.

Assumptions

The given sequences are not null and they have the same length
There are no duplicate keys in the binary tree

Examples

levelorder traversal = {5, 3, 8, 1, 4, 11}

inorder traversal = {1, 3, 4, 5, 8, 11}

the corresponding binary tree is

        5

      /    \

    3        8

  /   \        \

1      4        11

 */


/*
 * the problem for tree is always using recursions
 * 1. we need to decide which part need to be handle at current layer
 * 2. we need to decide which part to be handled in left / right branch
 *
 * For the level, it is mixed with left branch and right branch, so we want to find those two
 * corresponding parts, and divide them into two groups. And this is where we need the inorder
 * information.
 */

#include "BST.h"
#include <vector>
#include <unordered_map>

using namespace std;

TreeNode* buildTreeWithLevelAndInorder(const vector<int>& level,
		                               unordered_map<int, int>& indexMap)
{
	if(level.empty()) return NULL;

	int nodeVal = level[0];
	int idx = indexMap[nodeVal];
	vector<int> left;
	vector<int> right;
	// start from 1
	for(int i=1; i<level.size(); i++){
		if(indexMap[level[i]] < idx) left.push_back(level[i]);
		else if(indexMap[level[i]] > idx) right.push_back(level[i]);
	}

	TreeNode* node = new TreeNode(nodeVal);
	node->left = buildTreeWithLevelAndInorder(left, indexMap);
	node->right = buildTreeWithLevelAndInorder(right, indexMap);

	return node;
}

TreeNode* reconstructWithLevelAndInorder(vector<int> in, vector<int> level){
	// map inorder
	unordered_map<int, int> indexMap;
	for(int i=0; i<in.size(); i++){
		indexMap[in[i]] = i;
	}
	return buildTreeWithLevelAndInorder(level, indexMap);
}




