/*
 * Laicode_DeepCopyLinkedListWithRandomPointer.cpp

Each of the nodes in the linked list has another pointer pointing to a random node in the list or null.
Make a deep copy of the original list.

 */

#include <cstdlib>
#include <unordered_map>

using namespace std;

class RandomListNode{
public:
	int value;
	RandomListNode* next;
	RandomListNode* random;
	RandomListNode(int v){
		value = v;
		next = random = NULL;
	}
};

/* normally we can use 2 loops
 * but to use only one loops we can use a lookup table which maps the copy node to the original node
 * another solution is to copy the node and attach it to the next of original node
 * LC 138 Copy Linked List With Random Pointer
 * The lookup table solution is more compact
 */
RandomListNode* deepCopyList(RandomListNode* n)
{
	if(!n) return NULL;
	unordered_map<RandomListNode*, RandomListNode*> lookup;
	RandomListNode* copyNode = new RandomListNode(n->value);
	lookup[n] = copyNode;
	while(n){
		// first check if next is already exist in the table
		if(n->next){
			if(!lookup.count(n->next)) {
				lookup[n->next] = new RandomListNode(n->next->value);
			}
			lookup[n]->next = lookup[n->next];
		}
		// then check if random is already exist in the table
		if(n->random){
			if(!lookup.count(n->random)) {
				lookup[n->random] = new RandomListNode(n->random->value);
			}
			lookup[n]->random = lookup[n->random];
		}
		// proceed to the next node
		n = n->next;
	}
	return copyNode;
}
