/*
Given an array of integers (without any duplicates), shuffle the array such that all permutations are equally likely to be generated.

Assumptions
The given array is not null
*/

#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void solve(vector<int>& input)
{
	int n = input.size();
	for (int base = n; base > 0; base--)
	{
		int r = rand() % base;
		swap(input[r], input[base - 1]);
	}
}
