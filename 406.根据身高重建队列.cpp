/*
	假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

	注意：
	总人数少于1100人。

	示例
	输入:
	[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
	输出:
	[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		// 排序数组
		// h，k
		sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
			// 身高按降序排列
			if (a[0] > b[0])
				return true;
			// 身高相同时，k按升序排列
			if (a[0] == b[0] && a[1] < b[1])
				return true;
			return false;
		});

		vector<vector<int>> res;
		for (int i = 0; i < people.size(); i++) {
			// 按照向res[k]插入
			res.insert(res.begin() + people[i][1], people[i]);
		}

		return res;
	}
};