/*
Evaluate a to the power of b, assuming both a and b are integers and b is non-negative.

Examples:
- power(2, 0) = 1
- power(2, 3) = 8
- power(0, 10) = 0
- power(-2, 5) = -32

Corner Cases:
- What if the result is overflowed?

*/
   
#include <iostream>

using namespace std;

long power_recursion(int a, int b)
{
	if (b == 0) return 1;
	int part = power_recursion(a, b / 2);
	if (b % 2 == 0) return part*part;
	else return a*part*part;
}

long power_iteration(int a, int b)
{
	if (b == 0) return 1;
	int base = a;
	int result = 1;
	while (b > 0)
	{
		int fac = b & 0x01;
		if (fac) result *= base;
		b >>= 1;
		base *= base;
	}

	return result;
}

/*
int main(int argc, char ** argv)
{
	cout << "Test power_recursion " << endl;
	cout << power_recursion(2, 0) << endl; // expect 1
	cout << power_recursion(2, 3) << endl; // expect 8
	cout << power_recursion(0, 10) << endl; // expect 0
	cout << power_recursion(-2, 5) << endl; // expect 32
	cout << endl;

	cout << "Test power_iteration " << endl;
	cout << power_iteration(2, 0) << endl; // expect 1
	cout << power_iteration(2, 3) << endl; // expect 8
	cout << power_iteration(0, 10) << endl; // expect 0
	cout << power_iteration(-2, 5) << endl; // expect 32
	cout << endl;

	system("pause");

}
*/