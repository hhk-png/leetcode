/*
	�����д���˳���һȺ��վ��һ�����С� ÿ������һ��������(h, k)��ʾ������h������˵���ߣ�k�����������ǰ������ߴ��ڻ����h�������� ��дһ���㷨���ؽ�������С�

	ע�⣺
	����������1100�ˡ�

	ʾ��
	����:
	[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
	���:
	[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		// ��������
		// h��k
		sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
			// ��߰���������
			if (a[0] > b[0])
				return true;
			// �����ͬʱ��k����������
			if (a[0] == b[0] && a[1] < b[1])
				return true;
			return false;
		});

		vector<vector<int>> res;
		for (int i = 0; i < people.size(); i++) {
			// ������res[k]����
			res.insert(res.begin() + people[i][1], people[i]);
		}

		return res;
	}
};