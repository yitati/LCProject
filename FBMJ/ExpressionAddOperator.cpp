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
 */

vector<string> results;

// TODO - time complexity? BAOBAO

void dfsAddOperator(const string& num, int pos, int target, string result, int prevNum, int currSum)
{
	if(pos >= num.length())
	{
		if(currSum == target)
		{
			results.push_back(result);
		}
		return;
	}

	int nextNum = 0;
	for(int i = pos; i<num.length(); i++)
	{
		nextNum = nextNum * 10 + num[i]- ' 0';
		if(result.empty())
		{
			dfsAddOperator(num, i+1, target, num.substr(0, i+1), nextNum, nextNum);
		}
		else
		{
			// if we add '+' to this position
			dfsAddOperator(num, i+1, target, result + '+' + num.substr(pos, i-pos+1), nextNum, currSum + nextNum);
			// if we add '-' to this position
			dfsAddOperator(num, i+1, target, result + '-' + num.substr(pos, i-pos+1), -nextNum, currSum - nextNum);
			// if we add '*' to this position
			dfsAddOperator(num, i+1, target, result + '*' + num.substr(pos, i-pos+1), prevNum * nextNum, currSum - prevNum + prevNum*nextNum);
		}
	}
}

vector<string> addOperators(string num, int target)
{
	dfsAddOperator(num, 0, target, "", 0, 0);
	return results;
}


