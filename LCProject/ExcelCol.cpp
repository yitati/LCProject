/******************************************************************************/
/**
* Question: #168 Excel Sheet Column Title
* Given a positive integer, return its corresponding column title as appear in an Excel sheet.
*
* For example:
*   1 -> A
*   2 -> B
*   3 -> C
*   ...
*   26 -> Z
*   27 -> AA
*   28 -> AB
*
*
* Question: #171 Excel Sheet Column Number
* Related a column title as appear in an Excel sheet, return its corresponding column number.
*
* For example:
*   A -> 1
*   B -> 2
*   C -> 3
*   ...
*   Z -> 26
*   AA -> 27
*   AB -> 28
*
*/
/*****************************************************************************/

#include <iostream>
#include <string>

using namespace std;


class ExcelCol {
public:

	string convertToTitle(int n) {
		if (n <= 0) return "";
		string col;
		int r;
		while (true) {
			r = (n - 1) % 26;
			col.insert(0, 1, 'A' + r);
			n = (n - 1) / 26;
			if (n == 0) break;
		}
		return col;
	}

	int titleToNumber(string s) {
		int sum = 0;
		for (int i = 0; i<s.size(); i++)
		{
			char d = s[i] - 'A' + 1;
			sum *= 26;
			sum += d;
		}
		return sum;
	}
};

/*
int main(int argc, char * argv[])
{
	cout << "Main starts" << endl;
	ExcelCol excelTrans;

	cout << excelTrans.convertToTitle(0) << endl;  // ""
	cout << excelTrans.convertToTitle(1) << endl;  // "A"
	cout << excelTrans.convertToTitle(15) << endl; // "O"
	cout << excelTrans.convertToTitle(26) << endl; // "Z"
	cout << excelTrans.convertToTitle(28) << endl; // "AB"
	cout << excelTrans.convertToTitle(78) << endl; // "BZ"


	cout << excelTrans.titleToNumber("A") << endl; // 1
	cout << excelTrans.titleToNumber("Z") << endl; // 26
	cout << excelTrans.titleToNumber("O") << endl; // 15
	cout << excelTrans.titleToNumber("AB") << endl; // 28
	cout << excelTrans.titleToNumber("BZ") << endl; // 78



	system("pause");

}
*/
