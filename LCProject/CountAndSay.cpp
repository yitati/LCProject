/******************************************************************************/
/*
* Question: #38 Count And Say
* The count-and-say sequence is the sequence of integers beginning as follows:
* 1, 11, 21, 1211, 111221, ...

* 1 is read off as "one 1" or 11.
* 11 is read off as "two 1s" or 21.
* 21 is read off as "one 2, then one 1" or 1211.
* Given an integer n, generate the nth sequence.

* Note: The sequence of integers will be represented as a string.
*/
/*****************************************************************************/

#include <string>
#include <queue>

using namespace std;

string countAndSay(int n) 
{
	string result;
	if (n < 1) return result;
	result.push_back('1');
	while (n - 1)
	{
		string next;
		int len = result.length(), count = 1;
		for (int i = 0; i < len; i++)
		{
			if (i + 1 < len && result[i] == result[i + 1]) count++;
			else
			{
				if (count > 0) next += to_string(count);
				next += result[i];
				count = 1;
			}
		}
		result = next;
		n--;
	}

	return result;
}