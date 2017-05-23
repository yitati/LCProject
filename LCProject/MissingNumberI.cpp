/*
Given an integer array of size N - 1, containing all the numbers from 1 to N except one, find the missing number.

Assumptions
The given array is not null, and N >= 1

Examples
A = {2, 1, 4}, the missing number is 3
A = {1, 2, 3}, the missing number is 4
A = {}, the missing number is 1
*/

#include <vector>
#include <unordered_set>

using namespace std;

// Solution 1. Math Solution
// expected sum - real sum
int missing1(vector<int> array)
{
	// in case of overflow
	long long expectedSum = 0, realSum = 0;
	int n = array.size() + 1;
	expectedSum = n * (1 + n) / 2;
	for (int num : array)
	{
		realSum += num;
	}
	return expectedSum - realSum;
}

// Solution 2. Hash set solution
int missing2(vector<int> array)
{
	unordered_set<int> table;
	for (int num : array) table.insert(num);
	int n = array.size() + 1;
	for (int i = 1; i <= n; i++)
	{
		if (!table.count(i)) return i;
	}
	return n;
}

// Solution 3. XOR solution
int missing3(vector<int> array)
{
	int n = array.size() + 1, result = 0;
	for (int i = 0; i < n - 1; i++)
	{
		result ^= array[i];
		result ^= (i + 1);
	}
	result ^= n;
	return result;
}
