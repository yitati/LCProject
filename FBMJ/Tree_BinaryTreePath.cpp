/*
 * Tree_BinaryTreePath.cpp
 *
Given a binary tree, return all root-to-leaf paths.
 */

#include <vector>

using namespace std;

/*
 * TODO - discuss with BAOBAO about time complexity
 * http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=214582&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3046%5D%5Bvalue%5D%3D2%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311
 * time complexity should be O(n) which n is the total number of nodes inside this tree
 */
void fillBinaryPath(vector<string>& results, TreeNode* node, string result)
{
    if(!node->left && !node->right)
    {
        results.push_back(result);
        return;
    }

    if(node->left) fillBinaryPath(results, node->left, result + "->" + to_string(node->left->val));
    if(node->right) fillBinaryPath(results, node->right, result + "->" + to_string(node->right->val));
}

vector<string> binaryTreePaths(TreeNode* root)
{
    if(!root) return {};
    vector<string> results;
    string result = to_string(root->val);
    fillBinaryPath(results, root, result);
    return results;
}




