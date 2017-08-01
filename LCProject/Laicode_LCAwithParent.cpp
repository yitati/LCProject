/*
 * Laicode_LCAwithParent.cpp
 *
Given two nodes in a binary tree (with parent pointer available), find their lowest common ancestor.

Assumptions

There is parent pointer for the nodes in the binary tree

The given two nodes are not guaranteed to be in the binary tree

Examples

        5

      /   \

     9     12

   /  \      \

  2    3      14

The lowest common ancestor of 2 and 14 is 5

The lowest common ancestor of 2 and 9 is 9

The lowest common ancestor of 2 and 8 is null (8 is not in the tree)

 */

#include <cstdlib>

class TreeNodeP{
public:
	int value;
	TreeNodeP * left;
	TreeNodeP * right;
	TreeNodeP * parent;
	TreeNodeP(int v, TreeNodeP* p): value(v), left(NULL), right(NULL), parent(p){}
};


int getHeight(TreeNodeP* node){
	 int height = 1;
	 while(node){
		 node = node->parent;
		 height++;
	 }
	 return height;
}

TreeNodeP * getLCA(TreeNodeP* one, TreeNodeP* two){
	// first get height of both nodes
	int height1 = getHeight(one);
	int height2 = getHeight(two);
	int diff = abs(height1-height2);
	// move two nodes to the same level
	if(height1 > height2){
		while(diff){
			one = one->parent;
			diff--;
		}
	}
	else {
		while(diff){
			two = two->parent;
			diff--;
		}
	}
	// find their LCA
	while(one != two){
		one = one->parent;
		two = two->parent;
	}
	return one;
}




