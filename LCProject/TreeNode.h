#pragma once

#ifndef TREENODE_H
#define TREENODE_H

#include<cstdlib>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



#endif