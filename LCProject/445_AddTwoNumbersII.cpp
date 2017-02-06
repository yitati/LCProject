/******************************************************************************/
/**
* Question: #445 Add Two Numbers II
* You are given two non-empty linked lists representing two non-negative integers. 
* The most significant digit comes first and each of their nodes contain a single digit. 
* Add the two numbers and return it as a linked list.
* You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/
/*****************************************************************************/


#include "ListNode.h"

// most straightforward slution - get two numbers and use two integer to represent
// get the result and build a linked list

int linkedListToNum(ListNode * head)
{
	int result = 0;
	while (head != NULL)
	{
		result = result * 10 + head->val;
		head = head->next;
	}
	return result;
}

ListNode * numToLinkedList(int num)
{
	ListNode * dummy = new ListNode(0);
	ListNode * curr = dummy;
	int base = 10;
	while (num/base)
	{
		base *= 10;
	}
	base = base / 10;

	while (base >= 1)
	{
		ListNode * newNode = new ListNode(num / base);
		curr->next = newNode;
		curr = newNode;
		num = num % base;
		base /= 10;
	}
	curr = dummy->next;
	delete dummy;
	return curr;
}

// solution to convert the list to int - but overflowed
ListNode* addTwoNumbersII_toInt(ListNode* l1, ListNode* l2) 
{
	int op1 = linkedListToNum(l1);
	int op2 = linkedListToNum(l2);
	int sum = op1 + op2;
	cout << op1 << "   " << op2 << "   " << sum << endl;
	return numToLinkedList(sum);
}

// get the length of a linked list
int getListLength(ListNode * list)
{
	int count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return count;
}

// use recursion to calculate the value of the next nodes
ListNode * addTwoList_recursion(ListNode * l1, ListNode * l2, int len1, int len2)
{
	if (len1 == 0) return NULL;
	int sum = l1->val;
	ListNode * nextNode = NULL;
	if (len1 > len2)
	{
		nextNode = addTwoList_recursion(l1->next, l2, len1 - 1, len2);
	}
	else // l1 == l2
	{
		nextNode = addTwoList_recursion(l1->next, l2->next, len1 - 1, len2 - 1);
		sum += l2->val;
	}

	if (nextNode != NULL)
	{
		sum += nextNode->val / 10;
		nextNode->val %= 10;
	}
	
	ListNode * newNode = new ListNode(sum);
	newNode->next = nextNode;
	
	return newNode;
}

// solution to convert the list to int - but overflowed
ListNode* addTwoNumbersII_recursive(ListNode* l1, ListNode* l2)
{
	int len1 = getListLength(l1);
	int len2 = getListLength(l2);
	ListNode * nextNode;
	if (len1 < len2) nextNode = addTwoList_recursion(l2, l1, len2, len1);
	else nextNode = addTwoList_recursion(l1, l2, len1, len2);
	if (nextNode->val >= 10)
	{
		ListNode * head = new ListNode(1);
		head->next = nextNode;
		nextNode->val %= 10;
		return head;
	}
	return nextNode;
}

/*
int main(int argc, char ** argv)
{
	int input1[] = { 7, 2, 4, 3 }; // size is 3
	int n1 = 4;

	int input2[] = { 5, 6, 4 }; // size is 3
	int n2 = 3;

	ListNode * l1 = generateList(input1, n1);
	ListNode * l2 = generateList(input2, n2);

	ListNode * result1 = addTwoNumbersII_toInt(l1, l2);
	ListNode * result = addTwoNumbersII_recursive(l1, l2);

	printList(result1);

	printList(result);

	system("pause");
}
*/