/******************************************************************************
* Question: #103 Binary Tree Level Order Traversal
* company tag: Facebook, LinkedIn
* Given a binary tree, return the zigzag level order traversal of its nodes' values. 
* (ie, from left to right, then right to left for the next level and alternate between).
*****************************************************************************/

#include "BST.h"
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
{
	vector<vector<int>> results;
	if (root == NULL) return results;
	queue<TreeNode *> layer;
	layer.push(root);
	int k = 0;
	while (!layer.empty())
	{
		int layerLen = layer.size();
		vector<int> result;
		for (int i = 0; i < layerLen; i++)
		{
			TreeNode * curr = layer.front();
			layer.pop();
			result.push_back(curr->val);
			if (curr->left) layer.push(curr->left);
			if (curr->right) layer.push(curr->right);
		}
		if (k % 2 == 1) reverse(result.begin(), result.end());
		k++;
		results.push_back(result);
	}
	return results;
}

// use deque instead of vector so we do not need to reverse
vector<int> zigZag(TreeNode* root)
{
  if(!root) return {};
  vector<int> result;
  deque<TreeNode*> layer;
  layer.push_back(root);
  int k = 0;
  while(!layer.empty()){
    int layerSize = layer.size();
    int start = result.size();
    for(int i=0; i < layerSize; i++)
    {
      TreeNode* curr = NULL;
      if(k%2 == 0){
        curr = layer.back();
        layer.pop_back();
      }else{
        curr = layer.front();
        layer.pop_front();
      }
      result.push_back(curr->val);
      if(k%2 == 0){
        if(curr->right) layer.push_front(curr->right);
        if(curr->left) layer.push_front(curr->left);
      }
      else{
        if(curr->left) layer.push_back(curr->left);
        if(curr->right) layer.push_back(curr->right);
      }
    }
    k++;
  }
  return result;
}
