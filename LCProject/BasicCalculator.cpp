/******************************************************************************
* Question: #224 Basic Calculator
* company tag: Facebook
* Implement a basic calculator to evaluate a simple expression string.
* The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, 
* non-negative integers and empty spaces .

* You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23

* Note: Do not use the eval built-in library function. 
*
*****************************************************************************/
#include <string>
#include <stack>

using namespace std;

// there are only two things we want to watch out here, current result (num) and sign
// but everytime we see '(' need to keep both current result and current sign
int calculate(string s)
{
    long long num = 0;
    int sign = 1;
    stack<int> table;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == ' ') continue;
        else if(s[i] == '+')
        {
            sign = 1;
        }
        else if(s[i] == '-')
        {
            sign = -1;
        }
        else if(s[i] == '(')
        {
            table.push(num);
            table.push(sign);
            num = 0;
            sign = 1;
        }
        else if(s[i] == ')')
        {
            int prevSign = table.top();
            table.pop();
            int prevNum = table.top();
            table.pop();
            num = prevNum + prevSign*num;
            sign = 1;
        }
        else
        {
            long long x = 0;
            while(i<s.length() && s[i] >= '0' && s[i] <= '9')
            {
                x = x*10 + s[i++]-'0';
            }
            num += sign*x;
            sign = 1;
            i--;
        }
    }
    return num;
}
