/*
 * SkipList.cpp
 *
http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=210016&ctid=459
http://www.geeksforgeeks.org/skip-list/
What data structure would you use to construct a skip list? Implement search() and insert().
Skiplist is to implement Binary Search or BST on linked list.
Build multiple layer lists, leaf layer is the original list while upper layer are temp indexing node to coarsely locate
the target in a segment/range.
Reference links:
    http://igoro.com/archive/skip-lists-are-fascinating/
    http://www.mathcs.emory.edu/~cheung/Courses/323/Syllabus/Map/skip-list-impl.html
    http://ticki.github.io/blog/skip-lists-done-right/

 */




