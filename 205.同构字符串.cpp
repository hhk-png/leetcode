#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


/* ͬ���ַ�����
		�����ַ����л�����ͬ���ַ�������ͬ������ĳ������ӳ����ַ��ĸ�����ͬ */
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<char, char> map1;
		unordered_map<char, char> map2;
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			char x = s[i],
				y = t[i];
			// x �� y �໥ӳ��
			if ((map1.count(x) && map1[x] != y) || (map2.count(y) && map2[y] != x)) {
				return false;
			}
			map1[x] = y;
			map2[y] = x;
		}
		return true;
	}
};


