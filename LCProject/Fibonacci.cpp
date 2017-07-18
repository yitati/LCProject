/*
Get the Kth number in the Fibonacci Sequence. (K is 0-indexed, the 0th Fibonacci number is 0 and the 1st Fibonacci number is 1).
Examples
0th fibonacci number is 0
1st fibonacci number is 1
2nd fibonacci number is 1
3rd fibonacci number is 2
6th fibonacci number is 8
Follow-up:
company tag: Facebook
What is fibonacci%10?
*/

// TODO: discuss this with BAOBAO

#include <iostream>

using namespace std;

long fibonacci(int K)
{
	if (K < 2) return K < 0 ? 0 : K;
	long long fn_2 = 0, fn_1 = 1, fn = 0;
	while (K >= 2)
	{
		fn = fn_1 + fn_2;
		fn_2 = fn_1;
		fn_1 = fn;
		K--;
		cout << "fn is "<< fn << "  fn%10 is "<< fn%10 << endl;
	}
	return fn;
}

/*
int main(int argc, char ** argv)
{
	long x = fibonacci(20);
	return 0;
}
*/
