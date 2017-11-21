/*
 * ReverseFile.cpp
 *
 * Write a function to reverse a file in place.
 * Answer: Use two pointers, one reads from the beginning, one reads from the end, swap byte by byte.
 * But it is very inefficient since we are calling many I/O apis.
 *
 * Follow up: Each read and write will incur a system call, how do you minimize the amount of system calls?
 * Answer: We can read chunk by chunk instead (Need to modify the original function to illustrate this.)
 *
 * Follow up: What can be a good chunk size? What are the factors determine a good chunk size?
 *
 * Follow up: The reverse process can be interrupted at any time, how do you make sure the file won't be corrupted,
 * and you can resume the reverse process any time?
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

static string file ="abcdefghijklmnopqrstuvwxyz";

/*
 * a naive solution, swap byte by byte
 */
void reverseFile1(char * _file, int size)
{
	char * front = _file;
	char * back = _file + size - 1;
	while(front < back)
	{
		char temp = *front;
		*front = *back;
		*back = temp;
		front++;
		back--;
	}
}

/*
 * Solution for crash -
 Step 1: read 1 chunk of k bytes from front and back of file, load into memory buffer buf1 and buf2.
 	 -> if crash at step 1, redo log's last "good" chunk and go on swapping.
 Step 2: write offset address and content of front/back chunk into backup log in disk, mark a "longging done"
 in log if successful
	-> if crash happen at step 2, last log entry has no "done", so redo last "good" chunk and go on swapping
 Step 3: swap content of buf1 and buf2 in memory
	-> if crash happens at step 3, redo log's last "good" chunk and go on swapping
 Step 4: write buf1 to back chunk, buf2 to front chunk, mark a "swapping done" in log if successful
	-> if crash at step 4, file's content maybe dirty/corrupted
 	   log is like...

offset 0
abcde
offset 21
vwxyz
logging done (meaning log content is reliable, otherwise log is not reliable)
swapping done (meaning file content is reliable, otherwise file is not reliable)

offset 5
fghijk
offset 16
logging done
!! crash !!

So in summary, if a crash happens, then we should restart and redo the log, start to redo from which entry?
	- if last entry has  "swpping done", next chunk may has only been read not written, resume at last entry's
	offset + k
	- if last entry has ONLY "logging done", next chunk may has already been written and corrupted, redo last
	entry's offset using chlean chunk content from log
	- if last entry has NO "xx done", this log entry is corrupted but file is still clean, so redo last
	"swapping done" entry's offset + k using data from file
 */



// function that reads from the file
string readFile(int offset, int k)
{
	return file.substr(offset, k);
}

// funtion that write to file
void wirteFile(int offset, int k, string s)
{
	for(int i=0; i<k; i++)
	{
		file[offset+i] = s[i];
	}
}

void swapChunk(int i, int j, int k)
{
	// step 1: read from file with offset and size k
	string front = readFile(i, k);
	string back = readFile(j, k);
	// step 2: write backup log for updated offset
	// step 3: reverse
	reverse(front.begin(), front.end());
	reverse(back.begin(), back.end());
	// step 4: write back to disk
	wirteFile(i, k, back);
	wirteFile(j, k, front);
}

/*
 * How to choose proper k?
 * 1. k <= n/2
 * 2. chunk of k should be able to fit in memory, unit is char which is byte.
 * 	  So memory requirement is at least 2K byte.
 * 3. k should be resonable big, to reduce read/write IO operation, which is n/2k.
 */
void reverseFile2()
{
	int k = 7;
	int n = file.length(), i = 0, j = n-k;

	while(true)
	{
		swapChunk(i, j, k);
		i += k;
		j -= k;
		if(j <= i) break;
	}
}

/*
int main()
{
	cout << "Original file is "<<file << endl;
	reverseFile2();
	cout << "reverse file 2 result "<< file << endl;
}
*/
