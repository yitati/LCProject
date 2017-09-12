/*
 * MemoryAlignment.cpp
 *

https://instant.1point3acres.com/thread/141200
https://www.mitbbs.com/article_t/JobHunting/33083975.html
 */

#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
/*
 * Step 1: If consider only the malloc function and no free operation involved.
 * We can allocate (size+align) space and return the ptr at the n*align address
 */
void* malloc_aligned(size_t size, int align)
{
	char * oldPtr = (char *)malloc(size + align);
	char * newPtr = oldPtr + (align - (int)oldPtr % align);
	return (void*)newPtr;
}

/*
 * Step 2: Consider free function. How should we correctly free the space we just
 * allocated using the malloc_aligned function?
 * We want to allocate (size + align + 4)
 *
 */
void* malloc_aligned2(size_t size, int align)
{
	char * oldPtr = (char *)malloc(size + align + 4);
	char * newPtr = oldPtr + 4 + (align - (int)(oldPtr + 4) % align);
	int offset = newPtr - oldPtr;
	// copy offset to newPtr-4
	memcpy(newPtr-4, &offset, 4);
	printf("malloc : old pointer is %p, new pointer is %p, offset is %d\n", oldPtr, newPtr, offset);
	return newPtr;
}

void free_aligned(void * ptr)
{
	char * newPtr = (char *)ptr;
	int offset;
	memcpy(&offset, newPtr-4, 4);
	char * oldPtr = newPtr - offset;
	printf("free : old pointer is %p, new pointer is %p, offset is %d\n", oldPtr, newPtr, offset);
	free(oldPtr);
}

/*
int main()
{
	void* ptr1 = malloc_aligned2(100, 37);
	free_aligned(ptr1);
}
*/


