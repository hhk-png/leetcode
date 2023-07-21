#include<iostream>
#include<map>
using namespace std;

/*
	颠倒给定的 32 位无符号整数的二进制位。

 

	示例 1：
	输入: 00000010100101000001111010011100
	输出: 00111001011110000010100101000000
	解释: 输入的二进制串 00000010100101000001111010011100 表示无符号整数 43261596，
		 因此返回 964176192，其二进制表示形式为 00111001011110000010100101000000。
	
	示例 2：
	输入：11111111111111111111111111111101
	输出：10111111111111111111111111111111
	解释：输入的二进制串 11111111111111111111111111111101 表示无符号整数 4294967293，
 		 因此返回 3221225471 其二进制表示形式为 10111111111111111111111111111111 。

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/reverse-bits
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	uint32_t reverseByte(uint32_t byte, map<uint32_t, uint32_t> cache) {
		if (cache.find(byte) != cache.end()) {
			return cache[byte];
		}

		uint32_t value = (byte * 0x0202020202 & 0x010884422010) % 1023;

		cache.emplace(byte, value);
		return value;
	}


	uint32_t reverseBits(uint32_t n) {
		/*
		// 方案1
		// 逐个位翻转
		uint32_t power = 31, res = 0;
		while (n != 0) {
			res = res + ((n & 1) << power);
			power--;
			n = n >> 1;
		}
		return res;
		*/

		/*
		// 方案2
		uint32_t ret = 0, power = 24;
		map<int, int> cache;
		while (n != 0) {
			ret += reverseByte(n & 0xff, cache) << power;
			n = n >> 8;
			power -= 8;
		}

		return ret;
		*/


		// 方案3
		n = (n >> 16) | (n << 16);
		n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
		n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
		n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
		n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
		return n;

	}
};