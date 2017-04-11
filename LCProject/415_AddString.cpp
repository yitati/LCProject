/******************************************************************************/
/*
* Question: #415 Add String
* Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

* Note: 
* 1.The length of both num1 and num2 is < 5100.
* 2.Both num1 and num2 contains only digits 0-9.
* 3.Both num1 and num2 does not contain any leading zero.
* 4.You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
/*****************************************************************************/

#include <string>
using namespace std;

string addStrings(string num1, string num2)
{
	if (num1.empty()) return num2;
	if (num2.empty()) return num1;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	string result;
	int carry = 0, sum = 0;
	for (int i = 0, j = 0; i<num1.length() || j <num2.length() || carry > 0; i++, j++)
	{
		int opt1 = i >= num1.length() ? 0 : num1[i] - '0';
		int opt2 = j >= num2.length() ? 0 : num2[j] - '0';
		sum = carry + opt1 + opt2;
		carry = sum / 10;
		sum %= 10;
		result.push_back(sum + '0');
	}
	reverse(result.begin(), result.end());
	return result;
}