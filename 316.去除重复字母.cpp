/*
给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

注意：该题与 1081 https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters 相同

 

示例 1：

输入：s = "bcabc"
输出："abc"
示例 2：

输入：s = "cbacdcbc"
输出："acdb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicate-letters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	string removeDuplicateLetters(string s) {
		// vis的含义是：
		//  在已经遍历过的字符串相应字母中是否存在
		//	vis对应的值只能为0和1
		// num的含义是：
		//  还剩下未遍历字符的数目
		vector<int> vis(26), num(26);
		for (char ch : s) {
			num[ch - 'a']++;
		}

		string stk;
		for (char ch : s) {
			// 没遇见过ch，则只会更新num的状态，不会进行处理，也就不会向保存最终结果的stk中添加字符
			//		也就相当于去重
			if (!vis[ch - 'a']) {
				while (!stk.empty() && stk.back() > ch) {
					// 此判断语句表示后面还有stk.back()这个字母，
					//  那么就可以将stk和cis中的字符删除，使用后面的字母
					//  否则就不能删除，保证至少存在一个对应的字符
					if (num[stk.back() - 'a'] > 0) {
						// 在已经遍历过的字符集中，将对应字符清零
						vis[stk.back() - 'a'] = 0;
						stk.pop_back();
					}
					else {
						break;
					}
				}
				// 将当前字符对应的状态进行更新
				vis[ch - 'a'] = 1;
				stk.push_back(ch);
			}
			// 已经走过的字符
			num[ch - 'a'] -= 1;
		}
		return stk;
	}
};