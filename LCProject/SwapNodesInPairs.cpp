/******************************************************************************/
/**
* Question: #24 Swap Nodes In Pairs
* Given a linked list, swap every two adjacent nodes and return its head.
For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.
* Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/
/*****************************************************************************/

#include "ListNode.h"

ListNode* swapPairs(ListNode* head) 
{
	if (head == NULL || head->next == NULL) return head;
	ListNode * dummy = new ListNode(0);
	dummy->next = head;
	ListNode * prev = dummy;
	while (prev->next && prev->next->next)
	{
		ListNode * odd = prev->next;
		ListNode * even = odd->next;
		ListNode * tmp = even->next;
		prev->next = even;
		even->next = odd;
		odd->next = tmp;
		prev = odd;
	}
	head = dummy->next;
	delete dummy;
	return head;
}

/*
int main(int argc, char ** argv)
{
	int input1[] = { 1, 2, 3 }; // size is 3
	int n1 = 3;

	ListNode * l1 = generateList(input1, n1);

	ListNode * result = swapPairs(l1);

	printList(result);

	system("pause");
}
*/