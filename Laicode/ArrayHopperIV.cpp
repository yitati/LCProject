/*
 * ArrayHopperIV.cpp
 *

 Given an array A of non-negative integers, you are initially positioned at
 an arbitrary index of the array. A[i] means the maximum jump distance from
 that position (you can either jump left or jump right). Determine the minimum
 jumps you need to reach the right end of the array. Return -1 if you can not
 reach the right end of the array.

 Assumptions

 The given array is not null and has length of at least 1.
 Examples

 {1, 3, 1, 2, 2}, if the initial position is 2, the minimum jumps needed is 2
 (jump to index 1 then to the right end of array)

 {3, 3, 1, 0, 0}, if the initial position is 2, the minimum jumps needed is 2
 (jump to index 1 then to the right end of array)

 {4, 0, 1, 0, 0}, if the initial position is 2, you are not able to reach the
 right end of array, return -1 in this case.

 */

#include <vector>
#include <queue>

using namespace std;

/*
 * if we go backward, then calculate reachable range with negative value,
 * if we go forward, use positive value
 */
int minJumpIV(vector<int> array, int index) {
	vector<bool> visited(array.size(), false);
	queue<int> level;

	level.push(index);
	int step = 0;
	while (!level.empty()) {
		int size = level.size();
		for (int i=0; i<size; i++) {
			int curr = level.front();
			level.pop();
			if (curr == array.size() - 1) return step;
			int minReach = max(0, curr-array[curr]);
			int maxReach = min((int)array.size()-1, curr+array[curr]);
			for (int k = minReach; k <= maxReach; k++) {
				if (visited[k]) continue;
				level.push(k);
				visited[k] = true;
			}
		}
		step++;
	}

	return -1;
}

