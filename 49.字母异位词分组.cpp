// ����һ���ַ������飬����ĸ��λ�������һ����ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ�����
// ����: ["eat", "tea", "tan", "ate", "nat", "bat"],
//	 ��� :
//	 [
//	 	 ["ate", "eat", "tea"],
//	 	 ["nat", "tan"],
//		 ["bat"]
//	 ]

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {

		map<string, vector<string>> ma;
		vector<vector<string>> res;

		for (auto str : strs) {
			string tmp = str;
			sort(tmp.begin(), tmp.end());
			ma[tmp].push_back(str);
		}

		for (const auto& m : ma) {
			res.push_back(m.second);
		}

		return res;

	}

};