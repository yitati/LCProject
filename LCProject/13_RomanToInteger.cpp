/******************************************************************************/
/*
* Question: #13 Roman To Integer
* Given a roman numeral, convert it to an integer.
* Input is guaranteed to be within the range from 1 to 3999.
*/
/*****************************************************************************/

#include <string>

using namespace std;

int romanToInt(string s) 
{
	int result = 0;
	int len = s.length();
	for (int i=0; i < len; i++)
	{
		switch (s[i])
		{
		case 'I':
			if (i < len - 1 && (s[i + 1] == 'V' || s[i + 1] == 'X')) result -= 1;
			else result += 1;
			break;
		case 'V':
			result += 5;
			break;
		case 'X':
			if (i < len - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C')) result -= 10;
			else result += 10;
			break;
		case 'L':
			result += 50;
			break;
		case 'C':
			if (i < len - 1 && (s[i + 1] == 'D' || s[i + 1] == 'M')) result -= 100;
			else result += 100;
			break;
		case 'D':
			result += 500;
			break;
		case 'M':
			result += 1000;
			break;
		default:
			break;
		}
	}
	return result;
}