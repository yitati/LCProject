/******************************************************************************/
/*
* Question: #82 Remove Duplicates from Sorted List II
* Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct
* numbers from the original list.
* For example,
* Given 1->2->3->3->4->4->5, return 1->2->5
* Given 1->1->1->2->3, return 2->3
*/
/*****************************************************************************/

#include <climits>
#include "../Leetcode/ListNode.h"

using namespace std;

ListNode* deleteDuplicatesListII(ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	ListNode * dummy = new ListNode(0);
	dummy->next = head;
	ListNode * prev = dummy;
	ListNode * curr = head;
	int duplicateVal = INT_MIN;
	while (curr != NULL)
	{
		// Still some corner cases not covered here
		if (curr == head && curr->next->val != curr->val)
		{
			curr = curr->next;
			prev = prev->next;
		}
		if (curr->next != NULL && curr->next->val == curr->val)
		{
			duplicateVal = curr->val;
		}

		if (curr->val == duplicateVal) // delete curr
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
	head = dummy->next;
	delete dummy;
	return head;
}

/*
int main(int argc, char ** argv)
{
	int test1[] = { 1, 1, 1, 2, 3 }; // size is 5
	int n1 = 5;

	int test2[] = {0, 1, 2, 2, 3, 4};
	int n2 = 6;

	vector<int>test3;

	cout << "Test 1 1 1 2 3" << endl;
	ListNode * head1 = generateList(test1, n1);
	head1 = deleteDuplicatesListII(head1);
	printList(head1);  // expect 1 2 3
	cout << endl << endl;

	cout << "Test 2 2" << endl;
	ListNode * head2 = generateList(test2, n2);
	head2 = deleteDuplicatesListII(head2);
	printList(head2); // expect 2
	cout << endl << endl;

	cout << "Test NULL" << endl;
	ListNode * head3 = generateList(test3);
	head3 = deleteDuplicatesListII(head3);
	printList(head3); // expect 2
	cout << endl << endl;

	system("pause");
}
*/
