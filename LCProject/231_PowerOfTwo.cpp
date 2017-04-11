/******************************************************************************/
/*
* Question: #231 Power Of Two
* Given an integer, write a function to determine if it is a power of two.
*/
/*****************************************************************************/

#include <iostream>

using namespace std;

bool isPowerOfTwo(int n) 
{
	int x = n, y = n - 1;
	while (x || y)
	{
		if ((x&1) & (y&1) != 0) return false;
		x >>= 1;
		y >>= 1;
	}
	return true;
}

bool isPowerOfTwo2(int n)
{
	return (n>0) && !(n&(n - 1));
}

/*
int main(int argc, char ** argv)
{
	cout << isPowerOfTwo(1) << endl;
	cout << isPowerOfTwo(2) << endl;
	cout << isPowerOfTwo(10) << endl;
	cout << isPowerOfTwo(16) << endl;

	system("pause");
}
*/