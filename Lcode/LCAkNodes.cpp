/*
 * Laicode_LCAkNodes.cpp
Given K nodes in a binary tree, find their lowest common ancestor.

Assumptions

K >= 2

There is no parent pointer for the nodes in the binary tree

The given K nodes are guaranteed to be in the binary tree

Examples

        5

      /   \

     9     12

   /  \      \

  2    3      14

The lowest common ancestor of 2, 3, 14 is 5

The lowest common ancestor of 2, 3, 9 is 9
 */

#include <vector>
#include <unordered_set>
#include "../Leetcode/BST.h"

using namespace std;

TreeNode* genericLCA(TreeNode* root, unordered_set<TreeNode*>& nodes){
	// if root inside nodes set
	if(!root || nodes.count(root)) return root;

	TreeNode* left = genericLCA(root, nodes);
	TreeNode* right = genericLCA(root, nodes);

	if(left && right) return root;

	return left ? left : root;
}


TreeNode* getLCAKNodes(TreeNode* root, vector<TreeNode*> nodes)
{
	// input is vector, parse it to an unordered_set
	unordered_set<TreeNode*> nodeSet(nodes.begin(), nodes.end());
	return genericLCA(root, nodeSet);
}

/*
 * LCA of two nodes in k-naryTree
 */

class KnaryTreeNode{
public:
	int val;
	vector<KnaryTreeNode*> children;
};

/*
 * search through all child and there could be only 2 situations:
 * 1. there are 2 child satisfy the condition - then return root
 * 2. there is only 1 child satisfy the condition - then return this child
 */
KnaryTreeNode* getLCAKnaryTree(KnaryTreeNode * root, KnaryTreeNode * a, KnaryTreeNode *b){
	if(!root || !a || !b) return root;
	int count = 0;
	KnaryTreeNode* tmp = NULL;
	for(auto child : root->children){
		KnaryTreeNode* node = getLCAKnaryTree(child, a, b);
		if(node != NULL){
			count++;
			if(count == 2) return root;
			tmp = node;
		}
	}
	return tmp;
}
