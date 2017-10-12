/*
 * RotateArray.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: JoanneY1
 */

#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<int>& nums, int k) {
	int n = nums.size();
	k = k % n;
	// first reverse the whole string
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin() + k);
	reverse(nums.begin() + k, nums.end());
}

