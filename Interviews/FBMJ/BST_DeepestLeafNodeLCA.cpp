/*
 * BST_DeepestLeafNodeLCA.cpp
 *
// find LCA of all deepest leaves in a tree(can be a multiway tree)
 * http://www.elvisyu.com/%E5%8F%98%E7%A7%8Dlca-%E6%B1%82%E4%B8%80%E6%A3%B5%E6%A0%91%E7%9A%84%E6%9C%80%E6%B7%B1%E5%8F%B6%E5%AD%90%E8%8A%82%E7%82%B9%E7%9A%84%E5%85%AC%E5%85%B1%E7%88%B6%E8%8A%82%E7%82%B9/
 */


#include "../Leetcode/BST.h"

pair<KTreeNode*, int>deepestLeafLCA(KTreeNode* root) {
	if (!root) return { root, 0 };
	if (root->children.empty()) return { root, 1 };

	int maxDepth = 0, cnt = 0;
	KTreeNode* candidateLCA = NULL;
	for (auto child : root->children) {
		pair<KTreeNode*, int> tmp = deepestLeafLCA(child);
		if (tmp.second > maxDepth) {
			maxDepth = tmp.second;
			cnt = 1;
			candidateLCA = tmp.first;
		} else if (tmp.second == maxDepth) {
			cnt++;
		}
	}

	if (cnt > 1) {
		return { root, maxDepth + 1 };
	} else if (cnt == 1) {
		return { candidateLCA, maxDepth + 1 };
	} else {
		return { NULL, maxDepth + 1 };
	}
}

KTreeNode* deepestLCAKnaryTree(KTreeNode* root) {
	return deepestLeafLCA(root).first;
}


/*
 * if we need to find the deepest leaf nodes LCA for binary tree, it is simplier
 */
pair<TreeNode*, int> deepestLcaBtWithDepth(TreeNode* root)
{
	if(!root) return {root, 0};

	auto ldp = deepestLcaBtWithDepth(root->left);
	auto rdp = deepestLcaBtWithDepth(root->right);
	if(ldp.second == rdp.second)
	{
		return {root, ldp+1};
	}
	else if(ldp.second > rdp.second)
	{
		return {ldp.first, ldp.second+1};
	}
	else return {rdp.first, rdp.second+1};
}

TreeNode* deepestLcaBt(TreeNode* root)
{
	return deepestLcaBtWithDepth(root).first;
}
