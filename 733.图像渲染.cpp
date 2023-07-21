/*
	有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间。

	给你一个坐标 (sr, sc) 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 newColor，让你重新上色这幅图像。

	为了完成上色工作，从初始坐标开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，接着再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为新的颜色值。

	最后返回经过上色渲染后的图像。

	示例 1:
	输入:
	image = [[1,1,1],
			 [1,1,0],
			 [1,0,1]]
	sr = 1, sc = 1, newColor = 2
	输出:  [[2,2,2],
			[2,2,0],
			[2,0,1]]
	解析:
	在图像的正中间，(坐标(sr,sc)=(1,1)),
	在路径上所有符合条件的像素点的颜色都被更改成2。
	注意，右下角的像素没有更改为2，
	因为它不是在上下左右四个方向上与初始点相连的像素点。
*/

#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		// 需要被渲染的颜色
		int originColor = image[sr][sc];
		// 如果两者相同，就不需要进行渲染
		if (newColor == originColor) return image;

		fill(image, sr, sc, originColor, newColor);
		// 返回，因为渲染参数传递的是数组的引用，不需要再复刻一个数组
		return image;
	}

	int fill(vector<vector<int>>& image, int x, int y, int originColor, int newColor) {
		// 不在范围内，直接返回
		if (!inArea(image, x, y)) return 0;
		
		// 矩阵内元素的颜色与需要被渲染的颜色不相同，说明不再渲染范围内
		if (image[x][y] != originColor) return 0;
		
		// 使用-1标记元素已经被渲染过，不需要再次渲染
		if (image[x][y] == -1) return 0;
		image[x][y] = -1;

		// 上下左右四个方向进行渲染
		fill(image, x + 1, y, originColor, newColor);
		fill(image, x - 1, y, originColor, newColor);
		fill(image, x, y + 1, originColor, newColor);
		fill(image, x, y - 1, originColor, newColor);

		//最后在把-1变成newColor
		image[x][y] = newColor;

		// 函数需要，对最后的结果没有影响
		return 0;
	}

	// 判断是否在数组区域内的函数
	bool inArea(vector<vector<int>>& image, int x, int y) {
		return x >= 0
			&& x < image.size()
			&& y >= 0
			&& y < image[0].size();
	}
};