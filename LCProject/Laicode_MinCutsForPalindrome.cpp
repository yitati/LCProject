/*
 * Laicode_MinCutsForPalindrome.cpp
Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. Determine the fewest cuts needed for a palindrome partitioning of a given string.

Assumptions

The given string is not null
Examples

“a | babbbab | bab | aba” is a palindrome partitioning of “ababbbabbababa”.

The minimum number of cuts needed is 3.
 */

#include <string>
#include <algorithm>

using namespace std;

int minCuts(string input)
{
	if(input.size() < 2) return 0;
	vector<int> cuts(input.size());
	vector<vector<bool>> isPalindrome(input.size(), vector<bool>(input.size()));

	for(int rhs = 0; rhs < input.size(); rhs++){
		int cut = rhs;
		for(int lhs = rhs; lhs >= 0; lhs--){
			if(input[lhs] == input[rhs] && (lhs +1 >= rhs || isPalindrome[lhs+1][rhs-1])){
				isPalindrome[lhs][rhs] = true;
				cut = lhs == 0 ? 0 : min(cut, cuts[lhs-1] + 1);
			}
		}
		cuts[rhs] = cut;
	}

	return cuts[input.size()-1];
}


