/******************************************************************************
* Question: #2 Add Two Numbers
* company tag: Facebook
* You are given two non-empty linked lists representing two non-negative integers. 
* The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*****************************************************************************/

#include "../Leetcode/ListNode.h"

ListNode* addTwoNumbersI(ListNode* l1, ListNode* l2) 
{
	int carry = 0;
	ListNode * head = NULL;
	ListNode * tail = head;
	// carry can not be zeor - otherwise will lose the last node
	while (l1 != NULL || l2 != NULL || carry != 0)
	{
		int opt1 = l1 == NULL ? 0 : l1->val;
		int opt2 = l2 == NULL ? 0 : l2->val;
		int sum = opt1 + opt2 + carry;
		carry = sum / 10;
		sum = sum % 10;

		ListNode * newNode = new ListNode(sum);
		if (head == NULL) head = newNode;
		else tail->next = newNode;
		tail = newNode;

		l1 = l1 == NULL ? NULL : l1->next;
		l2 = l2 == NULL ? NULL : l2->next;
	}

	return head;
}

/*
int main(int argc, char ** argv)
{
	int input1[] = { 2, 4, 3}; // size is 3
	int n1 = 3;

	int input2[] = { 5, 6, 4 }; // size is 3
	int n2 = 3;

	ListNode * l1 = generateList(input1, n1);
	ListNode * l2 = generateList(input2, n2);

	ListNode * result = addTwoNumbers(l1, l2);

	printList(result);

	system("pause");
}

*/
