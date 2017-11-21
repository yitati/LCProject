/***********************************************************************************************
 * Question #536 Construct Binary Tree FromString
 * company tag: Facebook
 * You need to construct a binary tree from a string consisting of parenthesis and integers.
 * The whole input represents a binary tree. It contains an integer followed by zero, one or
 * two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis
 * a child binary tree with the same structure.
 * You always start to construct the left child node of the parent first if it exists.

Example:
Input: "4(2(3)(1))(6(5))"
Output: return the tree root node representing the following tree:

       4
     /   \
    2     6
   / \   /
  3   1 5

 * Note:
 * There will only be '(', ')', '-' and '0' ~ '9' in the input string.
 * An empty tree is represented by "" instead of "()".
 ************************************************************************************************/

#include <string>
#include "../Leetcode/BST.h"

using namespace std;

TreeNode* getTree(string& s, int & pos)
{
	if(s.empty() || pos >= s.length()) return NULL;
	int sign = 1, num = 0;
	if(s[pos] == '-')
	{
		sign = -1;
		pos++;
	}
	while(pos < s.length() && s[pos] >= '0' && s[pos] <= '9')
	{
		num = 10*num + s[pos++]-'0';
	}

	TreeNode* newRoot = new TreeNode(sign*num);
	if(pos < s.length() && s[pos] == '(')
	{
	    newRoot->left = getTree(s, ++pos);
	    pos++; // skip the ')'
	}
	if(pos < s.length() && s[pos] == '(')
	{
	    newRoot->right = getTree(s, ++pos);
	    pos++; // skip the ')'
	}
	return newRoot;
}

TreeNode* str2tree(string s)
{
	int pos = 0;
	return getTree(s, pos);
}



