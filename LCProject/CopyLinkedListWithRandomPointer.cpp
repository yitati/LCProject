/******************************************************************************/
/**
* Question: #138 Copy Linked List with Random Pointer
* A linked list is given such that each node contains an additional random pointer which could 
* point to any node in the list or null.
* Return a deep copy of the list.
*/
/*****************************************************************************/

#include <stdlib.h>

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

