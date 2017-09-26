/*
 * LCAFor2NodesInKnaryTree.cpp
 *
 *  Created on: Sep 23, 2017
 *      Author: JoanneY1
 */

#ifdef KNARYTREE

TreeNode* LCAKnary(TreeNode* root, TreeNode* a, TreeNode* b)
{
	if(root == NULL || root == a || root == b) return root;

	int counter = 0;
	TreeNode* tmp = NULL;
	for(TreeNode* child : root->children)
	{
		TreeNode* node = LCAKnary(child, a, b);
		if(node != NULL)
		{
			counter++;
			if(counter == 2) return root;
			tmp = node;
		}
	}

	return tmp;
}


#endif
