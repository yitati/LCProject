/******************************************************************************
* Question: #83 Remove Duplicates from Sorted List 
* company tag: Facebook
* Given a sorted linked list, delete all duplicates such that each element appear only once.
* For example,
* Given 1->1->2, return 1->2
* Given 1->1->2->3->3, return 1->2->3
*****************************************************************************/

#include <iostream>
#include <vector>

#include "../Leetcode/ListNode.h"

using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	ListNode * prev = head;
	ListNode * curr = prev->next;
	while (curr != NULL)
	{
		if (curr->val == prev->val)
		{
			ListNode * toDelete = curr;
			curr = curr->next;
			prev->next = curr;
			delete toDelete;
		}
		else
		{
			curr = curr->next;
			prev = prev->next;
		}
	}
	return head;
}

/*
int main(int argc, char ** argv)
{
	int test1[] = { 1, 1, 1, 2, 3 }; // size is 5
	int n1 = 5;

	int test2[] = { 2,2 };
	int n2 = 2;

	vector<int>test3;

	cout << "Test 1 1 1 2 3" << endl;
	ListNode * head1 = generateList(test1, n1);
	head1 = deleteDuplicates(head1);
	printList(head1);  // expect 1 2 3
	cout << endl << endl;

	cout << "Test 2 2" << endl;
	ListNode * head2 = generateList(test2, n2);
	head2 = deleteDuplicates(head2);
	printList(head2); // expect 2
	cout << endl << endl;

	cout << "Test NULL" << endl;
	ListNode * head3 = generateList(test3);
	head3 = deleteDuplicates(head3);
	printList(head3); // expect 2
	cout << endl << endl;

	system("pause");
}
*/
