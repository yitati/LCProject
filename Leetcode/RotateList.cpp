/******************************************************************************/
/**
* Question: #61 Rotate List
* Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
/*****************************************************************************/

#include "../Leetcode/ListNode.h"

ListNode* rotateRight(ListNode* head, int k) 
{
	if (head == NULL || head->next == NULL) return head;
	ListNode * tail = head;
	int len = 1;
	while (tail->next) 
	{
		tail = tail->next; 
		len++;
	}
	tail->next = head;
	k = len - k%len;
	while (k)
	{
		tail = tail->next;
		head = head->next;
		k--;
	}
	tail->next = NULL;
	return head;
}


/*
int main(int argc, char ** argv)
{
	int input1[] = { 1, 2, 3, 4, 5 }; // size is 3
	int n1 = 5;

	ListNode * l1 = generateList(input1, n1);

	ListNode * result = rotateRight(l1, 2);

	printList(result);

	system("pause");
}
*/
