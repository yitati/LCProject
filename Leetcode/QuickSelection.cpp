/*
 * Quick Selection
 * Quick selection is a selection algorithm to find the kth smallest element in an unsorted list.
 * It is related to the quick sort sorting algorithm. Like quick sort, it is efficient in practice and has
 * good average-case performance, but has poor worst-case performance.
 * How to prove that quick selection has average time complexity of O(n)?
 * company tag: Facebook
 * Quick select uses the same overall approach as quick sort, choosing one element as a pivot and partition the
 * data in two based on the pivot, accordingly as less than or greater than the pivot. However, instead of
 * recursing into both sides, as in quicksort, quickselect only recurses into one side - the side with
 * the element it is searching for. This reduces the average complexity from O(nlogn) to O(n), with a worst
 * case of O(n^2).
 * https://en.wikipedia.org/wiki/Quickselect
 */




