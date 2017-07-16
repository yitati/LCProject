/******************************************************************************************************
 * Question #158 Read N Characters Given Read4 II - Call multiple times
 * The API: int read4(char *buf) reads 4 characters at a time from a file.
 * The return value is the actual number of characters read. For example, it returns 3 if there is only 3
 * characters left in the file.
 * By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
 * Note:
 * The read function may be called mltiple times.
 *****************************************************************************************************/

static int read4(char * buf)
{
	return 4;
}

static char buf4[4];    // this is static buffer for read4 API
static int p4 = 0;          // this is the static pointer points to next to read in buf4, normally should be 4
static int n4 = 0;          // this is how many number of char last time we read


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



