/******************************************************************************/
/*
* Question: #9 Palindrome Number
* Determine whether an integer is a palindrome. Do this without extra space.

* Some hints:
* Could negative integers be palindromes? (ie, -1)

* If you are thinking of converting the integer to string, note the restriction of using extra space.

* You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", 
* you know that the reversed integer might overflow. How would you handle such case?

* There is a more generic way of solving this problem.
*/
/*****************************************************************************/

#include <iostream>

using namespace std;

bool isPalindrome(int x) 
{
	if (x < 0) return false;
	long long num = x;
	if (num / 10 == 0) return true;
	// base is the MSB
	long long base = 10;
	while (base * 10 <= num) base *= 10;
	while (num)
	{
		if ((num / base) != (num % 10)) return false;
		num = (num % base) / 10;
		base /= 100;
	}
	return true;
}

/*
int main(int argc, char ** argv)
{
	cout << isPalindrome(1410110141) << endl;
	//cout << isPalindrome(1) << endl;
	//cout << isPalindrome(11) << endl;
	//cout << isPalindrome(121) << endl;

	system("pause");

}
*/