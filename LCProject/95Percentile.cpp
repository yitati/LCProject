/*
Given a list of integers representing the lengths of urls, find the 95 percentile of all lengths 
(95% of the urls have lengths <= returned length).

Assumptions

The maximum length of valid url is 4096

The list is not null and is not empty and does not contain null

Examples

[1, 2, 3, ..., 95, 96, 97, 98, 99, 100], 95 percentile of all lengths is 95.
*/

#include <vector>

using namespace std;

int percentile(vector<int> values)
{
	int len[4096] = { 0 };
	for (int val : values) len[val]++;

	int tail = 0;
	int target = 0.05*(float)values.size();
	for (int i = 4095; i >= 0; i--)
	{
		tail += len[i];
		if (tail > target)
		{
			return i;
		}
	}
	return 0;
}