/******************************************************************************/
/*
* Question: #223 Rectangle Area
* Find the total area covered by two rectilinear rectangles in a 2D plane.
* Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
* Assume that the total area is never beyond the maximum possible value of int.
*/
/*****************************************************************************/

#include <algorithm>

using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
{
	int left = max(A, E), right = max(left, min(C, G));
	int bottom = max(B, F), top = max(bottom, min(D, H));
	return (C - A) * (D - B) + (G - E) * (H - F) - (right - left) * (top - bottom);

}