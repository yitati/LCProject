/******************************************************************************/
/*
* Question: #77 Combinations
* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
/*****************************************************************************/

#include <vector>
#include <iostream>
#include <string>

using namespace std;

void readBinaryWatch_dfs(vector<string> & results, int time, int num, int count, int level)
{
	int hour = time, min = time;
	hour >>= 6;
	if (hour > 11) return;
	int minMask = (1 << 6) - 1;
	min &= minMask;
	if (min > 59) return;
	if (count > num) return;
	if (count == num)
	{
		string result = to_string(hour) + ":";
		if (min < 10) result += "0";
		result += to_string(min);
		results.push_back(result);
		return;
	}
	for (int i = level; i < 10; i++)
	{
		if ((time & (1 << i)) != 0) continue;
		time |= (1 << i);
		readBinaryWatch_dfs(results, time, num, count + 1, i + 1);
		time &= ~(1 << i);
	}
}

vector<string> readBinaryWatch(int num)
{
	vector<string> results;
	if (num > 8) return results;
	readBinaryWatch_dfs(results, 0, num, 0, 0);
	return results;
}
