/******************************************************************************/
/*
* Question: #421 Maximum XOR of Two Numbers in an Array
* Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
* Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
* Could you do this in O(n) runtime?

Example:
Input: [3, 10, 5, 25, 2, 8]
Output: 28
Explanation: The maximum result is 5 ^ 25 = 28.

*/
/*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

class binNode
{
public:
	binNode* next[2];
	binNode() { next[0] = NULL; next[1] = NULL; }
};


binNode * buildTree(vector<int> & nums)
{
	binNode * root = new binNode(), *curr;
	for (int num : nums)
	{
		curr = root;
		for (int i = 31; i >= 0; i--)
		{
			int digit = (num >> i) & 1;
			if (!curr->next[digit]) curr->next[digit] = new binNode();
			curr = curr->next[digit];
		}

	}
	return root;
}

int findNum(binNode * root, int num)
{
	binNode * node = root;
	int res = 0;
	for (int i = 31; i >= 0; i--)
	{
		int digit = (num >> i) & 1;
		if (node->next[1 - digit])
		{
			res = (res << 1) + 1;
			node = node->next[1 - digit];
		}
		else
		{
			res <<= 1;
			node = node->next[digit];
		}
	}
	return res;
}

int findMaximumXOR(vector<int>& nums)
{
	int result = 0;
	binNode * root = buildTree(nums);
	for (int num : nums)
	{
		result = max(result, findNum(root, num));
	}
	return result;
}




