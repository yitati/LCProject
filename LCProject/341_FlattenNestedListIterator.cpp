/******************************************************************************/
/*
* Question: #341 Flatten Nested List Iterator
* Given a nested list of integers, implement an iterator to flatten it.
* Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]], 

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1]. 


Example 2:
Given the list [1,[4,[6]]], 

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].

*/
/*****************************************************************************/
#include <stack>
#include "NestedInteger.h"

using namespace std;


class NestedIterator {
public:
	NestedIterator(vector<NestedInteger> &nestedList)
	{
		for (int i = nestedList.size() - 1; i >= 0; i--)
		{
			nodes.push(nestedList[i]);
		}
	}

	int next()
	{
		int curr = nodes.top().getInteger();
		nodes.pop();
		return curr;
	}

	bool hasNext()
	{
		while (!nodes.empty())
		{
			if (nodes.top().isInteger()) return true;

			NestedInteger curr = nodes.top();
			nodes.pop();
			vector<NestedInteger> list = curr.getList();
			for (int i = list.size() - 1; i >= 0; i--)
			{
				nodes.push(list[i]);
			}
		}
		return false;
	}

private:
	stack<NestedInteger> nodes;

};