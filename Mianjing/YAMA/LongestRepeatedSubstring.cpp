/*
 * LongestRepeatedSubstring.cpp
 *
 *  Created on: Oct 9, 2017
 *      Author: JoanneY1
 */

/*
longest repeated substring
*/

#include <string>

using namespace std;

bool containsStr(string input, int pos, string sub)
{
  if(pos + sub.length() > input.length()) return false;

  for(unsigned int i=pos; i+sub.length() <= input.length(); i++)
  {
    unsigned int j;
    for(j=0; j<sub.length(); j++)
    {
      if(input[i+j] != sub[j]) break;
    }
    if(j == sub.length()) return true;
  }

  return false;
}


string longestRepeated(string input)
{
  string res;
  int ilen = input.length();
  for(int len=1; len <= ilen/2; len++)
  {
    for(int i=0; i + len * 2 <= ilen; i++)
    {
      string sub = input.substr(i, len);
      if(containsStr(input, i+len, sub))
      {
        res = sub;
        break;
      }
    }
  }
  return res;
}

/*
int main(int argc, char** argv)
{
  cout << "start running"<<endl;
  cout << longestRepeated("GEEKSFORGEEKS") << endl;
  cout << longestRepeated("AAAAAAAAAA") << endl;
}
*/


