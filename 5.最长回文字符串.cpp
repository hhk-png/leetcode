// 1.扩展字符串
    // 扩展字符串之后从原来要分清楚回文串中间位置字符的奇偶变成只分析奇数的情况
// 2.初始化
// 3.定义初始半径
// 4.增大半径
// 5.更新最左侧的回文字符串
// 6.更新最大的回文字符串所在位置
class Solution {
public:
    string longestPalindrome(string s) {
    
    // 刚开始记录s的长度，为了后面扩展字符串
    int len = s.length();
	if (len < 1)
	{
		return "";
	}

	// 预处理
	string s1;
	for (int i = 0; i < len; i++)
	{
		s1 += "#";
		s1 += s[i];
	}
	s1 += "#";
    // 这里重新计算s1的长度，以s1位主体进行判断
	len = s1.length();
    // 各种变量
	int MaxRight = 0;				// 当前访问到的所有回文子串，所能触及的最右一个字符的位置
	int pos = 0;					// MaxRight对应的回文串的对称轴所在的位置
	int MaxRL = 0;					// 最大回文串的回文半径
	int MaxPos = 0;					// MaxRL对应的回文串的对称轴所在的位置
	int* RL = new int[len];			// RL[i]表示以第i个字符为对称轴的回文串的回文半径
    // 将数组RL中的元素全设置为0，并申请空间
	memset(RL, 0, len * sizeof(int));

	for (int i = 0; i < len; i++)
	{
        // 这里看不懂
		if (i < MaxRight)
		{// 1) 当i在MaxRight的左边
			RL[i] = min(RL[2 * pos - i], MaxRight - i);
		}
		else
		{// 2) 当i在MaxRight的右边
			RL[i] = 1;
		}


		// 尝试扩展RL[i]，注意处理边界
		while (i - RL[i] >= 0  // 可以把RL[i]理解为左半径,即回文串的起始位不能小于0
			&& i + RL[i] < len // 同上,即回文串的结束位不能大于总长
			&& s1[i - RL[i]] == s1[i + RL[i]]// 回文串特性，左右扩展，判断字符串是否相同
			)
		{
			RL[i] += 1;
		}

		// 更新MaxRight, pos
		if (RL[i] + i - 1 > MaxRight)
		{
			MaxRight = RL[i] + i - 1;
			pos = i;
		}

		// 更新MaxRL, MaxPos
		if (MaxRL <= RL[i])
		{
			MaxRL = RL[i];
			MaxPos = i;
		}
	}
    // 这里看不懂
	return s.substr((MaxPos - MaxRL + 1) / 2, MaxRL - 1);

    
    
    }
};