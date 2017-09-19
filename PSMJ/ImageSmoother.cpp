/*
 * ImageSmoother.cpp
 *
Image smoother, 给定一个matrix, 要求输出一个matrix, 每个cell的值是原来3*3邻居的平均值, 要求in-place
 */

#include <vector>

using namespace std;

/*
 * Solution 1: for each integer, use the higer 16 bit to store the averaged result and use the lower 16 bit
 * to store the original velue. This works only when image[x][y] < pow(2, 16) and the average should be
 * able to fit in 16 bit too.
 */
void imageSmoother1(vector<vector<int>> image)
{
	int row = image.size(), col = image[0].size();

	// 8 neighbors including the point itself
	int dirs[9][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
	int mask = 0xff;

	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			int sum = 0, count = 0;
			for(auto dir : dirs)
			{
				int x = i + dir[0];
				int y = j + dir[1];
				if(x < 0 || x >= row || y < 0 || y >= col) continue;  // check out of bound
				if(dir[0] < 0 || dir[0] == 0 && dir[1] < 0) // previous data (left and above), image[x][y] is dirty
				{
					sum += (image[x][y] & mask);  // clean data is in lower 8 bits
				}
				else
				{
					sum += image[x][y]; // clean data
				}
				count++; // if does not have to be exactly 8 neighbors
			}
			image[i][j] += (sum/count) << 8;
		}

		for(int i=0; i<row; i++)
		{
			for(int j; j<col; j++)
			{
				image[i][j] >>= 8;
			}
		}
	}
}

/*
 * Solution 2: Use some extra memory.
 * Since for each line, we will trace at most 1 line of previous data.
 * So suppose we use one row of empty space to store the original data of last row, and by checking the neighbor
 * coordinates we can decide whether the neighbor value can be used or need to be choosen from the saved clean data.
 * This should work for all cases
 */
void imageSmoother2(vector<vector<int>> image)
{
	if(image.empty() || image[0].empty()) return;
	int row = image.size(), col = image[0].size();
	// possible directions, 8 neighbors including itself
	int dirs[9][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
	vector<int> clean(col, 0);

	for(int i=0; i<row; i++)
	{
		vector<int> avg(col, 0);
		for(int j=0; j<col; j++) // loop through all cols
		{
			int sum = 0, count = 0;
			for(auto dir : dirs) // loop through all neighbors
			{
				int x = i + dir[0];
				int y = j + dir[1];
				if(x < 0 || x >= row || y < 0 || y >= row) continue;
				if(dir[0] < 0) // previous level, not clean data
				{
					sum += clean[j];
				}
				else{
					sum += image[i][j];
				}
				count++;
			}
			avg[j] = sum/count;
		}
		// after this row is done
		for(int j=0; j<col; j++)
		{
			clean[j] = image[i][j];
			image[i][j] = avg[j];
		}
	}
}
