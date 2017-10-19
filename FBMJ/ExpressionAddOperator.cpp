/*
 * ExpressionAddOperator.cpp
 *
Given an expression formed by numbers, given operator '+', '-' and '*'. return the string that can add up to a
given target.
 */


#include <vector>
#include <string>

using namespace std;

/*
 * Each substring of the num can be taken as a number, and we can do addition, substraction and mutiplexation
 * upon it with the next number.
 * So we can use dfs recursion to calculate the current substring with the previous result.
 * But one thing to notice, since we can also do '*' operation, so need to also keep the last num that we
 * calculated.
 *
 * Time complexity: O(4^Len) since at each point we can do 4 different operations, + / - / * / group with other number
 * there will be len-1 space available to add all the operators and total time complexity will be O(4^len-1)
 */

vector<string> results;

void expressionAddOp(const string num, const int target, long long currVal, long long prevVal, string curr, unsigned int pos)
{
	if(pos >= num.size())
	{
		if(currVal == target)
		{
			results.push_back(curr);
		}
		return;
	}
	long long nextVal = 0;
	for(unsigned int i=pos; i<num.size(); i++)
	{
		nextVal = nextVal*10 + num[i]-'0';
		if(curr.empty())
		{
			expressionAddOp(num, target, nextVal, nextVal, to_string(nextVal), i+1);
		}
		else
		{
			// if we do add
			expressionAddOp(num, target, currVal+nextVal, nextVal, curr + "+" + to_string(nextVal), i+1);
			// if we do minuse
			expressionAddOp(num, target, currVal-nextVal, -nextVal, curr + "-" + to_string(nextVal), i+1);
			// if we do multiply
			expressionAddOp(num, target, currVal-prevVal+prevVal*nextVal, prevVal*nextVal, curr + "*" + to_string(nextVal), i+1);
		}
		if(num[pos] == '0') break; // 0 can not lead any number, pitfall here!!!
	}

}

vector<string> addOperators(string num, int target)
{
	expressionAddOp(num, target, 0, 0, "", 0);
	return results;
}


