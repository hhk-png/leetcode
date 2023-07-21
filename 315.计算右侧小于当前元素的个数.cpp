#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/*
 树状数组
 https://www.cnblogs.com/xenny/p/9739600.html
*/

class Solution {
private:
	vector<int> a;
	vector<int> c;

	void Init(int length) {
		c.resize(length, 0);
	}

	int LowBit(int x) {
		return x & (-x);
	}

	void update(int pos) {
		while (pos < c.size()) {
			// 此处是1，是k的特例
			c[pos] += 1;
			pos += LowBit(pos);
		}
	}

	// 获取数组 a 的前 pos - 1 项和
	int query(int pos) {
		int ret = 0;

		while (pos > 0) {
			ret += c[pos];
			pos -= LowBit(pos);
		}

		return ret;
	}

	// 将 nums 复制一份到 a 数组，排序后去重
	void Discretization(vector<int>& nums) {
		a.assign(nums.begin(), nums.end());
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
	}

	// 获取 nums[i] 在a数组中的位置
	int getId(int x) {
		return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
	}

public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> resultList;

		Discretization(nums);

		Init(nums.size() + 5);

		for (int i = (int)nums.size() - 1; i >= 0; i--) {
			int Id = getId(nums[i]);
			resultList.push_back(query(Id - 1));
			update(Id);
		}

		reverse(resultList.begin(), resultList.end());

		return resultList;
	}
};

