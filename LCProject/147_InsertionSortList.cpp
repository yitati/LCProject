/******************************************************************************/
/*
* Question: #147 Insertion Sort List
* Sort a linked list using insertion sort.
*/
/*****************************************************************************/

#include "ListNode.h"

ListNode* selectionSortList(ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	// init the dummy
	ListNode * dummy = new ListNode(INT_MIN);
	dummy->next = head;
	ListNode * toSort = dummy;

	ListNode * newHead = new ListNode(-1);
	ListNode * tail = newHead;
	while (toSort->next)
	{
		ListNode * prev = toSort;
		ListNode * minPrev = prev;
		while (prev->next)
		{
			if (prev->next->val < minPrev->next->val) minPrev = prev;
			prev = prev->next;
		}
		tail->next = minPrev->next;
		minPrev->next = minPrev->next->next;
		tail = tail->next;
		tail->next = NULL;
	}

	head = newHead->next;
	delete(newHead);
	delete(dummy);
	return head;
}

void insertSortDaC(ListNode * sorted, ListNode * toSort)
{
	if (toSort == NULL) return;
	if (sorted == NULL || sorted->next == NULL) return;
	// pick head of to Sort
	ListNode * nextToSort = toSort->next;
	ListNode * prev = sorted;
	ListNode * curr = sorted->next;
	while (curr != NULL && curr->val <= toSort->val)
	{
		//cout << "curr is " << curr->val << endl;
		prev = curr;
		curr = curr->next;
	}
	// insert toSort between prev and curr
	if (curr == NULL)
	{
		prev->next = toSort;
		toSort->next = NULL;
	}
	else 
	{
		toSort->next = curr;
		prev->next = toSort;
	}
	
	insertSortDaC(sorted, nextToSort);

}


ListNode * insertionSort_recursion(ListNode * head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode * dummy = new ListNode(INT_MIN);
	dummy->next = head;
	ListNode * toSort = head->next;
	head->next = NULL;

	insertSortDaC(dummy, toSort);
	head = dummy->next;
	delete dummy;
	return head;

}

ListNode * insertionSort_iteration(ListNode * head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode * dummy = new ListNode(INT_MIN);
	ListNode * toSort = head;
	while (toSort)
	{
		ListNode * prev = dummy;
		ListNode * curr = dummy->next;
		ListNode * nextToSort = toSort->next;
		while (curr && curr->val <= toSort->val)
		{
			prev = curr;
			curr = curr->next;
		}
		// insert toSort between prev and curr
		toSort->next = curr;
		prev->next = toSort;
		toSort = nextToSort;
	}
	
	head = dummy->next;
	delete dummy;
	return head;

}

/*
int main(int argc, char ** argv)
{
	int test1[] = { 7, 3, 5, 8, 1, 4, 2, 9, 10, 6 }; // size is 5
	int n1 = 10;

	int test2[] = { 2,2 };
	int n2 = 2;

	vector<int>test3;

	cout << "Test 7, 3, 5, 8, 1, 4, 2, 9, 10, 6" << endl;
	ListNode * head1 = generateList(test1, n1);
	head1 = selectionSortList(head1);
	printList(head1);  // expect 1 2 3
	cout << endl << endl;

	cout << "Test 2 2" << endl;
	ListNode * head2 = generateList(test2, n2);
	head2 = selectionSortList(head2);
	printList(head2); // expect 2
	cout << endl << endl;

	cout << "Test NULL" << endl;
	ListNode * head3 = generateList(test3);
	head3 = selectionSortList(head3);
	printList(head3); // expect 2
	cout << endl << endl;

	system("pause");
}

*/