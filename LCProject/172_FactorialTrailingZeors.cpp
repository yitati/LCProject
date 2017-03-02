/******************************************************************************/
/*
* Question: #172 Factorial Trailing Zeors
* Given an integer n, return the number of trailing zeroes in n!.
* Note: Your solution should be in logarithmic time complexity.
*/
/*****************************************************************************/

#include <iostream>

using namespace std;

int trailingZeroes(int n) 
{
	int count = 0;
	while (n)
	{
		n = n / 5;
		count += n;
	}
	return count;
}

/*
int main(int argc, char ** argv)
{
	cout << trailingZeroes(0) << endl;
	cout << trailingZeroes(5) << endl;
	cout << trailingZeroes(20) << endl;
	cout << trailingZeroes(25) << endl;
	cout << trailingZeroes(50) << endl;
	cout << trailingZeroes(60) << endl;
	cout << trailingZeroes(75) << endl;
	cout << trailingZeroes(125) << endl;

	system("pause");
}
*/