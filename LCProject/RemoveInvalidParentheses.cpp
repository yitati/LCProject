/*******************************************************************************************************
 * Question #301. Remove Invalid Parentheses
 * company tag: Facebook
 * Remove the minimum number of invalid parentheses in order to make the input string valid. Return all
 * possible results.
 * Note: The input string may contain letters other than the parentheses ( and )
 *
 Examples:

"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]

* Follow-up:
* TODO: BAOBAO
* company tag: Facebook
* What if we need to return only one result?

 ******************************************************************************************************/
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

/****************************** FBMJ ***********************************/
/*
 * Generate unique answer once and only once, do not rely on Set !!!
 * We all know how to check a string of parentheses is valid using a stack. Or even simpler use a counter.
 * The counter will increase when it is '(' and decrese when it is ')'. Whenever the couter is negative, we
 * remove ')' than '(' in the prefix.
 * To make the prefix valid, we need to remove a ')'. The problem is: which one?  - The first one!
 * After the removal, the prefix is then valid. We then call the function recursively to solve the rest
 * of the string. However, we need to keep another information: the last removal position. If we do not
 * have this position, we will generate duplicate by removing 2 ')' in two steps only with a different order.
 * For this, we keep tracking the last removal position and only remove ')' after that.
 *
 * Now we may ask. What about '('? What if s="(()(()" in which we need remove '('?
 * The answer is: do same from right to left.
 * However a cleaver idea is: reverse the string and reuse the code!
 */
// O(n) solution to build the result array
void remove(string input, vector<string> results, int curr, int lastr, vector<char>& par)
{
	int counter = 0;
	for(int i = curr; i < input.length(); i++)
	{
		if(input[i] == par[0]) counter++;
		if(input[i] == par[1]) counter--;
		if(counter >= 0) continue;
		for(int j=lastr; j <= curr; j++)
		{
			// TODO with BAOBAO
		}
	}
}

/*****************************  LC problem ************************************/
/*
 * helper function calculateInvalidParenteses
 * calculate the count for unmatched '(' and count of unmatched ')'
 * and fill the reference
 */
void calculateInvalidParentheses(const string s, int& uml, int& umr)
{
	uml = 0;
	umr = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == '(') uml++;
		else if(s[i] == ')')
		{
			if(uml > 0) uml--;
			else umr++;
		}
	}
}

/*
 * helper function that will reconstruct each valid string
 * to avoid duplicate we need to use unordered_set instead of vector here
 */
void buildValidParentheses(const string s, int pos, unordered_set<string>& results, string curr, int lc, int rc, int uml, int umr)
{
	if(pos >= s.length())
	{
		if(uml == 0 && umr == 0 && lc == rc)
		{
			results.insert(curr);
		}
		return;
	}
	if(s[pos] == '(')
	{
		if(uml > 0) buildValidParentheses(s, pos+1, results, curr, lc, rc, uml-1, umr);  // we can skip this '('
		buildValidParentheses(s, pos+1, results, curr+'(', lc+1, rc, uml, umr);   // we can also add this '('
	}
	else if(s[pos] == ')')
	{
		if(umr > 0) buildValidParentheses(s, pos+1, results, curr, lc, rc, uml, umr-1);  // skip this when there is unmatched right
		if(lc > rc) buildValidParentheses(s, pos+1, results, curr + ')', lc, rc+1, uml, umr);  // only when lc > rc we can push it in
	}
	else // other char
	{
		buildValidParentheses(s, pos+1, results, curr + s[pos], lc, rc, uml, umr);
	}

}

vector<string> removeInvalidParentheses(string s)
{
	int uml = 0, umr = 0;
	calculateInvalidParentheses(s, uml, umr);
	unordered_set<string> results;
	buildValidParentheses(s, 0, results, "", 0, 0, uml, umr);
	vector<string> collect;
	for(string result:results)
	{
		collect.push_back(result);
	}
	return collect;
}



