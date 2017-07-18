/******************************************************************************
* Question: #125 Valid Palindrome
* company tag: Facebook
* Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
* Note:
* Have you consider that the string might be empty? This is a good question to ask during an interview.
* For the purpose of this problem, we define empty string as valid palindrome.
*****************************************************************************/

#include <string>
#include <iostream>

using namespace std;

bool isSameLetter(char x, char y)
{
	if (x == y) return true;
	if ((x >= '0' && x <= '9') || (y >= '0' && y <= '9')) return false;
	return abs(x - y) == 32 ? true : false;
}

inline bool isAlphanumeric(char x)
{
	return ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9'));
}

bool isPalindrome(string s) 
{
	if (s.empty() || s.size() == 1) return true;
	int len = s.length();
	int i = 0, j = len-1;
	while(i < j)
	{
		if (!isAlphanumeric(s[i])) {
			i++; 
			continue;
		}
		
		if (!isAlphanumeric(s[j])) {
			j--;
			continue;
		}
		if (!isSameLetter(s[i], s[j])) return false;
		i++;
		j--;
	}
	
	return true;
}

/*
int main(int argc, char ** argv)
{
	cout << isPalindrome("aA") << endl;

	system("pause");
}
*/
