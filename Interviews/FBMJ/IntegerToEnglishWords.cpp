/******************************************************************************
* Question: #273 Integer To English Words
* company tag: Facebook
* Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1. 
For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

* Hint:
* 1.Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
* 2.Group the number by thousands (3 digits). You can write a helper function that takes a number 
* less than 1000 and convert just that chunk to words.
* 3.There are many edge cases. What are some good test cases? Does your code work with input such as 0? 
* Or 1000010? (middle chunk is zero and should not be printed out)
*
* Follow-up:
* company tag: Facebook
* What if we want to add ',' and "and" ?
*****************************************************************************/

#include <string>

using namespace std;

string under20[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
					"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
					"Nineteen"};
string above20[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string intToString(int num)
{
	string result;
	if(num >= 1000000000)
	{
		result = intToString(num/1000000000) + " Billion" + intToString(num%1000000000);
	}
	else if(num >= 1000000)
	{
		result = intToString(num/1000000) + " Million" + intToString(num%1000000);
	}
	else if(num >= 1000)
	{
		result = intToString(num/1000) + " Thousand" + intToString(num%1000);
	}
	else if(num >= 100)
	{
		result = intToString(num/100) + " Hundred" + intToString(num%100);
	}
	else if(num >= 20)
	{
		result = " " + above20[num/10] + intToString(num%10);
	}
	else if(num >= 1)  // pitfull here!!!!!
	{
		result = " " + under20[num];
	}
	return result;
}

string numberToWords(int num)
{
	if(num == 0) return "Zero";
	return intToString(num).substr(1);
}
