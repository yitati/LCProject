/********************************************************************************
 * Question #545 Boundary Of Binary Tree
 * company tag: Facebook
 * Given a binary tree, return the values of its boundary in anti-clockwise direction
 * starting from root. Boundary includes left boundary, leaves, and right boundary in
 * order without duplicate nodes.
 * Left boundary is defined as the path from root to the left-most node. Right boundary
 * is defined as the path from root to the right-most node. If the root doesn't have left
 * subtree or right subtree, then the root itself is left boundary or right boundary.
 * Note this definition only applies to the input binary tree, and not applies to any
 * subtrees.
 * The left-most node is defined as a leaf node you could reach when you always firstly
 * travel to the left subtree if exists. If not, travel to the right subtree. Repeat until
 * you reach a leaf node.
 * The right-most node is also defined by the same way with left and right exchanged.

Example 1

Input:
  1
   \
    2
   / \
  3   4

Ouput:
[1, 3, 4, 2]

Explanation:
The root doesn't have left subtree, so the root itself is left boundary.
The leaves are node 3 and 4.
The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
So order them in anti-clockwise without duplicates and we have [1,3,4,2].



Example 2

Input:
    ____1_____
   /          \
  2            3
 / \          /
4   5        6
   / \      / \
  7   8    9  10

Ouput:
[1,2,4,7,8,9,10,6,3]

Explanation:
The left boundary are node 1,2,4. (4 is the left-most node according to definition)
The leaves are node 4,7,8,9,10.
The right boundary are node 1,3,6,10. (10 is the right-most node).
So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].

 ********************************************************************************/

#include "BST.h"
#include <vector>

using namespace std;

/*
 *    Use two flags to indicate if current node is left boundary or right boundary.
 *    1. for left boundary node, we do pre-order : check node then left and right.
 *    2. for right boundary node, we do post-order :  check its left and right child, then itself.
 *    3. for left bound, its left child will naturally be left boundary; if left child does not
 *    exist, its right child will be left boundary
 *    4. same thing for right bound.
 *    5. for leaf node which is not left bound or right bound, will be leaf node.
 */
void getBound(TreeNode* node, vector<int>& bound, bool lb, bool rb)
{
	if (!node) return;
	if (lb) bound.push_back(node->val);
	if (!lb && !rb && !node->left && !node->right) bound.push_back(node->val);
	getBound(node->left, bound, lb, rb & (!node->right));
	getBound(node->right, bound, lb & (!node->left), rb);
	if (rb) bound.push_back(node->val);
}

vector<int> boundaryOfBinaryTree(TreeNode* root)
{
	vector<int> bound;
	if (!root) return bound;
	bound.push_back(root->val);
	getBound(root->left, bound, true, false);
	getBound(root->right, bound, false, true);
	return bound;
}



