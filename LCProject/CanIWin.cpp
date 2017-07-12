/********************************************************************************************************
 * Question #464 Can I Win
 * # company tag: LinkedIn
 * # type tag: #memDFS#back-tracking#bit-manipulation#
 * In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player
 * who first causes the running total to reach or exceed 100 wins.
 * What if we change the game so that players cannot re-use integers?
 * For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement
 * until they reach a total >= 100.
 * Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move
 * can force a win, assuming both players play optimally.
 * You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.

Example
Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.

********************************************************************************************************/

#include <vector>
#include <unordered_map>

using namespace std;

// since max choosable int should be no larger than 20
// so we can store the visited/non-visited situation by using an int
int getKey(vector<bool>& visited)
{
	int key = 0;
	for(bool b : visited)
	{
		key <<= 1;
		if(b) key |= 0x01;
	}
	return key;
}

// This is a mem DFS problem
bool memdfs_canWin(vector<bool>& visited, unordered_map<int, bool>& memTable, int target)
{
	if(target <= 0) return false;
	int key = getKey(visited);  // check which number is not visited
	if(!memTable.count(key))
	{
		for(int i=1; i<visited.size(); i++) // i ranges from [1, maxChoosableInteger]
		{
			if(visited[i]) continue;
			visited[i] = true;
			if(!memdfs_canWin(visited, memTable, target-i))  // if next player is not able to win
			{
				memTable[key] = true;  // memorization
				visited[i] = false;  // back-tracking
				return true;
			}
			visited[i] = false; // back-tracking
		}
		memTable[key] = false;  // memorization
	}
	return memTable[key];
}

bool canIWin(int maxChoosableInteger, int desiredTotal)
{
	if(maxChoosableInteger >= desiredTotal) return true;
	if(desiredTotal > (1 + maxChoosableInteger) * maxChoosableInteger / 2) return false; // impossible to reach this target
	vector<bool> visited(maxChoosableInteger + 1, false); // used to store which number is used
	unordered_map<int, bool> memTable;
	return memdfs_canWin(visited, memTable, desiredTotal);
}



