/*
 * AllSubsequence.cpp
输出给定String所有可能的subsequence
same as subset II
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

void gatherAllSubsequence(const string& input, int pos, vector<string>& results, string& result)
{
  results.push_back(result);

  if(pos >= input.size()) return;

  for(int i=0; i<input.size(); i++)
  {
    // deduplicate
    if(i != pos && input[i-1] == input[i]) continue;  // make sure each time we push only unique element
    result.push_back(input[i]);
    gatherAllSubsequence(input, i+1, results, result);
    result.pop_back();
  }
}

vector<string> allSubsequence(string input)
{
  sort(input.begin(), input.end());
  vector<string> results;
  string result;
  gatherAllSubsequence(input, 0, results, result);
  return results;
}

/*
int main(int argc, char ** argv)
{
  string input = "ab";
  vector<string> results = allSubsequence(input);
  for(int i=0; i<results.size(); i++)
  {
    cout << results[i] << endl;
  }
}
*/


