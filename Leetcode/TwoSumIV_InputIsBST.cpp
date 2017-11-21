/******************************************************************************
* Question: #653 Two Sum IV - Input is a BST
* company tag: Facebook
* Given a Binary Search Tree and a target number, return true if there exist two elements
* in the BST such that their sum is equal to the given target.

Example 1:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False

*****************************************************************************/

#include <unordered_set>
#include "../Leetcode/BST.h"

using namespace std;

/*
 * solution 1 : use a hashset, each time we insert a new element, check if target-node is already in the set
 * O(n) time and O(n) space
 */
bool findNode(unordered_set<int>& visited, TreeNode* root, int target)
{
	if(!root) return false;
	int comp = target - root->val;
	if(visited.count(comp)) return true;
	visited.insert(root->val);
	return findNode(visited, root->left, target) || findNode(visited, root->right, target);
}

bool findTarget1(TreeNode* root, int k)
{
	unordered_set<int> visited;
	return findNode(visited, root, k);
}

/*
 * solution 2: use a vector to save all the numbers in the tree with inorder traversal, then use two pointers
 * O(n) time, O(n) space
 */
void inorder(vector<int>& order, TreeNode* root)
{
    if(!root) return;
    inorder(order, root->left);
    order.push_back(root->val);
    //cout << root->val << "  ";
    inorder(order, root->right);
}

bool findTarget2(TreeNode* root, int k)
{
    vector<int> order;
    inorder(order, root);
    int lhs = 0, rhs = order.size()-1;
    while(lhs < rhs)
    {
        int sum = order[lhs] + order[rhs];
        if(sum == k) return true;
        else if(sum < k) lhs++;
        else rhs--;
    }
    return false;
}

/*
 * solution 3: for every node, we check if target - node->val exists in the map
 * time complexity is O(nlogn) and space complexity is O(h) h is the depth of the tree
 */
// every time search from the root
bool search(TreeNode* root, TreeNode* curr, int value)
{
    if(!root) return false;
    if(value == root->val) return root != curr;
    else if(value < root->val) return search(root->left, curr, value);
    else return search(root->right, curr, value);
}

bool dfs(TreeNode* root, TreeNode* curr, int target)
{
    if(!curr) return false;
    return search(root, curr, target-root->val) || dfs(root, curr->left, target) || dfs(root, curr->right, target);
}

bool findTarget3(TreeNode* root, int k)
{
    return dfs(root, root, k);
}

