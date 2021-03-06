/******************************************************************************
* Question: #449 Serialize And Deserialize BST
* company tag: Facebook
* Serialization is the process of converting a data structure or object into a sequence of bits 
* so that it can be stored in a file or memory buffer, or transmitted across a network connection 
* link to be reconstructed later in the same or another computer environment.

* Design an algorithm to serialize and deserialize a binary search tree. 
* There is no restriction on how your serialization/deserialization algorithm should work. 
* You just need to ensure that a binary search tree can be serialized to a string and 
* this string can be deserialized to the original tree structure.

* The encoded string should be as compact as possible.

* Note: Do not use class member/global/static variables to store states. 
* Your serialize and deserialize algorithms should be stateless.
*****************************************************************************/

#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include "../Leetcode/BST.h"

using namespace std;

// one int has 4 bytes while one char has 1 byte
// so for each int in the tree values, we will take 4 chars to store the value

void serializeBST_dfs(TreeNode * root, string & preorder)
{
	if (root == NULL) return;
	char buff[4];
	memcpy(buff, &(root->val), 4);
	for (int i = 0; i < 4; i++) preorder += buff[i];
	if (root->left) serializeBST_dfs(root->left, preorder);
	if (root->right) serializeBST_dfs(root->right, preorder);
}


// Encodes a tree to a single string.
// using preorder to flaten the tree
string serializeBST(TreeNode* root)
{
	string preorder = "";
	serializeBST_dfs(root, preorder);
	return preorder;
}

TreeNode * buildBSTFromPreorderStr(string & preorder, int& pos, int minVal, int maxVal)
{
	if ((unsigned int)pos >= preorder.size()) return NULL;

	int curr = 0;
	char* buf = &preorder[pos];
	memcpy(&curr, buf, sizeof(int));

	if (curr > maxVal || curr < minVal) return NULL;
	TreeNode * node = new TreeNode(curr);
	pos += 4;
	node->left = buildBSTFromPreorderStr(preorder, pos, minVal, curr);
	node->right = buildBSTFromPreorderStr(preorder, pos, curr, maxVal);

	return node;
}

// Decodes your encoded data to tree.
TreeNode* deserializeBST(string data)
{
	int pos = 0;
	TreeNode * root = buildBSTFromPreorderStr(data, pos, INT_MIN, INT_MAX);
	return root;
}


/*********************************************************************************************************************
if we need to serialize and deserialize to a vector of int instead of string, then how should we do this?
**********************************************************************************************************************/

// serialization is simply a preorder traversal
void serializeBST2(TreeNode* root, vector<int>& preorder)
{
	if(!root) return;
	preorder.push_back(root->val);
	serializeBST2(root->left, preorder);
	serializeBST2(root->right, preorder);
}

// deserialization
TreeNode* deserializeTree(const vector<int>& preorder, int& pos, int upper)
{
	if(pos >= preorder.size()) return NULL;
	int data = preorder[pos];
	if(data >= upper) return NULL;
	TreeNode* newNode = new TreeNode(data);
	pos++;
	newNode->left = deserializeTree(preorder, pos, data);
	newNode->right = deserializeTree(preorder, pos, upper);

	return newNode;
}


TreeNode* reconstruct(vector<int> pre)
{
	int upper = INT_MAX;
	int pos = 0;
	return deserializeTree(pre, pos, INT_MAX);
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

	string x = serializeBST(root);

	cout << x << endl;

	TreeNode * node = deserializeBST(x);

	printPretty(node, 1, 0, cout);

	system("pause");
}
*/





