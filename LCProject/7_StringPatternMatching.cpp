// Given a text txt[0..n-1] and a pattern pat[0..m-1], 
// write a function search(char pat[], char txt[]) that 
// prints all occurrences of pat[] in txt[]. 
// You may assume that n > m.

#include <string>

using namespace std;

// 1 - Native Solution
int stringMatchingI(string haystack, string needle)
{
	int start = 0, i = 0;
	if (haystack.empty()) return needle.empty() ? 0 : -1;
	if (needle.empty()) return 0;
	for (start = 0; start + needle.length() <= haystack.length(); start++)
	{
		if (haystack[start] != needle[0]) continue;
		for (i = 0; i < needle.size(); i++)
		{
			if (haystack[start + i] != needle[i]) break;
		}
		if (i == needle.size()) return start;
	}
	return -1;
}

// Rabin - Karp algorithm, which is actually a sliding window problem, it has limitations though
// TODO
int stringMatchingII(string haystack, string needle)
{

	return 0;
	// calculate the hash value for the pattern


}