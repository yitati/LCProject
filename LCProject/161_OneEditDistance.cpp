/******************************************************************************/
/*
* Question: #161 One Edit Distance
* Given two strings S and T, determine if they are both one edit distance apart.
*/
/*****************************************************************************/

#include <string>

using namespace std;


// there are three possibilities when s and t has edit distance of 1
// 1. replace one char
// 2. delete one char from s
// 3. delete one char from t
bool isOneEditDistance(string s, string t) {
	// we need to loop to the min value of the two lengths
	for (int i = 0; i < min(s.length(), t.length()); i++) {
		if (s[i] != t[i]) {
			if (s.length() == t.length()) {
				return s.substr(i + 1) == t.substr(i + 1);
			}
			if (s.length() < t.length()) {
				return s.substr(i) == t.substr(i + 1);
			} else
				return s.substr(i + 1) == t.substr(i);
		}
	}
	// !! all previous chars are same
	return s.length() - t.length() == 1 || t.length() - s.length() == 1;
}
