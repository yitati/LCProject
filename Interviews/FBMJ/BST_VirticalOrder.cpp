/*
 * BST_VirticalOrder.cpp
 *
 *  Created on: Oct 7, 2017
 *      Author: JoanneY1
 */

#include <vector>
#include <map>
#include <queue>
#include "../Leetcode/BST.h"

using namespace std;

/*
 * every tree node is attached with a degree assigned from parent node
 * left node degree = parent node degree - 1
 * right node degree = parent node degree + 1
 */
vector<vector<int>> verticalOrder(TreeNode* root)
{
  if(!root) return {};
  vector<vector<int>> results;

  map<int, vector<int>> orders;

  queue<pair<TreeNode*, int>> level;  // store the tree node and its degree
  level.push(make_pair(root, 0));

  while(!level.empty())
  {
    int levelSize = level.size();
    for(int i = 0; i < levelSize; i++)
    {
      auto curr = level.front();
      level.pop();
      orders[curr.second].push_back(curr.first->val);

      if(curr.first->left)
      {
        level.push(make_pair(curr.first->left, curr.second-1));
      }
      if(curr.first->right)
      {
        level.push(make_pair(curr.first->right, curr.second+1));
      }
    }
  }

  for(auto it = orders.begin(); it != orders.end(); it++)
  {
    results.push_back(it->second);
  }

  return results;
}


