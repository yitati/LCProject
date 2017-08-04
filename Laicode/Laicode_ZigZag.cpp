/*
 * Laicode_ZigZag.cpp
Get the list of keys in a given binary tree layer by layer in zig-zag order.

Examples

        5

      /    \

    3        8

  /   \        \

 1     4        11

the result is [5, 3, 8, 11, 4, 1]

Corner Cases

What if the binary tree is null? Return an empty list in this case.
How is the binary tree represented?

We use the level order traversal sequence with a special symbol "#" denoting the null node.

For Example:

The sequence [1, 2, 3, #, #, 4] represents the following binary tree:

    1

  /   \

 2     3

      /

    4
*/

#include "BST.h"
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> zigZag(TreeNode* root) {
	if (!root)
		return {};
	vector<int> result;
	deque<TreeNode*> layer;
	layer.push_back(root);
	int k = 0;
	while (!layer.empty()) {
		int layerSize = layer.size();
		int start = result.size();
		for (int i = 0; i < layerSize; i++) {
			TreeNode* curr = NULL;
			if (k % 2 == 0) {
				curr = layer.back();
				layer.pop_back();
			} else {
				curr = layer.front();
				layer.pop_front();
			}
			result.push_back(curr->val);
			if (k % 2 == 0) {
				if (curr->right)
					layer.push_front(curr->right);
				if (curr->left)
					layer.push_front(curr->left);
			} else {
				if (curr->left)
					layer.push_back(curr->left);
				if (curr->right)
					layer.push_back(curr->right);
			}
		}
		k++;
	}
	return result;
}
