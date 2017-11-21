/*
 * TreeNodeDistance.cpp
 *
construct BST 后找俩node之间distance

Given a list of unique integers, construct the binary tree by given order without rebalancing,
then find out the distance between two nodes.

public static int bstDistance(int[] values, int n, int node1, int node2)

for example,

values= [5,6,3,1,2,4], n is the size of values, node1 is 2, node2 is 4, then function return 3
构建完BST如下，2和4呢，距离就是3
      5
   3      6
1     4
   2
 */

#include <climits>
#include "../../Leetcode/BST.h"

using namespace std;

/*
 * step 1 : construct the tree
 */

// helper function that will insert one node to the current tree
TreeNode* insertToTree(TreeNode* root, int x)
{
	if(root == NULL)
	{
		root = new TreeNode(x);
		return root;
	}
	else
	{
		if(x < root->val) root->left = insertToTree(root->left, x);
		else root->right = insertToTree(root->right, x);
	}
	return root;
}

TreeNode* buildBinarySearchTree(int* values, int n)
{
	TreeNode* root = NULL;
	for(int i=0; i<n; i++)
	{
		root = insertToTree(root, values[i]);
	}
	return root;
}

/*
 * step 2 : find the common ancestor of two nodes
 */
TreeNode* findLca(TreeNode* root, int x1, int x2)
{
	if(root == NULL || root->val == x1 || root->val == x2) return root;
	TreeNode* leftNode = findLca(root->left, x1, x2);
	TreeNode* rightNode = findLca(root->right, x1, x2);
	if(leftNode && rightNode) return root;
	else return leftNode ? leftNode : rightNode;
}

/*
 * step 3 : find the distance from lca to node1 and node2 and return sum
 */
int getDist(TreeNode* root, int x)
{
	if(!root) return INT_MAX;
	if(root->val == x) return 0;
	return min(getDist(root->left, x), getDist(root->right, x)) + 1;
}

int bstDistance(int* values, int n, int node1, int node2)
{
	TreeNode* root = buildBinarySearchTree(values, n);
	TreeNode* lca = findLca(root, node1, node2);
	return getDist(root, node1) + getDist(root, node2);
}





