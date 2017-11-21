/******************************************************************************/
/*
* Question: #148 Sort List
* Sort a linked list in O(n lgn) time using constant space complexity.
*/
/*****************************************************************************/

#include "../Leetcode/ListNode.h"
// split, sort and merge
// use merge sort to sort the list so the time complexity will be O(nlogn)
// this is devide and conquer - consumes O(nlogn) space

void split(ListNode * head, ListNode * & half)
{
	if (head == NULL || head->next == NULL)
	{
		half = NULL;
	}
	ListNode * fast = head;
	ListNode * slow = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	half = slow->next;
	slow->next = NULL;
}

ListNode* sortList(ListNode* head) 
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	// split the list into two halfs
	ListNode * half = NULL;
	split(head, half);
	head = sortList(head);
	half = sortList(half);
	head = mergeTwoLists(head, half);
	return head;
}

/*
int main(int argc, char ** argv)
{
	int test1[] = { 3, 4, 8, 2, 1, 7 }; // size is 5
	int n1 = 6;

	vector<int>test3;

	cout << "Test 3 4 8 2 1 7" << endl;
	ListNode * head1 = generateList(test1, n1);
	head1 = sortList(head1);
	printList(head1);  // expect 1 2 3
	cout << endl << endl;

	system("pause");
}
*/