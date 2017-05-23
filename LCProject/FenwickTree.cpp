/*
Use Fenwick Tree to getSum(index) and update(index) in O(logN) time
*/
#include <vector>

using namespace std;

/*
            n -> No. of elements present in input array.
BITree[0...n] -> Array that represents Binary Indexed Tree
arr[0...n-1]  -> Input array for which prefix sum is evalued

*/

int getSum(vector<int> BITree, int index)
{
	int sum = 0;
	index = index + 1;
	while (index)
	{
		sum += BITree[index];
		index -= index & (-index);
	}
	return sum;
}

void updateBIT(vector<int> & BITree, int index, int diff)
{
	index = index + 1;
	while (index)
	{
		BITree[index] += diff;
		index -= index & (-index);
	}
}

// Construct and returns a Binary Indexed Tree for given array of size n.
vector<int> constructBITree(vector<int> & input)
{
	int n = input.size();
	// Create and initialize BITree[] as 0
	vector<int> BITree(n + 1);
	for (int i = 1; i <= n; i++)
	{
		BITree[i] = 0;
	}
	// Store the actual values in BITree[] using update()
	for (int i = 0; i < n; i++)
	{
		updateBIT(BITree, i, input[i]);
	}

	return BITree;
}