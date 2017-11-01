#include <string>
#include <stack>

using namespace std;

/*
 * Basic Calculator I: only +, -, ( and )
 * solutiion is we keep two gloal, num and sign.
 * corner case
 */
int calculate(string s)
{
    long long num = 0, sign = 1;
    stack<long long> table;
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
        else if(s[i] == '(')  // we need both the sign and num to keep previous status
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
            num = prevNum + prevSign * num;
        }
        else
        {
            long long x = 0;
            while(i < s.length() && s[i] >= '0' && s[i] <= '9')
            {
                x = 10*x + s[i++] - '0';
            }
            num += sign * x;
            sign = 1;
            i--;   // pitfall here!!!
        }
    }
    return num;
}


/*
 * Basic Calculator II:
 */


