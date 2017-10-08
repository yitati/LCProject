/*
 * StringWithNumCompare.cpp
 *
让实现一个比较两道字符串的方法；前提是让字符串分block比较，相连的字母组成一个block，相连的数字组成一个block.
两个字符串变成两组block之后对应的block挨个比较，如果对应的block一个是字母一个是数字，那么字母小于数字；如果对应的block都是字母，
用的是String的标准的比较方法；如果对应的两个block都是数字，那么比较数字的绝对值大小。
 */

/*
 * block compare function, return
 * -1 if a < b
 * 0  if a ==  b
 * 1  if a > b
 */


// TODO today

#include <string>

using namespace std;

inline bool isAlpha(char c)
{
	return (c >= 'a' && c <= 'z') || (c >='A' && c <= 'Z');
}

inline bool isNum(char c)
{
	return c >= '0' && c <= '9';
}

int stringWithNumCompare(string& str1, int pos1, string& str2, int pos2)
{
	if(pos1 >= str1.size() && pos2 >= str2.size()) return 0;
	else if(pos1 >= str1.length()) return -1;
	else if(pos2 >= str2.length()) return 1;

	int i = pos1, j = pos2;
	if(isAlpha(str1[pos1]) && isNum(str2[pos2]))
	{
		return -1;
	}
	else if(isNum(str1[pos1]) && isAlpha(str2[pos2]))
	{
		return 1;
	}
	else
	{
		if(isAlpha(str1[pos1]))  // both alpha
		{
			while(i < str1.length() && isAlpha(str1[i])) i++;
			while(j < str2.length() && isAlpha(str2[j])) j++;

		}
		else // both number
		{

		}
	}

}



