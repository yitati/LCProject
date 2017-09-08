/*
 * Laicode_LowestCommonAncestorIII.cpp
 *

Given two nodes in a binary tree, find their lowest common ancestor
(the given two nodes are not guaranteed to be in the binary tree).

Return null If any of the nodes is not in the tree.

Assumptions

There is no parent pointer for the nodes in the binary tree

The given two nodes are not guaranteed to be in the binary tree

Examples

        5

      /   \

     9     12

   /  \      \

  2    3      14

The lowest common ancestor of 2 and 14 is 5

The lowest common ancestor of 2 and 9 is 9

The lowest common ancestor of 2 and 8 is null (8 is not in the tree)

 */

/*
 * consider how many situationtions we could have, we can have two bool flags to indecate
 * if one exists in the tree and if two exists in the tree, so the helper function would
 * looklike TreeNode* LCA(TreeNode* root, TreeNode* one, TreeNode* two, bool exist1, bool eists2)
 *
 *
 */

#include "../LCProject/BST.h"

using namespace std;

// solution 1 - check existence and LCA in one loop
TreeNode* lcaWithExist(TreeNode* root, TreeNode* one, TreeNode* two, bool & exist1, bool & exist2)
{
	if(!root) return NULL;
	// first search through the tree
	TreeNode* leftLca = lcaWithExist(root->left, one, two, exist1, exist2);
	TreeNode* rightLca = lcaWithExist(root->right, one, two, exist1, exist2);
	if(leftLca && rightLca) return root; // both nodes exists
	else // at least one exists
	{
		if(root == one)
		{
			exist1 = true;
			return root;
		}
		else if(root == two)
		{
			exist2 = true;
			return root;
		}
		else return leftLca ? leftLca : rightLca;
	}
}

TreeNode* solve(TreeNode* root, TreeNode* one, TreeNode* two)
{
	bool exist1 = false;
	bool exist2 = false;
	TreeNode* lca = lcaWithExist(root, one, two, exist1, exist2);
	if(!exist1 || !exist2) return NULL;
	return lca;
}

// solution 2 - check LCA and then check existence

/*
 * check LCA
 */
TreeNode* getLca(TreeNode* root, TreeNode* one, TreeNode* two)
{
	if(root == NULL || root == one || root == two) return root;
	TreeNode* leftLca = getLca(root->left, one, two);
	TreeNode* rightLca = getLca(root->right, one, two);
	if(leftLca && rightLca) return root;
	return leftLca ? leftLca : rightLca;
}

bool exist(TreeNode* root, TreeNode* node)
{
	if(!root) return false;
	if(root == node) return true;
	if(exist(root->left, node)) return true;
	return exist(root->right, node);
}

TreeNode* solve2(TreeNode* root, TreeNode* one, TreeNode* two)
{
	TreeNode* lca = getLca(root, one, two);
	if(lca != one && lca != two) return lca;
	else if(lca == one)
	{
		if(exist(one, two)) return one;
	}
	else if(lca == two)
	{
		if(exist(two, one)) return two;
	}
	return NULL;
}




