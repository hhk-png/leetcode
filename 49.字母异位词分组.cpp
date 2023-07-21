// 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
//	 输出 :
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