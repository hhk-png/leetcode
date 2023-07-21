#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/*
 ��״����
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
			// �˴���1����k������
			c[pos] += 1;
			pos += LowBit(pos);
		}
	}

	// ��ȡ���� a ��ǰ pos - 1 ���
	int query(int pos) {
		int ret = 0;

		while (pos > 0) {
			ret += c[pos];
			pos -= LowBit(pos);
		}

		return ret;
	}

	// �� nums ����һ�ݵ� a ���飬�����ȥ��
	void Discretization(vector<int>& nums) {
		a.assign(nums.begin(), nums.end());
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
	}

	// ��ȡ nums[i] ��a�����е�λ��
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

