/******************************************************************************/
/*
* Question: #500 Keyboard Row
* Given a List of words, return the words that can be typed using letters of 
* alphabet on only one row's of American keyboard like the image below. 
Example 1:

Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

* Note:
* 1.You may use one character in the keyboard more than once.
* 2.You may assume the input string will only contain letters of alphabet.
*/
/*****************************************************************************/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> findWords(vector<string>& words) {
	vector<string> result;
	unordered_map<char, int> table;
	string keyboardRow[3] = { "qwertyuiop", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM" };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < keyboardRow[i].length(); j++)
		{
			char c = keyboardRow[i][j];
			table[c] = i;
		}
	}

	for (int i = 0; i < words.size(); i++)
	{
		int level = table[words[i][0]], len = words[i].length();
		bool match = 1;
		for (char c : words[i])
		{
			if (table[c] != level)
			{
				match = 0;
				break;
			}
		}
		if (match) result.push_back(words[i]);

	}

	return result;
}