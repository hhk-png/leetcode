#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;

/*
城市的 天际线 是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。
	给你所有建筑物的位置和高度，请返回 由这些建筑物形成的 天际线 。

每个建筑物的几何信息由数组 buildings 表示，
	其中三元组 buildings[i] = [lefti, righti, heighti] 表示：

lefti 是第 i 座建筑物左边缘的 x 坐标。
righti 是第 i 座建筑物右边缘的 x 坐标。
heighti 是第 i 座建筑物的高度。
你可以假设所有的建筑都是完美的长方形，在高度为 0 的绝对平坦的表面上。

天际线 应该表示为由 “关键点” 组成的列表，格式 [[x1,y1],[x2,y2],...] ，并按 x 坐标 进行 排序 。
	关键点是水平线段的左端点。列表中最后一个点是最右侧建筑物的终点，y 坐标始终为 0 ，仅用于标记天际线的终点。
	此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。

注意：输出天际线中不得有连续的相同高度的水平线。例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...] 
	是不正确的答案；三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...]


示例 1：
	输入：buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
	输出：[[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
示例 2：
	输入：buildings = [[0,2,3],[2,5,3]]
	输出：[[0,3],[5,0]]
 

提示：
	1 <= buildings.length <= 104
	0 <= lefti < righti <= 231 - 1
	1 <= heighti <= 231 - 1
	buildings 按 lefti 非递减排序

*/

class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		// 针对 vector<pair<int, int>> 的比较函数
		auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) -> bool { return a.second < b.second; };
		// 优先级队列，实际上是一个大根堆
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);

		// 所有边界的集合，left 和 right
		vector<int> boundaries;
		for (auto& building : buildings) {
			boundaries.emplace_back(building[0]);
			boundaries.emplace_back(building[1]);
		}
		// 按正序排列
		sort(boundaries.begin(), boundaries.end());

		// result
		vector<vector<int>> ret;
		// 
		int n = buildings.size(), idx = 0;
		// 以 boundary 为中心进行遍历
		for (auto& boundary : boundaries) {
			// 先将 building 左边缘坐标小于 boundary 的建筑物的右边缘和高度加入到大根堆中，
			//		que 中以建筑物的高度进行堆的更新
			while (idx < n && buildings[idx][0] <= boundary) {
				// 向 que 中添加的是 pair<int, int>
				//  右边缘作为弹出队列的依据，
				que.emplace(buildings[idx][1], buildings[idx][2]);
				idx++;
			}

			// 针对已经插入到队列里面的元素进行删除
			// 若队顶建筑物的右边缘小于 boundary ，且队列不为空，就将其删除
			while (!que.empty() && que.top().first <= boundary) {
				que.pop();
			}

			// 队顶建筑物的高度
			int maxn = que.empty() ? 0 : que.top().second;
			// ret 大小为0，即刚开始
			//	前一个结果的高度与 maxn 的大小不相同
			if (ret.size() == 0 || maxn != ret.back()[1]) {
				ret.push_back({ boundary, maxn });
			}
		}
		return ret;
	}
};

