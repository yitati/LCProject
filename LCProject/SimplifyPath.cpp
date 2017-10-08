/******************************************************************************
* Question: #71 Simplify Path
* company tag: Facebook
* Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

* Corner Cases:
* Did you consider the case where path = "/../"?
* In this case, you should return "/".
* Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
* In this case, you should ignore redundant slashes and return "/home/foo".
*
*****************************************************************************/

#include <string>
#include <stack>
#include <iostream>

using namespace std;

string simplifyPath(string path) 
{
	string result;
	if (path.empty()) return result;

	stack<string> table;
	int len = path.length(), i = 0; 
	while (i < len)
	{
		while (i < len && path[i] == '/') i++;
		int start = i;
		while (i < len && path[i] != '/') i++;
		string curr = path.substr(start, i - start);
		if (curr.empty() || curr == ".") continue;
		else if (curr == "..")
		{
			if (!table.empty()) table.pop();
		}
		else
		{
			table.push(curr);
		}
	}

	while (!table.empty())
	{
		string curr = table.top();
		table.pop();
		result = "/" + curr + result;
	}

	if (result.empty()) result = "/";

	return result;
}

/*
int main(int argc, char ** argv)
{
	string input = "/home/";
	string result = simplifyPath(input);
	cout << result << endl;
	system("pause");
}
*/
