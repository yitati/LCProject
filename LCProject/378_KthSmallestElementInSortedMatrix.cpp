/******************************************************************************/
/*
* Question: #378 Kth Smallest Element in a Sorted Matrix
* Given a n x n matrix where each of the rows and columns are sorted in ascending order,
* find the kth smallest element in the matrix.
* Note that it is the kth smallest element in the sorted order, not the kth distinct element.
* Example:
* matrix = [
*   [ 1,  5,  9],
*   [10, 11, 13],
*   [12, 13, 15]
* ],
* k = 8,
* return 13.
*
* Note:
* You may assume k is always valid, 1 <= k <= n^2
*/
/*****************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// This question equals to find Kth min element in n sorted arraies
// similar to the question to merge K sorted arraies

// but apart from the min heap, we also need to know the index for the top element
// so we need to build a struct for every element pushed to the heap

struct MatrixNode
{
	int val;
	int row;
	int col;
	MatrixNode(int v, int r, int c) : val(v), row(r), col(c) {};
};

struct comparator {
	bool operator()(MatrixNode & i, MatrixNode & j)
	{
		return i.val > j.val;
	}
};

// solution 1 - same idea with merge K sorted list
int kthSmallest1(vector<vector<int>>& matrix, int k) 
{
	int n = matrix.size();
	
	priority_queue<MatrixNode, std::vector<MatrixNode>, comparator> minHeap;
	for (int i = 0; i < matrix.size(); i++)
	{
		minHeap.push(MatrixNode(matrix[i][0], i, 0));
	}
	int count = 0;
	while (count < k)
	{
		count++;
		MatrixNode node = minHeap.top();
		if (count == k) return node.val;
		minHeap.pop();
		if (node.col < n - 1)
		{
			minHeap.push(MatrixNode(matrix[node.row][node.col + 1], node.row, node.col+1));
		}
	}
	return 0;
}

// solution 2 - use "BFS"

int kthSmallest_dfs(vector<vector<int>>& matrix, int k)
{
	int n = matrix.size();
	priority_queue<MatrixNode, std::vector<MatrixNode>, comparator> minHeap;
	int count = 0;
	vector<vector<int>> flag(n, vector<int>(n, 0));

	minHeap.push(MatrixNode(matrix[0][0], 0, 0));
	flag[0][0] = 1;

	
	while (count < k)
	{
		count++;
		//cout << "count is " << count << endl;
		MatrixNode node = minHeap.top();
		minHeap.pop();
		// cout << "pop " << node.val << endl;
		//cout << "push ";
		if (node.col < n - 1 && flag[node.row][node.col+1] == 0)
		{
			minHeap.push(MatrixNode(matrix[node.row][node.col + 1], node.row, node.col + 1));
			flag[node.row][node.col + 1] = 1;
			//cout << matrix[node.row][node.col + 1] << '\t';
		}

		if (node.row < n - 1 && flag[node.row+1][node.col] == 0)
		{
			minHeap.push(MatrixNode(matrix[node.row + 1][node.col], node.row + 1, node.col));
			flag[node.row + 1][node.col] = 1;
			//cout << ' ' << matrix[node.row + 1][node.col] << '\t';
		}
		//cout << endl;


		if (count == k) return node.val;

		//cout << endl;
	}

	return -1;
}

/*
int main(int argc, char ** argv)
{
	int input[3][3] = { { 1, 3, 5}, {6, 7, 12}, {11, 14, 14 } };
	int m = 3, n = 3;
	vector<vector<int>> matrix(n, vector<int>(m));
	int r, c;
	for (r = 0; r < n; r++)
	{
		for (c = 0; c < m; c++)
		{
			matrix[r][c] = input[r][c];
		}
	}

	int x = kthSmallest_dfs(matrix, 6);
	system("pause");
}
*/