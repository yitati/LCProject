/*
 * BuddySystem.cpp
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
int main(int argc, char ** argv)
{
	BuddySystem bs(completeTree);

	bs.print();

	bs.setBit(3, 3);

	bs.print();

	bs.clearBit(1, 3);

	bs.print();
}

*/



