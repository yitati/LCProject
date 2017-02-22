/******************************************************************************/
/*
* Question: #43 Multiply String
* Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
* Note:
* The length of both num1 and num2 is < 110.
* Both num1 and num2 contains only digits 0-9.
* Both num1 and num2 does not contain any leading zero.
* You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
/*****************************************************************************/

#include <string>

using namespace std;

string multiplyStrWithOneNum(string num1, string num2, int index)
{
	string result;
	int opt = num2[index] - '0', len1 = num1.length(), len2 = num2.length();
	int i = len1 - 1, carry = 0, k = len2 - index - 1;
	if (opt == 0) return result;
	while (i >= 0)
	{
		int mul = (num1[i] - '0') * opt + carry;
		carry = mul / 10;
		mul = mul % 10;
		result.insert(result.begin(), mul + '0');
	}
	while (k)
	{
		result.push_back('0');
		k--;
	}

	return result;
}

string addTwoString(string num1, string num2)
{
	string result;
	if (num1.empty()) return num2;
	if (num2.empty()) return num1;
	int len1 = num1.length(), len2 = num2.length();
	int i = len1 - 1, j = len2 - 1, carry = 0;
	while (i >= 0 || j >= 0)
	{
		int sum = (i >= 0 ? num1[i] - '0': 0) + (j >=0 ? num2[j] - '0' : 0);
		carry = sum / 10;
		sum %= 10;
		result.insert(result.begin(), sum);
		i--; j--;
	}
	return result;
}

string multiply(string num1, string num2) 
{
	string result;
	if (num1.empty() || num2.empty()) return result;
	if (num1[0] == 0 || num2[0] == 0) return "0";
	int len1 = num1.length(), len2 = num2.length();
	

}