/*
 * BaseballScore.cpp
 *
发一个亚麻社招 OA 的面经，OA是在amcat上做的，包括75 min Coding + 15 min Culture + 5 min Feedback，其实开始做coding之后时间有90min
Q1 丢棒球砸砖块，貌似是地里没有出现过的题，输入是一个字符串数组，每一个值可能是一个整数，或者Z，或者X，或者+。
整数代表现在拿的分，X代表当前成绩是前一个分数Double，+代表当前成绩是前两个的和，Z代表移除前一个成绩，然后要求的是最后的总成绩
例子： 输入 ["5", "-2", "4", "Z", "X", 9, "+", "+"]
输出 27.
5 : sum = 5.
-2 : sum = 5 - 2 = 3
4 : sum = 3 + 4 = 7
Z : sum = 7 - 3 = 4
X : sum = 3 + -2 * 2 = -1 (因为4被移除了，前一个成绩是-2). from: 1point3acres.com/bbs
9 : sum = -1 + 9 = 8
+ : sum = 8 + 9 - 4 = 13 (前两个成绩是9和-4)
+ : sum = 13 + 9 + 5 = 27 (前两个成绩是5 和 9)
 */

#include <vector>
#include <stack>

using namespace std;

int scoreBalance(string score)
{
	stack<int> log;
	int sum;
	for(char c : score)
	{
		if(c >= '0' && c <'9')
		{
			log.push(c-'0');
			sum += c-'0';
		}
		else if(c == 'Z')
		{
			sum -= log.top();
			log.pop();
		}
		else if(c == 'X')
		{
			sum += log.top()*2;
			log.push(log.top()*2);
		}
		else
		{
			int top = log.top();
			log.pop();
			int top2 = log.top();
			log.push(top);
			log.push(top + top2);
			sum += top + top2;
		}
	}
	return sum;
}


