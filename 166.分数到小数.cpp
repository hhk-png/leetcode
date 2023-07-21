/*
	给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。

	如果小数部分为循环小数，则将循环的部分括在括号内。

	如果存在多个答案，只需返回 任意一个 。

	对于所有给定的输入，保证 答案字符串的长度小于 104 。

 

	示例 1：
		输入：numerator = 1, denominator = 2
		输出："0.5"

	示例 2：
		输入：numerator = 2, denominator = 1
		输出："2"

	示例 3：
		输入：numerator = 2, denominator = 3
		输出："0.(6)"

	示例 4：
		输入：numerator = 4, denominator = 333
		输出："0.(012)"

	示例 5：
		输入：numerator = 1, denominator = 5
		输出："0.2"
*/

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (denominator == 0) return "";
		if (numerator == 0) return "0";
		string result;
		// 转换为longlong防止溢出
		long long num = static_cast<long long>(numerator);
		long long denom = static_cast<long long>(denominator);
		// 处理正负号，一正一负取符号
		if ((num > 0) ^ (denom > 0)) result.push_back('-');
		// 分子分母全部转换为正数
		num = llabs(num); denom = llabs(denom);




		// 处理整数部分
		result.append(to_string(num / denom));
		// 处理小数部分
		num %= denom;	// 获得余数
		if (num == 0) return result;	// 余数为0，表示整除了，直接返回结果
		result.push_back('.');	// 余数不为0，添加小数点
		int index = result.size() - 1;	// 获得小数点的下标
		unordered_map<int, int> record;	// map用来记录出现重复数的下标，然后将'('插入到重复数前面就好了
		while (num && record.count(num) == 0) {	// 小数部分：余数不为0且余数还没有出现重复数字
			record[num] = ++index;
			num *= 10;	// 余数扩大10倍
			result += to_string(num / denom);	// 求商
			num %= denom;	// 求余数
		}

		if (record.count(num) == 1) {	// 出现循环余数，直接在重复数前面添加'('，字符串末尾添加')'
			result.insert(record[num], "(");
			result.push_back(")");
		}

		return result;
	}
};

