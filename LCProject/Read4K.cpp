/*
 * Mianjing: Read4k
 * Company tag: Facebook, Google
 * Given API: int Read4096(char * buf);
 * It reads data from a file and records the position so that the next time when it is called it read the
 * next 4k chars (or the rest of the file, whichever is smaller). The return value is the number of char read.
 * You need to use above API to implement below API:
 * int Read(char* buf, int n)
 * which reads any number of chars from the file.
 *
 */

// TODO - check this code with BAOBAO

#include <algorithm>
#include <cstdint>
#include <cstring>

using namespace std;

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
			memcpy(buf+count, buf4+p4, offset);
			count += offset;
			p4 += offset;
		}
	}
	return count;
}



