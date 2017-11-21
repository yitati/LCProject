/******************************************************************************/
/**
* Question: #328 Odd Even Linked List
* Given a singly linked list, group all odd nodes together followed by the even nodes. 
* Please note here we are talking about the node number and not the value in the nodes.

* You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

* Note:
* The relative order inside both the even and odd groups should remain as it was in the input.
* The first node is considered odd, the second node even and so on ...
*/
/*****************************************************************************/

#include "../Leetcode/ListNode.h"

ListNode* oddEvenList(ListNode* head) 
{
	if (head == NULL || head->next == NULL) return head;
	ListNode * evenHead = head->next;
	ListNode * odd = head;
	ListNode * even = evenHead;
	while (odd)
	{
		even = odd->next;
		if (even == NULL) break;
		else odd->next = even->next;
		if (odd->next)
		{
			even->next = odd->next->next;
			odd = odd->next;
		}
		else
		{
			even->next = NULL;
		}
	}
	odd->next = evenHead;
	return head;
}

/*
int main(int argc, char ** argv)
{
	int input1[] = { 1, 2, 3, 4, 5}; // size is 3
	int n1 = 5;

	ListNode * l1 = generateList(input1, n1);

	ListNode * result = oddEvenList(l1);

	printList(result);

	system("pause");
}
*/