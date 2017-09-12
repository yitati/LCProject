/*
 * Memcpy.cpp
 *
 给了一段简单的代码，实际就是memcpy的实现。讨论下什么情况不work（两个buf有overlap的时候不work），怎么改进，用memmove改进，然后实现memmove
http://www.geeksforgeeks.org/write-memcpy/
memcpy is implemented in a simple (but fast manner).
Simplistically, it just loops over the data (in order), copying from one location to the other.
This can result in the source being overwritten while it's being read.
memmove performs a test to determine which direction to loop in to avoid corrupting the data.

给了另外一段代码，五个线程，对一个global变量x做5次++，问这个代码有什么问题。
thread concurrence问题，具体是C++翻译成汇编是三个指令：
1. load x
2. increment x
3. store x back to memory。
然后问最大可能的数是多少（25），可能的最小值是多少（2）为什么最小值是2. 我层层提示下想到了为什么是2。

 */

#include <stdio.h>
#include <string.h>

using namespace std;


/*
 * The memcpy funtion is used to copy a block of data from a source address to a destination address.
 */
void memcpy(void * destination, void * source, size_t num);

/*
 * The idea is to simply typecast given address to char * (char takes 1 byte). Then one by one copy data
 * from source to destination.
 */
void myMemCpy(void * dest, void * src, size_t n)
{
	// Typecast src and dest addresses to (char *)
	char * csrc = (char *) src;
	char * cdest = (char *) dest;
	// Copy contents of src[] to dest[]
	for(int i=0; i<n; i++)
	{
		cdest[i] = csrc[i];
	}
}

void testMemCpy1()
{
	char csrc[] = "GeeksforGeeks";
	char cdest[100];
	myMemCpy(cdest, csrc, strlen(csrc)+1);
	printf("Copied string is %s", cdest);
}

/*
 * memcpy() leads to problems when source and destination addresses overlap as memcpy() dimply
 * copies data one by one from one location to another. For example consider below program.
 * It overwrites the orginal string and causes data loss.
 */
int negMemCpy()
{
	char csrc[100]="Geeksfor";
	memcpy(csrc+5, csrc, strlen(csrc)+1);  // output is "GeeksGeeksGeek", data lost
	printf("%s", csrc);
	return 0;
}

/*
 * What is memmove()?
 * memmove() is imilar to memcpy() as it also copies data from a source to destination which also
 * hanles address overlap.
 * How to implement memmove()?
 * The trick here is to use a temp array instead of directly copying from src to dest. The use of
 * temp array is important to handle cases when source and destination addresses are overlapping.
 *
 */
void myMemMove(void * dest, void * src, size_t n)
{
	// Type cast src and dest address to char*
	char * csrc = (char *) src;
	char * cdest = (char *) dest;
	// Create a temporary array to hold data of src
	char * temp = new char[n];
	// Copy data from csrc to temp
	for(int i=0; i<n; i++)
	{
		temp[i] = csrc[i];
	}
	// Copy data from temp to cdest
	for(int i=0; i<n; i++)
	{
		cdest[i] = temp[i];
	}

	delete temp;
}

/*
 * Optimization:
 * The algorithm is inefficient (and honestly double the time if you use a temporary array). Double copies
 * should be avoided unless if it is really impossible.
 * In this case though it is easily possible to avoid double copies by picking a direction of copy. In fact
 * this is what memmove() library function does.
 * By comparing the src and the dst addresses you should be able to find if they overlap.
 * - if they do no overlap, you can just to memcpy()
 * - if they do overlap, find which end of dest overlaps with the source and choose the direction of copy
 * accordingly.
 *    1. if the begining of dest overlaps, copy from end to begining.
 *    2. if the end of dest overlaps, copy from begining to end.
 * - Another optimization woule be to copy by word size. Just be careful to handle the boundary conditions.
 * - A further optimization would be to use vector instructions for the copy since they are contiguous.
 */

