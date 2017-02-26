/******************************************************************************/
/**
* Question: #165 Compare Version Numbers
* Compare two version numbers version1 and version2
* If version1 > version2 return1, if version1 < version2 return -1, otherwise return 0.
*
* You may assume that the version strings are non-empty and contain only digits and the . character.
* The . character does not represent a decimal point and is used to separate number sequences.
* For instance, 2.5 is not "two and a half" or  "half way to version three", it is the fifth
* second-level revision of the second first-level revision.
*
* Here is an example of version numbers ordering:
* 0.1 < 1.1 < 1.2 < 13.37
*/
/*****************************************************************************/

#include <iostream>
#include <string>


using namespace std;

class VersionComp {
public :
	int versionComp(string version1, string version2)
	{
		int end1, end2;
		int num1, num2;

		while (!version1.empty() || !version2.empty())
		{
			end1 = version1.find('.');
			if (end1 != -1) {
				num1 = strToNum(version1.substr(0, end1));
				version1 = version1.substr(end1 + 1);
			}
			else {
				num1 = strToNum(version1);
				version1 = "";
			}
			//cout << num1 << "   " << version1 << endl;

			end2 = version2.find('.');
			if (end2 != -1) {
				num2 = strToNum(version2.substr(0, end2));
				version2 = version2.substr(end2 + 1);
			}
			else {
	
				num2 = strToNum(version2);
				version2 = "";
			}

			//cout << num2 << "   " << version2 << endl;

			if (num1 > num2) return 1;
			else if (num1 < num2) return -1;
		}

		if (!version1.empty()) return 1;
		else if (!version2.empty()) return -1;
		return 0;
	}

	int strToNum(string s)
	{
		cout << "string passing to strToNum is " << s << endl;
		// remove heading 0's
		while (s[0] == '0') s = s.substr(1);
		if (s.empty()) return 0;
		int sum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ') continue;
			sum *= 10;
			sum += s[i]-'0';
		}
		return sum;
	}
};

/*
int main(int argc, char * argv[])
{
	int res;
	string version1 = "20.12.34.56";
	string version2 = "20.12.34.54";

	string version3 = "1.34";
	string version4 = "0020.12.34.56";
	string version5 = "20";

	VersionComp verComp;

	//res = verComp.versionComp(version1, version2);
	//cout << res << endl;

	//res = verComp.versionComp(version1, version3);
	//cout << res << endl;

	res = verComp.versionComp(version1, version5);
	cout << res << endl;

	system("pause");
}
*/