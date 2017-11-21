/**********************************************************************************************
 * Question #339 Nested List Weight Sum
 * company tag: LinkedIn
 * Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 * company tag : LinkedIn

Example 1:
Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)

Example 2:
Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3;
1 + 4*2 + 6*3 = 27)

*********************************************************************************************/

#include "../Leetcode/NestedInteger.h"

void calcSum(NestedInteger item, int currWeight, int& currSum)
{
	if(item.isInteger())
	{
		currSum += currWeight * item.getInteger();
		return;
	}
	else
	{
		vector<NestedInteger> list = item.getList();
		currWeight++;
		for(int i=0; i<list.size(); i++)
		{
			calcSum(list[i], currWeight, currSum);
		}
	}
}

int depthSum(vector<NestedInteger>& nestedList)
{
	int currSum = 0;
	for(int i=0; i<nestedList.size(); i++)
	{
		calcSum(nestedList[i], 1, currSum);
	}
	return currSum;
}




