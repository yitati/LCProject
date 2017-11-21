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


