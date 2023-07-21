/*
	给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

	字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

	说明：

	字母异位词指字母相同，但排列不同的字符串。
	不考虑答案输出的顺序。

	示例 1:
	输入:
	s: "cbaebabacd" p: "abc"
	输出:
	[0, 6]
	解释:
	起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
	起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。

 	示例 2:
	输入:
	s: "abab" p: "ab"
	输出:
	[0, 1, 2]
	解释:
	起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
	起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
	起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string t) {
		// need  需要验证的字符
		// window  窗口内字符的数量
        unordered_map<char, int> need, window;
		// 获取t中字符的具体数量
        for (char c : t) need[c]++;

		// 窗口左右区间
		// [left, right)
        int left = 0, 
			right = 0,
			// 有效字母
			valid = 0;
        vector<int> res; // 记录结果

		// 右区间还在范围内的时候
        while (right < s.size()) {
			// 获取right对应的字符
            char c = s[right];
			// 向前进，作用于下一次循环
            right++;
            // need中包含当前字符
            if (need.count(c)) {
				// 窗口中，当前字符的数量加一
                window[c]++;
				// 当window中本字符的数量自增之后为1时，
				// 说明窗口中多了一个有效的字符
                if (window[c] == need[c]) 
                    valid++;
            }
            // 判断左侧窗口是否要收缩
			// 窗口的大小等于 t 的长度
            while (right - left >= t.size()) {
                // 有效字符的个数，等于need的大小
                if (valid == need.size())
					// 就说明当前窗口的字符串满足要求
                    res.push_back(left);
				// 获取窗口末尾的字符
                char d = s[left];
				// 因为外层循环中right已经自增，而且right - left >= t.size()
				// 要保证窗口大小为need.size()，就要left++
                left++;
                // 舍去的字符在need中
                if (need.count(d)) {
					// 如果相等
                    if (window[d] == need[d])
						// 说明有效字符少一
                        valid--;
					// 之后再进行窗口数量减少
                    window[d]--;
                }
            }
        }
		// 返回res
        return res;
    }
};
