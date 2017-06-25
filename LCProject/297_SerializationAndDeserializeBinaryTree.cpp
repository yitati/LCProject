/******************************************************************************/
/**
* Question: #297 Serialize And Deserialize Binary Tree
* Serialization is the process of converting a data structure or object into a 
* sequence of bits so that it can be stored in a file or memory buffer, 
* or transmitted across a network connection link to be reconstructed 
* later in the same or another computer environment.

* Design an algorithm to serialize and deserialize a binary tree. 
* There is no restriction on how your serialization/deserialization 
* algorithm should work. You just need to ensure that a binary tree 
* can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. 
You do not necessarily need to follow this format, so please be creative and come up 
with different approaches yourself.
Note: Do not use class member/global/static variables to store states. 
Your serialize and deserialize algorithms should be stateless.
/*****************************************************************************/

#include "BST.h"
#include <string>
#include <queue>
#include <cstring>

using namespace std;

// suppose every node must have left child and right child, they can be null or number
// if child is a number, then we decode with an '!' in front of it
// if child is NULL, then we decode with an '#' in front of it

// helper function that will store one int in a 4 byte char array
void addInttoStr(string & str, int val)
{
	int x = val;
	char buff[4];
	memcpy(buff, &x, sizeof(int));
	for (int i = 0; i < 4; i++) str += buff[i];
}

// helper function that will get one treenode from string
TreeNode * getNodeFromStr(string & data, int & pos)
{
	if (pos >= data.size()) return NULL;

	if (data[pos] == '#')
	{
		pos++;
		return NULL;
	}

	pos++;
	int val;
	char * buff = &data[pos];
	memcpy(&val, buff, sizeof(int));
	TreeNode * node = new TreeNode(val);
	pos += 4;
	return node;
}

string serialize(TreeNode * root) 
{
	if (root == NULL) return "";
	queue<TreeNode *> layer;
	string bfs;
	layer.push(root);

	while (!layer.empty())
	{
		int len = layer.size();
		for (int i = 0; i < len; i++)
		{
			TreeNode * curr = layer.front();
			layer.pop();

			if (!curr) bfs += '#';
			else
			{
				bfs += '!';
				addInttoStr(bfs, curr->val);
				layer.push(curr->left);
				layer.push(curr->right);
			}
		}
	}

	return bfs;

}



// Decodes your encoded data to tree.
TreeNode* deserialize(string data) 
{
	if (data.empty()) return NULL;
	queue<TreeNode *> layer;
	int pos = 0;
	TreeNode * root = getNodeFromStr(data, pos);
	if (root == NULL) return NULL;
	layer.push(root);
	

	while (pos < (int)data.size() && !layer.empty())
	{
		int len = layer.size();
		for (int i = 0; i < len; i++)
		{
			TreeNode * node = layer.front();
			layer.pop();
			node->left = getNodeFromStr(data, pos);
			node->right = getNodeFromStr(data, pos);
			if (node->left) layer.push(node->left);
			if (node->right) layer.push(node->right);
		}
	}

	return root;
}

/*
int main(int argc, char ** argv)
{
	string input1 = "5,3,2,4,9,10";

	// build a tree
	TreeNode * root = new TreeNode(5);
	TreeNode * node3 = new TreeNode(3);
	TreeNode * node2 = new TreeNode(2);
	TreeNode * node4 = new TreeNode(4);
	TreeNode * node9 = new TreeNode(9);
	TreeNode * node10 = new TreeNode(10);
	node3->left = node2;
	node3->right = node4;
	node9->right = node10;
	root->left = node3;
	root->right = node9;

	printPretty(root, 1, 0, cout);

	string x = serialize(root);

	cout << x << endl;

	TreeNode * node = deserialize(x);

	printPretty(node, 1, 0, cout);

	system("pause");
}
*/
