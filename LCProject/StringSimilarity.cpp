/*
*/

#include <string>

using namespace std;

int similarity(const string word)
{
	int i = 0, j = 0, suf = 1;
	int wordLen = word.length();
	int count = wordLen;
	while (suf < wordLen)
	{
		j = suf;
		while (word[i++] == word[j++]) count++;
		suf++;
		i = 0;
	}
	return count;
}

