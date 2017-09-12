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

/*
 * Solution for crash -
 * We should store a global variable called offset.
 * Step 1: read 1 chunk of k bytes from front and back of file, load into memory buffer buf1 and buf2.
 * -> if crash at step 1, redo reading from the file with the last good offset.
 * Step 2: write offset address and content of front/back chunk into backup log in disk, mark a "done"
 * in log if successful
 * -> if crash happen at step w, last log entry has no "done", so redo last "good" chunk and go on swapping
 * Step 3: swap content of buf1 and buf2 in memory
 * -> if crash happens at step3
 */


