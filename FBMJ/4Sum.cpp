/*
 * 4Sum.cpp

Determine if there exists a set of four elements in a given array that sum to the given target number.

Assumptions

The given array is not null and has length of at least 4
Examples

A = {1, 2, 2, 3, 4}, target = 9, return true(1 + 2 + 2 + 4 = 8)

A = {1, 2, 2, 3, 4}, target = 12, return false

 */

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Solution 1 - O(n^3)
bool fourSumExists1(vector<int> array, int target)
{
	sort(array.begin(), array.end());

	for(int i=0; i<array.size(); i++){
		if(i > 0 && array[i] == array[i-1]) continue;
		for(int j=i+1; j<array.size(); j++){
			int lhs = j+1, rhs = array.size()-1;
			while(lhs < rhs){
				int sum = array[i] + array[j] + array[lhs] + array[rhs];
				if(sum == target) return true;
				else if(sum < target) lhs++;
				else rhs--;
			}
		}
	}
	return false;
}

// Solution 2 - O(n^2), store the result of two sum but be careful to dedup
bool fourSumExists2(vector<int> array, int target)
{
	// map sum - <index1, index2>
	unordered_map<int, pair<int, int>> sumMap;
	for(int i=0; i<array.size(); i++)
	{
		for(int j=0; j<i; j++)
		{
			int twosum = array[i] + array[j];
			int comp = target - twosum;
			auto it = sumMap.find(comp);
			if(it != sumMap.end() && it->second.second < j) return true;
			if(!sumMap.count(twosum)){
				sumMap[twosum] = pair<int, int>(j, i);
			}
		}
	}
	return false;
}

// Solution 3 - O(n^2 * logn)  BAOBAO Jiang jiang
struct Element {
  int index1;
  int index2;
  int sum;
  Element(int i1, int i2, int s) : index1(i1), index2(i2), sum(s) {};
  bool operator<(const Element& rhs) {
    if (rhs.sum == sum) {
      if (rhs.index2 == index2) {
        return index1 < rhs.index1;
      }
      return index2 < rhs.index2;
    }
    return sum < rhs.sum;
  }
};

bool fourSumExists3(vector<int> array, int target) {
  //Method 3: O(n^2 * log(n))

  vector<Element> twosums;
  for (int i=0; i<array.size(); i++) {
    for (int j=i+1; j<array.size(); j++) {
      twosums.push_back(Element(i, j, array[i] + array[j]));
    }
  }
  sort(twosums.begin(), twosums.end());

  int lhs = 0;
  int rhs = twosums.size() - 1;

  while (lhs < rhs) {
    int sum = twosums[lhs].sum + twosums[rhs].sum;
    if (sum == target) {
      if (twosums[lhs].index2 < twosums[rhs].index1) return true;
      lhs++;
      rhs--;
    } else if (sum < target) {
      lhs++;
    } else {
      rhs--;
    }
  }
  return false;
}


