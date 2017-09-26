/******************************************************************************
* Question: #138 Copy Linked List with Random Pointer
* company tag: Amazon
* A linked list is given such that each node contains an additional random pointer which could 
* point to any node in the list or null.
* Return a deep copy of the list.
*****************************************************************************/

#include <stdlib.h>
#include <unordered_map>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

// make copies of every node and attached it to be the original next
RandomListNode *copyRandomList(RandomListNode * head) 
{
	if (head == NULL) return NULL;
	// copy every node to be the next of the original node
	RandomListNode * ptr = head;
	while (ptr)
	{
		RandomListNode * tmp = ptr->next;
		RandomListNode * copyNode = new RandomListNode(ptr->label);
		copyNode->next = tmp;
		ptr->next = copyNode;
		ptr = tmp;
	}
	// get the random pointers
	ptr = head;
	RandomListNode * copyHead = head->next;

	while (ptr)
	{
		if (ptr->random != NULL)
		{
			ptr->next->random = ptr->random->next;
		}
		ptr = ptr->next->next;
	}

	// split the list
	ptr = head;
	while(ptr)
	{
		RandomListNode * copyCurr = ptr->next;
		ptr->next = copyCurr->next;
		if (ptr->next) copyCurr->next = copyCurr->next->next;
		ptr = ptr->next;
	}

	return copyHead;		
}

RandomListNode *deepCopyRandomList(RandomListNode * head)
{
	if(head == NULL) return NULL;
	// use a hash table to store the node pair
	unordered_map<RandomListNode*, RandomListNode* > table;
	RandomListNode* curr = head;
	while(curr)
	{
		// check for the node itself
		if(!table.count(curr))
		{
			RandomListNode* copyCurr = new RandomListNode(curr->label);
			table[curr] = copyCurr;
		}
		// check for the next
		if(curr->next)
		{
			if(!table.count(curr->next))
			{
				RandomListNode* copyNext = new RandomListNode(curr->next->label);
				table[curr->next] = copyNext;
			}
			table[curr]->next = table[curr->next];
		}
		// check for the random
		if(curr->random)
		{
			if(!table.count(curr->random))
			{
				RandomListNode* copyRandom = new RandomListNode(curr->random->label);
				table[curr->random] = copyRandom;
			}
			table[curr]->random = table[curr->random];
		}
		// move curr to next
		curr = curr->next;
	}

	RandomListNode* copyHead = table[head];
	return copyHead;

}
