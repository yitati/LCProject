/*
 * EMBJ_ExpressionTree.cpp
 *
http://www.geeksforgeeks.org/expression-tree/
http://www.geeksforgeeks.org/evaluation-of-expression-tree/
Given input should be Reverse Polish Notation, we need to build a expression tree and calculate the
value of it.
For example: Given 3 + (5 + 9) * 2 should be "359+2*+" in postfix notation.
We can build the expression tree with this input and evaluate the expression.
Assume that every operand has only one digit.
 */

#include <string>
#include <stack>

using namespace std;

/*
 *  an expression tree node
 */
struct etNode
{
	etNode(char v):val(v), left(NULL), right(NULL){}
	char val;
	etNode* left;
	etNode* right;
};

/*
 * a utility function to check if 'c' is an operator
 */
bool isOperator(char c)
{
	return c=='+' || c=='-' || c=='*' || c== '/';
}

/*
 * construct tree
 */
etNode * constructExpressionTree(string postFix)
{
	stack<etNode*> etStack;
	for(char c : postFix)
	{
		if(isOperator(c))
		{
			etNode* root = new etNode(c);
			etNode* node1 = NULL;
			etNode* node2 = NULL;
			if(!etStack.empty())
			{
				node1 = etStack.top();    // this is the key!!!
				etStack.pop();
			}
			if(!etStack.empty())
			{
				node2 = etStack.top();
				etStack.pop();
			}
			root->right = node1;
			root->left = node2;
			etStack.push(root);
		}
		else
		{
			etStack.push(new etNode(c));
		}
	}
	etNode* root = etStack.top();
	etStack.pop();
	return root;
}


/*
 * and to evaluate the expression tree
 */
int evaluateExpressionTree(etNode* root)
{
	if(!root) return 0;
	if(!root->left && !root->right) return root->val;

	int leftAns = evaluateExpressionTree(root->left);

	int rightAns = evaluateExpressionTree(root->right);

	if(root->val == '+') return leftAns + rightAns;
	if(root->val == '-') return leftAns - rightAns;
	if(root->val == '*') return leftAns * rightAns;
	if(root->val == '/') return leftAns / rightAns;

	return 0;

}







