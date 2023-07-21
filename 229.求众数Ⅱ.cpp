#include<iostream>
#include<vector>
using namespace std;

/*

给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

 
示例 1：
	输入：[3,2,3]
	输出：[3]

示例 2：
	输入：nums = [1]
	输出：[1]

示例 3：
	输入：[1,1,1,3,3,2,2,2]
	输出：[1,2]

*/

/* 哈希 */

// 略

/*
	摩尔投票法
*/
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		// 出现次数大于n/3的元素最多只有两个
		// 出现频率最高的两个元素
		int element1 = 0;
		int element2 = 0;
		int vote1 = 0;
		int vote2 = 0;

		// 统计出出现频率最高的两个元素
		for (int num : nums) {
			if (vote1 > 0 && num == element1) { // 如果元素为已经统计的的元素，在原来的基础上加 1
				vote1++;							
			} 
			else if (vote2 > 0 && num == element2) { // 同上
				vote2++;
			} 
			else if (vote1 == 0) { // 更换元素
				element1 = num;
				vote1++;
			} 
			else if (vote2 == 0) { // 更换元素
				element2 = num;
				vote2++;
			}
			else { // 如果三个元素均不相同，则相互抵消一次
				vote1--;
				vote2--;
			}
		}

		// 统计 ele1 和 ele2 出现的次数
		int cnt1 = 0,
			cnt2 = 0;
		for (int num : nums) {
			// vote1 是负数则一定不满足题设条件
			if (vote1 > 0 && num == element1) {
				cnt1++;
			}
			if (vote2 > 0 && num == element2) {
				cnt2++;
			}
		}
		
		vector<int> res;
		// 看是否满足条件
		if (vote1 > 0 && cnt1 > nums.size() / 3) {
			res.push_back(element1);
		}
		if (vote2 > 0 && cnt2 > nums.size() / 3) {
			res.push_back(element2);
		}

		return res;
	}
};