#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


/* 同构字符串：
		两个字符串中互不相同的字符个数相同，并且某个互相映射的字符的个数相同 */
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<char, char> map1;
		unordered_map<char, char> map2;
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			char x = s[i],
				y = t[i];
			// x 和 y 相互映射
			if ((map1.count(x) && map1[x] != y) || (map2.count(y) && map2[y] != x)) {
				return false;
			}
			map1[x] = y;
			map2[y] = x;
		}
		return true;
	}
};


