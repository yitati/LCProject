/******************************************************************************/
/*
* Question: #383 Ransom Note
* Given an arbitrary ransom note string and another string containing letters from all the magazines, 
* write a function that will return true if the ransom note can be constructed from the magazines ; 
* otherwise, it will return false. 

* Each letter in the magazine string can only be used once in your ransom note. 

* Note:
* You may assume that both strings contain only lowercase letters. 
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/
/*****************************************************************************/

#include <string>
#include <unordered_map>

using namespace std;

bool canConstruct(string ransomNote, string magazine) 
{
	unordered_map<char, int> table;
	for (size_t i = 0; i < magazine.length(); i++)
	{
		table[magazine[i]]++;
	}
	for (size_t i = 0; i < ransomNote.length(); i++)
	{
		if (!table.count(ransomNote[i])) return false;
		else table[ransomNote[i]]--;
		if (table[ransomNote[i]] < 0) return false;
	}
	return true;
}