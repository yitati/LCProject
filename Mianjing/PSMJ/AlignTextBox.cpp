/*
 * AlignTextBox.cpp
 *
有一系列的textbox，要求bias的线齐平（如图），给一个一行的最大宽度。
如果这一行放不下更多的textbox了就提行。放textbox的顺序必须是输入的textbox的顺序。就是说你不能更改顺序。只能调整位置。

给你a list of rectangle 让你把它们放在一个坐标平面上并align，从左往右放矩形，最右边有一个边界，不能超界，
每个矩形提供getLength(), getWidth()，要保证每一行矩形的中心都在一条直线上，一行放不满另起一行，但是不能有overlap。

textbox class 有高度，宽度，biasline的位置，还有左上角位置xy。xy初始化为0。解题就是要给每个box设置相应合适的xy
 */

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

/*
 * to simplify the problem, we put everything as public
 */
class Box
{
public:
	int height;
	int width;
	int upleftx;
	int uplefty;
	int bias2top;
	Box(int w, int h, int b): width(w), height(h), bias2top(b){}
};

void alignBoxes(vector<Box>& boxes, int widthLimit)
{
	int lhs = 0, rhs = 0;
	int bottomLine = 0, topLine = 0, biasLine = INT_MIN;
	int currWidth = 0;
	while(rhs < boxes.size())
	{
		lhs = rhs;
		topLine = bottomLine;
		biasLine = INT_MIN;
		// loop through every level
		for(; rhs < boxes.size() && currWidth + boxes[rhs].width <= widthLimit; rhs++)
		{
			boxes[rhs].uplefty = currWidth;
			currWidth += boxes[rhs].width;
			// find bias line for each row
			biasLine = max(biasLine, topLine + boxes[rhs].bias2top);
		}
		currWidth = 0;
		// calculate x, y and calculate the bottom for the next layer
		for(int i=lhs; i<rhs; i++)
		{
			boxes[i].upleftx = biasLine - boxes[i].bias2top;
			bottomLine = max(bottomLine, biasLine + boxes[i].height-boxes[i].bias2top);
		}
	}
}

/*
int main() {
    cout <<"Hello, World!" << endl;
    Box box1(3, 3, 2);
    Box box2(5, 7, 3);
    Box box3(2, 2, 1);
    Box box4(2, 4, 2);

    Box box5(5, 7, 5);
    Box box6(3, 5, 4);

    vector<Box> boxes{box1, box2, box3, box4, box5, box6};
    alignBoxes(boxes, 14);

    for(int i=0; i<boxes.size(); i++){
        cout << "Box " << i << " : upleft vertex is (" << boxes[i].upleftx << ", " << boxes[i].uplefty << ")\n";
    }

    return 0;
}
*/
