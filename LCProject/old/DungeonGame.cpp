/******************************************************************************/
/**
* Question: #174 Dungeon Game
* The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. 
* The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned 
* in the top-left room and must fight his way through the dungeon to rescue the princess.
* The knight has an initial health point represented by a positive integer. If at any point his health point 
* drops to 0 or below, he dies immediately.
* Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; 
* other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).
* In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
* Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

* Notes:
* The knight's health has no upper bound.
* Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/
/*****************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DungeonGame {
	// bottom-up DP
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int n = dungeon.size();
		if (n == 0) return 0;
		int m = dungeon[0].size();
		if (m == 0) return 0;

		// use hp[][] to represent the hp value before adding to the current value
		vector<vector<int>> hp(n, vector<int>(m, 1));

		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = m - 1; j >= 0; j--)
			{
				if (i == n - 1 && j == m - 1) hp[i][j] = max(1, 1 - dungeon[i][j]);
				else if (j == m - 1 && i < n - 1) hp[i][j] = max(1, hp[i + 1][j] - dungeon[i][j]);
				else if (i == n - 1 && j < m - 1) hp[i][j] = max(1, hp[i][j + 1] - dungeon[i][j]);
				else {
					hp[i][j] = max(1, (min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j]));
				}
			}
		}

		return hp[0][0];
	}
};