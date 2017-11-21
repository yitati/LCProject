/******************************************************************************/
/*
* Question: #401 Binary Watch
* A binary watch has 4 LEDs on the top which represent the hours (0-11), 
* and the 6 LEDs on the bottom represent the minutes (0-59).

* Each LED represents a zero or one, with the least significant bit on the right.

* Given a non-negative integer n which represents the number of LEDs that are currently on, 
* return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
* Note:
* The order of output does not matter.
* The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
* The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, 
* it should be "10:02".
*/
/*****************************************************************************/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

void readBinaryWatch_dfs(vector<string> & results, int time, int num, int count)
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
		cout << result << endl;
		results.push_back(result);
	}
	for (int i = 0; i < 10; i++)
	{
		if (time & (1 << i) != 0) continue;
		time |= (1 << i);
		readBinaryWatch_dfs(results, time, num, count+1);
		time &= ~(1 << i);
	}
}

vector<string> readBinaryWatch(int num) 
{
	vector<string> results;
	if (num > 8) return results;
	readBinaryWatch_dfs(results, 0, num, 0);
	return results;
}

/*
int main(int argc, char * * argv)
{
	vector<string> results = readBinaryWatch(3);
	for (int i = 0; i < results.size(); i++)
	{
		cout << results[i] << endl;
	}

	system("pause");
}
*/