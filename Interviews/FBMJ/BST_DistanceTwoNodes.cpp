#include <climits>
#include "../Leetcode/BST.h"

using namespace std;

/*
find the length of shortest path between two nodes in a tree
Find distance between two given keys of a Binary Tree, no parent pointers are given.
Distance between two nodes is the minimum number of edges to be traversed to reach one node from other.
*/

// find the lowest common ancestor of both nodes in the tree
TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q)
{
  if(!root || root == p || root == q) return root;
  TreeNode* leftLca = lca(root->left, p, q);
  TreeNode* rightLca = lca(root->right, p, q);
  if(leftLca && rightLca) return root;
  return leftLca ? leftLca : rightLca;
}

// find distance from root to node
int getDist(TreeNode* anc, TreeNode* node)
{
  if(!anc) return INT_MAX;
  if(anc == node) return 0;
  return min(getDist(anc->left, node), getDist(anc->right, node)) + 1;
}

int shortestDistBetweenTwoNodes(TreeNode* root, TreeNode* p, TreeNode* q)
{
  TreeNode* anc = lca(root, p, q);
  if(!anc) return INT_MAX;
  else return getDist(anc, p) + getDist(anc, q);
}




