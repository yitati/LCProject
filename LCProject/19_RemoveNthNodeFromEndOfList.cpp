/******************************************************************************/
/**
* Question: #19 Remove Nth Node From End Of List
* Given a linked list, remove the nth node from the end of list and return its head.
For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
* Note:
* Given n will always be valid.
* Try to do this in one pass.
/*****************************************************************************/

#include "ListNode.h"

using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	if (head == NULL) return NULL;
	ListNode * dummy = new ListNode(0);
	dummy->next = head;
	ListNode * ptr = head;
	int len = 0;
	while (ptr) 
	{
		ptr = ptr->next; 
		len++;
	}
	// can not remove dummy 
	if (n > len) return head;
	int k = len - n;
	ptr = dummy;
	while (k) { ptr = ptr->next; k--; }
	ListNode * tmp = ptr->next;
	ptr->next = tmp->next;
	delete tmp;
	head = dummy->next;
	delete dummy;
	return head;
}

int main(int argc, char ** argv)
{
	int input1[] = { 1, 2, 3, 4, 5 }; // size is 3
	int n1 = 5;

	ListNode * l1 = generateList(input1, n1);

	ListNode * result = removeNthFromEnd(l1, 2);

	printList(result);

	system("pause");
}