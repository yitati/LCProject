/*
 * 2SumAllPairII.cpp

Find all pairs of elements in a given array that sum to the pair the given target number.
Return all the distinct pairs of values.

Assumptions

The given array is not null and has length of at least 2
The order of the values in the pair does not matter
Examples

A = {2, 1, 3, 2, 4, 3, 4, 2}, target = 6, return [[2, 4], [3, 3]]

 */

#include <vector>
#include <unordered_map>

using namespace std;

/*
 * if the array is sorted, we can use two pointers
 * if not we can use unordered_map to keep frequences of the numbers
 * !! one very important thing - do not remove element when looping on set/map
 */
vector<vector<int>> twoSumAllPairsII(vector<int> array, int target)
{
	unordered_map<int, int> freq;
	vector<vector<int>> results;
	for(int num : array) freq[num]++;

	for(auto it = freq.begin(); it != freq.end(); it++){
		int num = it->first;
		int tofind =target-num;
		// instead of remove element while looping, we can give some order here
		if(tofind > num) continue;
		else
		{
			if(num == tofind){
				if(freq[tofind] >= 2){
					vector<int> result = {num, num};
					results.push_back(result);
				}
			}else{
				if(freq.count(tofind)){
					vector<int> result = {tofind, num};
					results.push_back(result);
				}
			}
		}
	}
	return results;
}

