/******************************************************************************/
/*
* Question: #119 Pascal's Triangle II
* Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

* Note:
* Could you optimize your algorithm to use only O(k) extra space?
*/
/*****************************************************************************/

#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) 
{
	vector<int> result(rowIndex + 1, 0);
	result[0] = 1;
	for (int i = 1; i <= rowIndex; i++)
	{
		for (int j = i; j > 0; j--)
		{
			result[j] = result[j - 1] + result[j];
		}
	}
	return result;
}