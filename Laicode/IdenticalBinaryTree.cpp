/*
 * Laicode_IdenticalBinaryTree.cpp
 *

Check if two given binary trees are identical. Identical means the equal valued keys are at the same position
in the two binary trees.

Examples



        5

      /    \

    3        8

and

        5

      /    \

    3        8

are identical trees.

 */

#include "../LCProject/BST.h"

bool isIdentical(TreeNode* r1, TreeNode* r2)
{
	if(!r1 && !r2) return true;
	else if(!r1 || !r2) return false;
	if(r1->val != r2->val) return false;
	return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
}


