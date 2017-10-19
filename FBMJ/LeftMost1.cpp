/*
 * LeftMost1.cpp
 *
矩阵找最左边的1在哪一列，for example
[
0, 0, 0, 0, 1
0, 0, 1, 1, 1
0, 0, 0, 0, 1
0, 0, 0, 1, 1
]
 */


#include <vector>

using namespace std;

// worse case time complexity is O(nlog m)
int binaryFindFirst1(vector<int>& nums, int lhs, int rhs)
{
	if(lhs > rhs) return -1;
	while(lhs < rhs)
	{
		int mid = lhs + (rhs - lhs)/2;
		if(nums[mid] == 1) rhs = mid;
		else if(nums[mid] == 0) lhs = mid+1;
	}
	return rhs;
}

int findLeftMost1(vector<vector<int>> matrix)
{
	if(matrix.empty() || matrix[0].empty()) return -1;
	int col = binaryFindFirst1(matrix[0], 0, matrix[0].size()-1);
	if(col == -1) return -1;
	for(int i=1; i<matrix.size(); i++)
	{
		if(matrix[i][col] == 0) continue;
		else col = binaryFindFirst1(matrix[i], 0, col);
	}
	return col;
}






