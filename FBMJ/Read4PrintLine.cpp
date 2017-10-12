#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

const string inputLine = "this is line1\nthis is line2\nthis is line3\nthis is line4\n";

int read4k(char* buf) {
  int i;
  for (i=0; i<min(4096, (int)inputLine.size()); i++) {
    buf[i] = inputLine[i];
  }
  return i;
}

/*
Given a function read4k() (return a string 4000 length) make a function printLine() that can print line (break by '\n')
*/
class PrintLn
{
public:
  PrintLn()
  {
    pos = 0;
    readCnt = 0;
  }

  void printLine()
  {
    string line;
    if(pos >= readCnt)
    {
      readCnt = read4k(buf);
      pos = 0;
    }

    while(pos < readCnt)
    {
      if(buf[pos] != '\n') line.push_back(buf[pos++]);
      else
      {
        pos++;
        break;
      }
    }

    cout << line << endl;
  }

private:
  int pos;
  int readCnt;
  char buf[4096];
};



