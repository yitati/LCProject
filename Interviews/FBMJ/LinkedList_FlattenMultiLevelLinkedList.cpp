/*
 * MultiLevelLinkedListToSinglyLinkedList.cpp
http://www.geeksforgeeks.org/flatten-a-linked-list-with-next-and-child-pointers/
 */

#include <cstdlib>

/*
 * suppose we have a multi-level linked list and we need to flatten it
 */
struct MListNode
{
	MListNode(): val(0), next(NULL), child(NULL){}
	int val;
	MListNode* next;
	MListNode* child;  // point to next level
};

/*
 * first if we need to flat the multi level list to singly linked list level by level

10 - 5 - 12 - 7 - 11
|             |
4 - 20 - 13 - 17 - 6
    |    |    |
     2   16   9 - 8
         |    |
         3   19 - 15
Output:
10->5->12->7->11->4->20->13->17->6->2->16->9->8->3->19->15

for each level use two pointers
 - pointer curr point to the head of the list
 - pointer tail point to the tail of the list
 - if curr->child, then move tail in next level, update tail
 - update curr
*/
MListNode* flattenLevelByLevel(MListNode* head)
{
	if(!head) return NULL;
	MListNode* curr = head;
	MListNode* tail = head;

	while(tail->next) tail = tail->next;

	// curr is moving slow and tail is moving fast
	while(curr != tail)
	{
		if(curr->child)
		{
			tail->next = curr->child;
			MListNode* tmp = curr->child;
			while(tmp->next) tmp = tmp->next;
			tail = tmp;
			curr->child = NULL;
		}
		curr = curr->next;
	}
	return head;
}

/*
1 - 2 - 3 - 4
    |
    7 -  8 - 10 - 12
    |    |    |
    9    16   11
    |    |
    14   17 - 18 - 19 - 20
    |                    |
    15 - 23             21
         |
         24
Output:
1->2->7->9->14->15->23->24->8->16->17->18->19->20->21->10->11->12->3->4

first go down then go next

This is a dfs recursion
 */
MListNode* flattenRecursion(MListNode* head, MListNode*& tail)
{
	if(!head) return NULL;
	tail = head;
	MListNode* nextNode = head->next;
	if(head->child) // first check next level, go deeper
	{
		head->next = flattenRecursion(head->child, tail);
	}
	if(nextNode) // then check same level, go horizontally
	{
		tail->next = flattenRecursion(nextNode, tail);
	}
	return head;
}

MListNode* flattenChildFirst(MListNode* head)
{
	MListNode* tail = head;
}

