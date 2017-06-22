/******************************************************************************/
/*
* Question: #8 String To Integer (atoi)
* Implement atoi to convert a string to an integer.
* Hint: Carefully consider all possible input cases. If you want a challenge, 
* please do not see below and ask yourself what are the possible input cases.
* Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
* You are responsible to gather all the input requirements up front.
*/
/*****************************************************************************/

#include <string>

using namespace std;

int myAtoi(string str)
{
	int i = 0, sign = 1;
	long long result = 0;

	while (i < str.length() && str[i] == ' ') i++;
	if (str[i] == '+' || str[i] == '-') sign = str[i++] == '-' ? -1 : 1;
	while (i < str.length() && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if (sign * result >= INT_MAX) return INT_MAX;
		if (sign * result <= INT_MIN) return INT_MIN;
	}
	return result*sign;
}