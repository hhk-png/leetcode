/*
给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

 
示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]

示例 2：
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的

*/

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size();
		int n2 = nums2.size();
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		vector<int> res;
		int index1 = 0;
		int index2 = 0;
		// 如果两个数组其中一个数组已经遍历完成，则另一个数组不需要遍历，已经没有了交集
		while (index1 < n1 && index2 < n2) {
			int num1 = nums1[index1];
			int num2 = nums2[index2];
			if (num1 == num2) {
				// 通过 rex.back() 来保证最终结果的唯一性
				if (!res.size() || num1 != res.back()) {
					res.push_back(num1);
				}
				index2++;
				index1++;
			}
			else if (num1 < num2) {
				index1++;
			}
			else {
				index2++;
			}
		}

		return res;
	}
};