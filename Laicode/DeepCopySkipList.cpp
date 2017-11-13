/*
 * Laicode_DeepCopySkipList.cpp
 *

A Skip List is a special type of linked list, where each of the nodes has a
forward pointer to another node in the front and forward pointers are guaranteed
to be in non-descending order.

Make a deep copy of the original skip list.

 */

#include <cstdlib>
#include <unordered_map>

using namespace std;

class SkipListNode {
 public:
  int value;
  SkipListNode* next;
  SkipListNode* forward;
  SkipListNode(int v) {
     value = v;
     next = forward = NULL;
  }
};

/*
 * if we are allowed to use extra spaces, take forward as random node
 */
SkipListNode* solve(SkipListNode* n)
{
	if(!n) return NULL;

	unordered_map<SkipListNode*, SkipListNode*> table;

	SkipListNode* dummy = new SkipListNode(0);
	SkipListNode* tail = dummy;

	while(n)
	{
		auto it = table.find(n);
		SkipListNode* copyNode = NULL;
		if(it != table.end())
		{
			copyNode = table[n];
		}
		else
		{
			copyNode = new SkipListNode(n->value);
			table[n] = copyNode;
		}
		tail->next = copyNode;

		// foward pointer points to previous node
		if(n->forward)
		{
			auto it = table.find(n->forward);
			if(it != table.end())
			{
				copyNode->forward = it->second;
			}
			else
			{
				SkipListNode* fnode = new SkipListNode(n->forward->value);
				table[n->forward] = fnode;
				copyNode->forward = fnode;
			}
		}
		n = n->next;
		tail = copyNode;
	}

	tail = dummy->next;
	delete dummy;
	return tail;

}

