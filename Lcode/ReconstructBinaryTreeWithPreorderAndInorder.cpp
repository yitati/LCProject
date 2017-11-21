/*
 * Laicode_ReconstructBinaryTreeWithPreorderAndInorder.cpp

Given the preorder and inorder traversal sequence of a binary tree, reconstruct the original tree.

Assumptions

The given sequences are not null and they have the same length
There are no duplicate keys in the binary tree
Examples

preorder traversal = {5, 3, 1, 4, 8, 11}

inorder traversal = {1, 3, 4, 5, 8, 11}

the corresponding binary tree is

        5

      /    \

    3        8

  /   \        \

1      4        11

 */

#include <vector>
#include <unordered_map>
#include "../Leetcode/BST.h"

using namespace std;
/*
 *  first element in preorder shoudl be the root node, and in inorder we can find its left branch and
 *  right branch
 */

TreeNode* reconstructFromInAndPre(const vector<int>& in, const vector<int>& pre,
		                          const unordered_map<int, int>&indexMap,
								  int istart, int iend, int pstart, int pend){
	if(istart > iend) return NULL;

	int nodeVal = pre[pstart];
	auto it = indexMap.find(nodeVal);
	int i = it->second;

	TreeNode* node = new TreeNode(nodeVal);

	node->left = reconstructFromInAndPre(in, pre, indexMap, istart, i-1, pstart+1, pstart + i-istart);
	node->right = reconstructFromInAndPre(in, pre, indexMap, i+1, iend, pstart+i-istart+1, pend);
	return node;
}

TreeNode* reconstruct(vector<int> in, vector<int> pre){
	if(in.empty() || pre.empty() || in.size() != pre.size()) return NULL;
	unordered_map<int, int> indexMap;
	for(int i=0; i<in.size(); i++){
		indexMap[pre[i]] = i;
	}
	return reconstructFromInAndPre(in, pre, indexMap, 0, in.size()-1, 0, pre.size()-1);
}



