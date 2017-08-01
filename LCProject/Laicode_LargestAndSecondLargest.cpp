/*
 * Laicode_LargestAndSecondLargest.cpp
 *
 *  Created on: Jul 30, 2017
 *      Author: JoanneY1
 */

#include <vector>
#include <climits>

using namespace std;

// create a heler class to store the candidate and its defeated
class Cand {
public:
	int val;
	vector<int> defeated;
	Cand(int v) :
			val(v) {
	}
	int getLargestDefeated() {
		int maxNum = INT_MIN;
		for (int num : defeated) {
			maxNum = max(maxNum, num);
		}
		return maxNum;
	}
};

Cand beat(Cand& lhs, Cand& rhs) {
	if (lhs.val > rhs.val) {
		lhs.defeated.push_back(rhs.val);
		return lhs;
	} else {
		rhs.defeated.push_back(lhs.val);
		return rhs;
	}
}

vector<Cand> getBeatList(vector<Cand>& candidates) {
	vector<Cand> result;
	for (int i = 0; i < candidates.size(); i += 2) {
		if (i + 1 < candidates.size()) {
			result.push_back(beat(candidates[i], candidates[i + 1]));
		} else {
			result.push_back(candidates[i]);
		}
	}
	return result;
}

vector<int> largestAndSecond(vector<int> array) {
	vector<int> result(2, -1);
	vector<Cand> candidates;
	for (int i = 0; i < array.size(); i++) {
		Cand newCand(array[i]);
		candidates.push_back(newCand);
	}
	while (candidates.size() > 1) {
		candidates = getBeatList(candidates);
	}
	result[0] = candidates[0].val;
	result[1] = candidates[0].getLargestDefeated();
	return result;
}

