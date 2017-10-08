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
给一个质数数组，没有重复元素，比如[2, 3, 5]，要求返回所有元素之间可能的乘积，比如结果是[2, 3, 5, 6, 10, 15, 30]，
每个数最多用一次，结果不一定需要是有序的。
*/

void recursivePrimeMux(vector<int>& result, vector<int>& array, int pos, int curr)
{
  result.push_back(curr);
  if(pos >= (int)array.size())
  {
    return;
  }

  for(int i=pos; i<array.size(); i++)
  {
    curr *= array[i];
    recursivePrimeMux(result, array, i+1, curr);
    curr /= array[i];
  }
}

vector<int> primeMux(vector<int> array)
{
  vector<int> result;
  recursivePrimeMux(result, array, 0, 1);
  return result;
}




