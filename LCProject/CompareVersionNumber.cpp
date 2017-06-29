/******************************************************************************/
/*
* Question: #165 Compare Version Number
* Compare two version numbers version1 and version2.
* If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
* You may assume that the version strings are non-empty and contain only digits and the . character.
* The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level 
revision of the second first-level revision.
Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 13.37
*/
/*****************************************************************************/

#include <string>

using namespace std;

int compareVersion(string version1, string version2)
{
	int len1 = version1.length(), len2 = version2.length();
	int num1 = 0, num2 = 0, i = 0, j = 0;
	while (i < len1 || j < len2)
	{
		while (version1[i] != '.' && i<len1)
		{
			num1 = num1 * 10 + version1[i] - '0';
			i++;
		}
		while (version2[j] != '.' && j<len2)
		{
			num2 = num2 * 10 + version2[j] - '0';
			j++;

		}

		if (num1 > num2) return 1;
		else if (num1 < num2) return -1;
		num1 = 0;
		num2 = 0;
		i++;
		j++;
	}

	return 0;
}