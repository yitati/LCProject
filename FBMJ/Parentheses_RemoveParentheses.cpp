/*
 * Remove invalid parentheses
 * remove the least invalid parentheses and get one valid parenthese string
 */

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

/****************************** FBMJ ***********************************/
/*
balance parentheses in a string
例子：
"(a)()" -> "(a)()"
"((bc)" -> "(bc)"
")))a((" -> "a"
"(a(b)" ->"(ab)" or "a(b)"

we can simply use a counter to indicate the status of left and right numbers,
if we see an '{' then increase the counter and if we see an '}' then we decrease
the counter.
When counter < 0 that means we have extra '}', then remove the current one and increase the conter.

Then do the same sweep from right to left to remove extra '}'

so we want to have a general function to do sweep from one direction, reverse the string
and sweep from left to right using same trick
*/

string removeInvalidPar(string& input, const vector<char>& par)
{
  int cnt = 0;
  // use two pointers to do the search and copy
  int search = 0, copy = 0;
  while(search < input.length())
  {
    if(input[search] == par[0]) cnt++;
    else if(input[search] == par[1]) cnt--;
    if(cnt >= 0)
    {
      input[copy++] = input[search++];
    }
    else // remove this char and increase the cnt
    {
      search++;
      cnt++;
    }
  }
  input.resize(copy);
  return input;
}

string balanceParentheses(string input)
{
  vector<char> par = {'(', ')'};
  input = removeInvalidPar(input, par);
  swap(par[0], par[1]);
  reverse(input.begin(), input.end());
  input = removeInvalidPar(input, par);
  reverse(input.begin(), input.end());
  return input;
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





