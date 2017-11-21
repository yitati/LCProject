/******************************************************************************/
/**
* Question: #86 Partition List
* Given a linked list and a value x, partition it such that all nodes less than x come 
* before nodes greater than or equal to x.
* You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
/*****************************************************************************/

#include <algorithm>
#include "../Leetcode/ListNode.h"

// move elements greater or equal to x to the tail
ListNode* partition(ListNode* head, int x) 
{
	if (head == NULL || head->next == NULL) return head;
	int len = 0, minVal = head->val, maxVal = head->val;

	ListNode * dummy = new ListNode(0);
	dummy->next = head;
	ListNode * tail = head;
	ListNode * ptr = dummy;

	while (tail->next) 
	{ 
		minVal = min(tail->next->val, minVal);
		maxVal = max(tail->next->val, maxVal);
		tail = tail->next; 
		len++; 
	}
	if (minVal > x || maxVal < x) return head;

	while (len)
	{
		if (ptr->next->val < x) ptr = ptr->next;
		else
		{
			tail->next = ptr->next;
			tail = ptr->next;
			ptr->next = ptr->next->next;
			tail->next = NULL;
		}
		len--;
	}
	head = dummy->next;
	delete dummy;
	return head;
}

/*
int main(int argc, char ** argv)
{
	//int input1[] = {13, 11, 1, 6, 8, 22, 9, 4, 14}; // size is 3
	//int n1 = 9;
	int input1[] = {1, 2}; // size is 3
	int n1 = 2;

	ListNode * l1 = generateList(input1, n1);

	ListNode * result = partition(l1, 0);

	printList(result);

	system("pause");
}
*/
