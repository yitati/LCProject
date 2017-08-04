/*
 * Laicode_2SumAllPairI.cpp

Find all pairs of elements in a given array that sum to the given target number. Return all the pairs of indices.

Assumptions

The given array is not null and has length of at least 2.

Examples

A = {1, 3, 2, 4}, target = 5, return [[0, 3], [1, 2]]

A = {1, 2, 2, 4}, target = 6, return [[1, 3], [2, 3]]

 */

#include <vector>
#include <unordered_map>

using namespace std;


/*
 * there coule be duplicates in the given array, so we have to use a vector<int>
 * to store all the index of the same element
 */
vector<vector<int>> twoSumAllPairsI(vector<int> array, int target)
{
	unordered_map<int, vector<int>> numMap;
	vector<vector<int>> results;
	for(int i=0; i<array.size(); i++){
		int tofind = target - array[i];
		if(numMap.count(tofind)){
			auto list = numMap[tofind];
			for(int j=0; j<list.size(); j++)
			{
				vector<int> result = {list[j], i};
				results.push_back(result);
			}
		}
		if(!numMap.count(array[i]))
		{
			vector<int> item;
			numMap[array[i]] = item;
		}
		numMap[array[i]].push_back(i);
	}
	return results;
}



