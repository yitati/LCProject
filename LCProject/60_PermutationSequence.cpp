/******************************************************************************/
/*
* Question: #60 Permutation Sequence
* The set [1,2,3,…,n] contains a total of n! unique permutations.
* By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):
"123"
"132"
"213"
"231"
"312"
"321"
* Given n and k, return the kth permutation sequence.
* Note: Given n will be between 1 and 9 inclusive.
*/
/*****************************************************************************/

#include <string>
#include <vector>
#include <set>

using namespace std;

// plase review #31 next permutation 

string getPermutation(int n, int k) 
{
	vector<int> factorial(10, 0);
	factorial[0] = 1;
	k--;
	for (int i = 1; i < 10; i++) factorial[i] = factorial[i - 1] * i;
	// an ordered set to store the numbers
	set<int> nums;
	for (int i = 1; i <= n; i++) nums.insert(i);
	string result;
	for (int i = 1; i <= n; i++)
	{
		int kth;
		kth = k / factorial[n - i];
		auto it = nums.begin();
		for (int j = 0; j < kth; j++) it++;
		result.push_back(*it + '0');
		nums.erase(*it);
		k %= factorial[n - i];
	}
	return result;
}