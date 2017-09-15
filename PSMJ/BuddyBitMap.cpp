/*
 * BuddyBitMapcpp
 *
 *  Created on: Sep 10, 2017
 *      Author: JoanneY1
 */


#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> completeTree = {
    {0},
    {1, 0},
    {1, 1, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1}
};

/*
 * Solution 1 :  when doing the set bit/clear bit, always need to check next level
 * This is not very efficient.
 */
class BuddySystem
{
public:
	BuddySystem(){}

	BuddySystem(vector<vector<int>> tree){
		m_tree = tree;
	}

	void udpateFromLeaf(int start, int length, int val)
	{
		int lhs = start, rhs = start + length - 1;
		int level = m_tree.size();
		while(level >= 0)
		{
			for(int i=lhs; i<=rhs; i++)
			{
				if(level == m_tree.size()) m_tree[level][i] = val;
				else
				{
					int lchild = i*2;
					int rchild = i*2 + 1;
					if(m_tree[level+1][lchild] && m_tree[level+1][rchild]) m_tree[level][i] = 1;
					else m_tree[level][i] = 0;
				}
			}
			lhs <<= 2;
			rhs <<= 2;
			level--;
		}
	}

	void clearBit(int start, int length)
	{
		udpateFromLeaf(start,length, 0);
	}

	void setBit(int start, int length)
	{
		udpateFromLeaf(start, length, 1);
	}

	void print()
	{
		for(int level =0; level < m_tree.size(); level++)
		{
			for(int i=0; i<m_tree[level].size(); i++)
			{
				cout << " " << m_tree[level][i];
			}
			cout<<endl;
		}
	}

private:
	vector<vector<int>> m_tree;

};

/*
 * Solution 2: No need to trace back the previous level
 */
static vector<vector<int>> bits;

void clearBit2(int start, int len)
{
	int level = bits.size();
	int lhs = start, rhs = lhs + len - 1;
	while(level >= 0)
	{
		for(int i=lhs; i<=rhs; i++)
		{
			bits[level][i] = 0;
		}
		level--;
		lhs <<= 1;
		rhs <<= 1;
	}
}

void setBit2(int start, int len)
{
	int level = bits.size();
	int lhs = start, rhs = start + len - 1;
	while(level >= 0)
	{
		// this part can be changed to memcpy
		for(int i = lhs; i <= rhs; i++)
		{
			bits[level][i] = 1;
		}

		level--;
		int leftBuddy = lhs%2 == 0 ? lhs + 1 : lhs - 1;
		int rightBuddy = rhs%2 == 0 ? rhs + 1 : rhs - 1;
		lhs <<= 1;
		rhs <<= 1;
		if(leftBuddy == 0) lhs++;
		if(rightBuddy == 0) rhs--;
	}
}




