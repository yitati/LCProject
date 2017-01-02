#pragma once

#ifndef LISTNODE_H
#define LISTNODE_H

#include<cstdlib>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode * head);
ListNode * generateList(int arr[], int arr_size);
ListNode * generateList(vector<int> & arr);
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);


#endif
