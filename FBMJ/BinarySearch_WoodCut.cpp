/*
 * WoodCut.cpp
Given n pieces of wood with length L[i] (integer array).
Cut them into small pieces to guarantee you could have equal or more than k pieces with the same length.
What is the longest length you can get from the n pieces of wood?
Given L & k, return the maximum length of the small pieces.
Challenge:
O(n log Len), where Len is the longest length of the wood.

http://www.lintcode.com/en/problem/wood-cut/
http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=296351&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3046%5D%5Bvalue%5D%3D2%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311
 */

#include <vector>

using namespace std;

// helper function
bool canCut(vector<int>& L, int k, long long len) {
	int count = 0;
	for (int i = 0; i < L.size(); i++) {
		count += L[i] / len;
	}
	return count >= k;
}

/**
 *@param L: Given n pieces of wood with length L[i]
 *@param k: An integer
 *return: The maximum length of the small pieces.
 */
int woodCut(vector<int> L, int k) {
	if (L.empty())
		return 0;
	int rhs = *max_element(L.begin(), L.end());
	int lhs = max(1, rhs / k);
	int maxLen = 0;

	while (lhs <= rhs) {
		int mid = lhs + (rhs - lhs) / 2;
		if (canCut(L, k, mid)) {
			maxLen = mid;
			lhs = mid + 1;
		} else {
			rhs = mid - 1;
		}
	}
	cout << maxLen << endl;
	return maxLen;
}



