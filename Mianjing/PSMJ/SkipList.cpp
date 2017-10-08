/*
 * SkipList.cpp
 *
http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=210016&ctid=459
http://www.geeksforgeeks.org/skip-list/
What data structure would you use to construct a skip list? Implement search() and insert().
Skiplist is to implement Binary Search or BST on linked list.
Build multiple layer lists, leaf layer is the original list while upper layer are temp indexing node to coarsely locate
the target in a segment/range.
Reference links:
    http://igoro.com/archive/skip-lists-are-fascinating/
    http://www.mathcs.emory.edu/~cheung/Courses/323/Syllabus/Map/skip-list-impl.html
    http://ticki.github.io/blog/skip-lists-done-right/

 */

#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

/*
 * The naive solution is to create one val for each node, but this will duplicate data for the node
 * in each layer. If data is integer, it is ok, but if data is string, it will waster space.
 * So a better solution is for each skip node, we store a vector of "next" pointer, and the index
 * of the vector indicate the level. For example, next[i] means the next pointer in level i.
 * The uppest level is maxLevel and the lowest level is 0.
 */

// define a global max level of skip list
const int MAXLEVEL = 3;

class SkipNode
{
public:
	int val;
	vector<SkipNode*> next;

	SkipNode(int v): val(v)
	{
		next = vector<SkipNode*>(MAXLEVEL, NULL);
	}

};

class SkipList
{
public:
	SkipList()
	{
		srand(time(NULL));
		dummy = new SkipNode(0);
	}

	/*
	 * search method:
	 * compare the value to insert with curr->next, if curr->next->val >= value to insert, go for the next level
	 */
	SkipNode* search(int data)
	{
		SkipNode* curr = dummy;
		int level = MAXLEVEL;
		while(curr->next[level])
		{
			if(curr->next[level]->val < data) curr = curr->next[level]; // move to the next in the same level
			else
			{
				if(curr->next[level]->val == data) return curr->next[level];
				level--; // move to next level
			}
		}
		return NULL;
	}

	/*
	 * insert method
	 */
	void insert(int data)
	{
		int upper = rand()%(MAXLEVEL+1);
		int level = MAXLEVEL;
		vector<SkipNode*> update;
		SkipNode* curr = dummy;
		// find all nodes that need to update
		while(curr)
		{
			if(curr->next[level] && curr->next[level]->val < data) curr = curr->next[level];
			else
			{
				if(curr->next[level] && curr->next[level]->val == data) return;  // this node exist
				if(level <= upper) // if curr->next[level] is NULL, we still may need this node in the vector
				{
					update.push_back(curr);
				}
				level--;
			}
		}
		// create a new node
		SkipNode* newNode = new SkipNode(data);
		// update all nodes
		for(int i=0; i<=upper; i++)
		{
			SkipNode* curr = update.back();
			update.pop_back();
			SkipNode* tmp = curr->next[i];
			newNode->next[i] = tmp;
			curr->next[i] = newNode;
		}
	}

private:
	SkipNode* dummy;
};


