#pragma once

#ifndef TREENODE_H
#define TREENODE_H

#include <fstream>
#include <iostream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// the max height of a tree
int BSTHeight(TreeNode * root);
// helper funtion to find an integer value to string
string IntToString(int data);
// Print the arm branches (eg, /    \ ) on a line
void BSTPrintBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<TreeNode*>& nodesQueue, ostream & out);
// Print the branches and node (eg, ___10___ )
void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<TreeNode*>& nodesQueue, ostream & out);
// Print the leaves only (just for the bottom row)
void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<TreeNode*>& nodesQueue, ostream & out);
// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)
void printPretty(TreeNode * root, int level, int indentSpace, ostream & out);



#endif