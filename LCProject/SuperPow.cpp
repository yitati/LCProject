/******************************************************************************/
/*
* Question: #372 Super Pow
* Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer 
* given in the form of an array. 

Example1: 
a = 2
b = [3]

Result: 8

Example2: 
a = 2
b = [1,0]

Result: 1024

*/
/*****************************************************************************/

#include<vector>

using namespace std;

const int base = 1337;
// calculate a^k with mode
int powermode(int a, int k)
{
	int result = 1;
	a %= base;
	for (int i = 1; i <= k; i++)
	{
		result = (result * a) % base;
	}
	return result;
}

// from ith digit to i+1 th digit we get
// f(a, i+1) = f(f(a, i), 10)*f(a, i+1) % base
int superPow(int a, vector<int>& b)
{
	if (b.empty()) return 1;
	int result = 1;
	for (int i = 0; i<b.size(); i++)
	{
		result = (powermode(result, 10)*powermode(a, b[i])) % base;
	}
	return result;
}