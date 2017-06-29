/******************************************************************************/
/**
* Question: #166 Fraction To Recurring Decimal
* Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
* If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".

* Hint:
* No scary math, just apply elementary math knowledge. Still remember how to perform a long division?
* Try a long division on 4/9, the repeating part is obvious. Now try 4/333. Do you see a pattern?
* Be wary of edge cases! List out as many test cases as you can think of and test your code thoroughly.
*/
/*****************************************************************************/

#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

string fractionToDecimal(int numerator, int denominator) 
{
	if (denominator == 0) return "INT_MAX";
	string result;
	int sign = ((numerator > 0) ^ (denominator > 0) == 0) ? 1 : -1;
	if (sign == -1) result += "-";
	long long num = abs(numerator), den = abs(denominator), quo = 0;

	if (num >= den)
	{
		quo = num / den;
		result += to_string(quo);
		num -= quo * den;
	}

	if (num == 0) return result;
	if (result.empty() || result[result.size()-1] == '-') result.push_back('0');
	result.push_back('.');
	unordered_map<int, int> table;
	table[num] = result.size();
	while (num)
	{
		num = num * 10;
		quo = num / den;
		if (table.count(num))
		{
			int start = table[num];
			result.insert(result.begin() + start, '(');
			result.push_back(')');
			return result;
		}
		else
		{
			table[num] = result.size();
			result.push_back(quo + '0');
		}
		num = num - quo * den;
		if (num == 0)
		{
			return result;
		}
	}
}

/*
int main(int argc, char ** argv)
{
	cout << fractionToDecimal(4, 9) << endl;
	cout << fractionToDecimal(4, 333) << endl;
	cout << fractionToDecimal(2, 1) << endl;
	cout << fractionToDecimal(1, 2) << endl;
	cout << fractionToDecimal(-10, 2) << endl;
	cout << fractionToDecimal(1, 333) << endl;
	cout << fractionToDecimal(1, 6) << endl;

	system("pause");
}
*/