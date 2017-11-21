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
	int y4 = 4*y;
	int x4 = 4*x;
	int err = 3- radius;

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
		//err += 4*y + 6;
		err += y4 + 6; // or err = (y<<2) + 6;
		y4 += 4;
		y++;
	}
	else
	{
		//err += 4*(y-x)+10;
		err += y4 - x4 + 10; // or err = ((y-x) << 2) + 10;
		y4 += 4;
		x4 -= 4;
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


