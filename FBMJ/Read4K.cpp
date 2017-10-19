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


/********************** From read4K to read arbitary ****************************/
static char buf4[4096];
static int p4 = 0;
static int n4 = 0;

int Read4096(char * buf)
{
	return 4096;
}

int Read(char * buf, int n)
{
	if(!buf) return 0;
	int count = 0;
	while(count < n)
	{
		if(p4 >= n4)
		{
			n4 = Read4096(buf4);
			p4 = 0;
			if(p4 >= n4) break;    // eof
		}
		while(count < n && p4 < n4)
		{
			int offset = min(n-count, n4-p4);
			// memcpy(dest, source, size)
			memcpy(buf+count, buf4+p4, offset);
			count += offset;
			p4 += offset;
		}
	}
	return count;
}

////////////////////////////////////// Leet Code Read4 /////////////////////////////////
/******************************************************************************************************
 * Question #157 Read N Characters Given Read4
 * The API: int read4(char *buf) reads 4 characters at a time from a file.
 * The return value is the actual number of characters read. For example, it returns 3 if there is only 3
 * characters left in the file.
 * By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
 * Note:
 * The read function will only be called once for each test case.
 *****************************************************************************************************/
static int read4(char *buf)
{
	return 4;
}

int read(char *buf, int n)
{
	char buf4[4];
	int n4 = 0, count = 0;
	bool eof = false;
	while(count < n && !eof)
	{
		n4 = read4(buf4);
		if(n4 < 4) eof = true;
		for(int i=0; i<n4 && count < n; i++) buf[count++] = buf4[i];
	}
	return count;
}

/******************************************************************************************************
 * Question #158 Read N Characters Given Read4 II - Call multiple times
 * company tag: Facebook
 * The API: int read4(char *buf) reads 4 characters at a time from a file.
 * The return value is the actual number of characters read. For example, it returns 3 if there is only 3
 * characters left in the file.
 * By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
 * Note:
 * The read function may be called mltiple times.
 *
 * company tag: Facebook
 * 利扣 妖舞扒变形，给了read4，但是实现按行read，会有'/n'为行终止，这题开始没理清题意，以为总是以行终止作为结束，就没考虑读完的情况，
 * 后来面试官提醒说不一定最后是行终止字符才发现少了个if，悲剧， 大家一定要问清题意再作答啊
 *****************************************************************************************************/

//static char buf4[4];    	  // this is static buffer for read4 API
//static int p4 = 0;          // this is the static pointer points to next to read in buf4, normally should be 4
//static int n4 = 0;          // this is how many number of char last time we read

int readII(char * buf, int n)
{
	if(!buf) return 0;
	int count = 0;
	while(count < n)
	{
		if(p4 == n4)  // last time we reached an end
		{
			n4 = read4(buf4);
			p4 = 0;
			if(p4 > n4) break;    // a corner case here if read4 return ""
		}
		while(count < n && p4 < n4)
		{
			buf[count++] = buf4[p4++];
		}
	}
	return count;
}

// read 4 with new line character
int read4Line(char * buf)
{
	if(!buf) return 0;
	int cnt = 0;
	while(true)  // break if we have eof OR '\n'
	{
		if(p4 >= n4)
		{
			n4 = read4(buf4);  // or n4 = read4K()
			p4 = 0;
			if(p4 >= n4) break;   // eof
		}
		while(p4 < n4)
		{
			if(buf4[p4] == '\n')
			{
				p4++;  // for the next time read line
				return cnt;
			}
			buf[cnt++] = buf4[p4++];
		}
	}
}

