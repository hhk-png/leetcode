class Solution {
public:
	int romanToInt(string s) {
		map<char, int> m = {
			{'I',1},
			{'V',5},
			{'X',10},
			{'L',50},
			{'C',100},
			{'D', 500},
			{'M', 1000}
		};//初始化哈希表

		// 存储结果
		int sum = 0;
		// 前一个结果，用于比较
		int preNum = m[s[0]];
		// 字符串长度
		int len = s.length();
		for (int i = 1; i < len; i++) {
			// 当前字母
			int num = m[s[i]];
			if (preNum < num) { // 如果前一个数字小于后一个，则减
				sum -= preNum;
			}
			else { // 否则加
				sum += preNum;
			}
			preNum = num; // 替换preNum
		}

		sum += preNum; // 加上最后的结果
		return sum; // 返回

	}
};