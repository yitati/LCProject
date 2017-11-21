/******************************************************************************/
/**
* Question: #92 Reverse Linked List II
* Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.

* Note:
* Given m, n satisfy the following condition:
* 1 ≤ m ≤ n ≤ length of list.
*/
/*****************************************************************************/

#include "../Leetcode/ListNode.h"
ListNode* reverseBetween(ListNode* head, int m, int n) 
{
	if (head == NULL) return NULL;
	int k = n - m;
	ListNode * dummy = new ListNode(0);
	dummy->next = head;

	ListNode * prev = dummy;
	ListNode * curr = head;
	
	// we want to revert from m to n
	while (m > 1 && curr)
	{
		prev = curr;
		curr = curr->next;
		m--;
	}
	while (k > 0 && curr)
	{
		ListNode * tmp = curr->next;
		if (tmp)
		{
			curr->next = tmp->next;
			tmp->next = prev->next;
			prev->next = tmp;
			k--;
		}
	}

	head = dummy->next;
	delete dummy;
	return head;
}

/*
int main(int argc, char ** argv)
{
	int input1[] = { 1, 2, 3, 4, 5 }; // size is 3
	int n1 = 5;

	ListNode * l1 = generateList(input1, n1);

	ListNode * result = reverseBetween(l1, 2, 4);

	printList(result);

	system("pause");
}
*/