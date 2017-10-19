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

/*
if str1 > str2 return 1
if str1 < str2 return -1
if str1 == str2 return 0
*/
int stringWithNumCompare(string& str1, int pos1, string& str2, int pos2) {
  if (pos1 >= str1.size() && pos2 >= str2.size()) return 0;
  else if (pos1 >= str1.length()) return -1;
  else if (pos2 >= str2.length()) return 1;

  if (isAlpha(str1[pos1]) && isNum(str2[pos2]))
  {
    return -1;
  }
  else if (isNum(str1[pos1]) && isAlpha(str2[pos2]))
  {
    return 1;
  }
  else if (isAlpha(str1[pos1]) && isAlpha(str2[pos2]))
  {
    if (str1[pos1] > str2[pos2]) return 1;
    else if (str1[pos1] < str2[pos2]) return -1;
    else return stringWithNumCompare(str1, pos1 + 1, str2, pos2 + 1);
  }
  else // both number
  {
    int i = pos1, j = pos2;
    int num1 = 0, num2 = 0;
    while (i < str1.length() && isNum(str1[i])) num1 = num1 * 10 + str1[i++] - '0';
    while (j < str2.length() && isNum(str2[j])) num2 = num2 * 10 + str2[j++] - '0';

    if (num1 > num2) return 1;
    else if (num1 < num2) return -1;
    else return stringWithNumCompare(str1, i, str2, j);
  }
  return 0;
}


int compStr(string input1, string input2)
{
  return stringWithNumCompare(input1, 0, input2, 0);
}



int main(int argc, char ** argv)
{
 cout << compStr("abc0000yyy", "abc0yyy") <<endl;
}


