/*
 * ArithmeticSequence.cpp
 *
 *  Find the longest arithmetic subsequence in unsorted array.
 */

#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

// dp[i][diff] means for sequence of [0, i] the longest arithmetic subsequence with diff
int longestArithmeticSequence(const vector<int>& data) {
  vector<unordered_map<int, int> > dp(data.size());
  int maxLen = 0;
  for (int i=1; i<data.size(); i++) {
    for (int j=i-1; j >= 0; j--) {
      int diff = data[i] - data[j];
      int preLen = dp[j].count(diff) ? dp[j][diff] : 1;
      dp[i][diff] = max(dp[i][diff], preLen + 1);
      maxLen = max(maxLen, dp[i][diff]);
    }
  }

  return maxLen;
}

int main(int argc, char** argv) {
  vector<int> data = {1, 2, 6, 2, 5, 2, 3, 4, 7, 6, 7, 8, 10, 12};
  cout << longestArithmeticSequence(data) << endl;
}



