#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

/*
 * this is same as Subset I
 */
/*
给一个质数数组，没有重复元素，比如[2, 3, 5]，要求返回所有元素之间可能的乘积，比如结果是[2, 3, 5, 6, 10, 15, 30]，
每个数最多用一次，结果不一定需要是有序的。
*/

void fillPrimeMux(vector<int>& primes, vector<int>& results, int pos, int currMux)
{
  if(currMux != 1) results.push_back(currMux);
  if(pos >= primes.size()) return;

  for(int i=pos; i<primes.size(); i++)
  {
    fillPrimeMux(primes, results, i+1, currMux * primes[i]);
  }
}

vector<int> PrimeMux(vector<int> primes)
{
  vector<int> results;
  fillPrimeMux(primes, results, 0, 1);
  return results;
}




