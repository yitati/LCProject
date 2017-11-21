/******************************************************************************
* Question: #99 Recover Binary Search Tree
* Two elements of a binary search tree (BST) are swapped by mistake.
* Recover the tree without changing its structure.
* Note:
* A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*****************************************************************************/

#include <vector>
#include "../Leetcode/BST.h"

using namespace std;
// helper function that will find all possible suspects
// arguments are current node and previous node
void findSuspects(TreeNode* curr, TreeNode*& prev, vector<pair<TreeNode*, TreeNode*>>& suspect)
{
    if(!curr) return;
    findSuspects(curr->left, prev, suspect);
    if(prev && prev->val > curr->val)
    {
        suspect.emplace_back(prev, curr);
    }
    prev = curr;
    findSuspects(curr->right, prev, suspect);
}
// there are 2 situations
// 1. two nodes are root-leaf relationship
// 2. two nodes are not root-leaf relationship but random nodes
void recoverTree(TreeNode* root)
{
    vector<pair<TreeNode*, TreeNode*>> suspect;
    if(!root) return;
    TreeNode* prev = NULL;
    findSuspects(root, prev, suspect);
    if(suspect.size() == 2)  // when there are two pairs messed up
    {
        swap(suspect[0].first->val, suspect[1].second->val);
    }
    else
    {
        swap(suspect[0].first->val, suspect[0].second->val);
    }
}
