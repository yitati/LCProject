/******************************************************************************/
/**
* Question: #142 Linked List Cycle II
* Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

* Follow up:
* Can you solve it without using extra space?
*/
/*****************************************************************************/

#include "ListNode.h"

bool hasCycle_helper(ListNode *head)
{
	ListNode * fast = head;
	ListNode * slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) return true;
	}
	return false;
}

ListNode *detectCycle_brutalforce(ListNode *head)
{
	if (hasCycle_helper(head) == false) return NULL;
	ListNode * curr = NULL;
	while (head->next)
	{
		if (head->next == head) return head;
		curr = head;
		head = head->next;
		curr->next = NULL;
		bool hasCycle = hasCycle_helper(head);
		curr->next = head;
		if (hasCycle == true) continue;
		else break;
	}
	return curr;
}

ListNode *detectCycle_math(ListNode *head)
{
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next) 
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) break;
	}

	if (fast == NULL || fast->next == NULL) return NULL;

	slow = head;
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}



/*
int main(int argc, char ** argv)
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = head;
	ListNode* start = detectCycle_math(head);

	if (start) {
		cout << start->val << endl;
	}
	else {
		cout << "no cycle" << endl;
	}

	system("pause");

}
*/