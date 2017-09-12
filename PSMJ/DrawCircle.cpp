/*
 * PSMJ_DrawCircle.cpp
 *
Draw a circle at point(0, 0) with radius r.

 */

#include <vector>
#include <iostream>

using namespace std;

#define SCREENSIZE   100

static vector<vector<int>> screen(SCREENSIZE, vector<int>(SCREENSIZE, 0));

void putPixel(int x, int y, int color)
{
	int x0 = SCREENSIZE/2;
	int y0 = SCREENSIZE/2;
	screen[x0+x][y0+y] = (char)color;
}

void drawCircle(int radius)
{
	int x = radius;
	int y = 0;
	int err = 1- radius;

	while(x >= y)
	{
		putPixel(x, y, 1);
		putPixel(y, x, 1);
		putPixel(-y, x, 1);
		putPixel(-x, y, 1);
		putPixel(-x, -y, 1);
		putPixel(-y, -x, 1);
		putPixel(y, -x, 1);
		putPixel(x, -y, 1);
	}

	if(err < 0)
	{
		err += 2*y + 3;
		y++;
	}
	else
	{
		err += 2*(y-x)+5;
		y++;
		x--;
	}
}

void printCircle()
{
	for(int i=0; i<SCREENSIZE; i++)
	{
		for(int j=0; j<SCREENSIZE; j++)
		{
			if(screen[i][j] == 1) cout << "*";
			else cout << " ";
		}
	}
}

/*
int main(int argc, char ** argv)
{
	drawCircle(10);
	printCircle();
}
*/


