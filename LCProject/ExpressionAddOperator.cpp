/*****************************************************************************************
 * Question #282 Expression Add Operator
 * Given a string that contains only digits 0-9 and a target value, return all possibilities to
 * add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples:
"123", 6 -> ["1+2+3", "1*2*3"]
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []

 *****************************************************************************************/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

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
		if(num[pos] == '0') break; // 0 can not lead any number
	}

}

vector<string> addOperators(string num, int target)
{
	expressionAddOp(num, target, 0, 0, "", 0);
	return results;
}

/*
int main(int argc, char ** argv)
{
	string num = "123";
	int target = 6;

	results = addOperators(num, target);
	for(unsigned int i=0; i<results.size(); i++)
	{
		cout << results[i] << endl;
	}
}
*/



