/******************************************************************************/
/**
* Question: #166 Fraction to Recurring Decimal
* Given two integers representing the numerator and denominator of a fraction,
* return the fraction in string format.
* If the fractional part is repeating, enclose the repeating part in parentheses.
* For example,
*  * Given numerator = 1, denominator = 2, return "0.5"
*  * Given numerator = 2, denominator = 1, return "2"
*  * Given numerator = 2, denominator = 3, return "0.(6)"
*
*  Hint:
*  1. No scary math, just apply elementary math knowledge. Still remember how to perform a long division.
*  2. Try a long division on 4/9, the repeating part is obvious. Now try 4/333. Do you see a pattern?
*  3. Be wary of edge cases! List out any many test cases as you can think of and test your code thoroughly.
*
*/
/*****************************************************************************/

#include <iostream>
#include <string>
#include <map>

using namespace std;


// some words to use : numerator, denominator, quotient, remainder

class FracToDec {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (denominator == 0) return "";

		map<int, int> table; 
		string result;
		int position = 0;
		bool sign;

		if ((numerator > 0 && denominator > 0) || (numerator < 0 && denominator < 0)) sign = true; 
		else sign = false;
		cout << sign << endl;
		
		long long n = abs(numerator);
		long long d = abs(denominator);
		long long q = abs(n / d);
		long long r = n % d;
		
		if (!sign) result += "-";
		result += to_string(q);
		cout << result << endl;
		if (r == 0) return result;
		result.push_back('.');
		position = result.length();

		while (r != 0) {
			r *= 10;

			if (table.find(r) == table.end()) { table[r] = position++; }
			else {
				result.insert(table[r], 1, '(');
				result += ")";
				break;
			}
			q = abs(r / d);
			result += to_string(q);
			r = r % d;

		}

		if (sign == 1) result.insert(0, 1, '-');
		return result;
	}
};

/*
int main(int argc, char * argv[])
{
	cout << "Main starts" << endl;
	FracToDec fracToDec;
	//cout << fracToDec.fractionToDecimal(4, 2) << endl;
	//cout << fracToDec.fractionToDecimal(5, 2) << endl;
	//cout << fracToDec.fractionToDecimal(-4, 2) << endl;
	//cout << fracToDec.fractionToDecimal(-5, 2) << endl;
	//cout << fracToDec.fractionToDecimal(3, 4) << endl;
	//cout << fracToDec.fractionToDecimal(-3, 4) << endl;
	//cout << fracToDec.fractionToDecimal(4, 333) << endl;
	//cout << fracToDec.fractionToDecimal(433, 333) << endl;
	//cout << fracToDec.fractionToDecimal(1, 6) << endl;
	//cout << fracToDec.fractionToDecimal(-1, INT_MIN) << endl;
	cout << fracToDec.fractionToDecimal(INT_MIN, -1) << endl;
	system("pause");

}
*/
