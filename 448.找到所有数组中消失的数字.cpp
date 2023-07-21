/*
	给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

	找到所有在 [1, n] 范围之间没有出现在数组中的数字。

	您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

	示例:
	输入:
	[4,3,2,7,8,2,3,1]
	输出:
	[5,6]
*/
// hash
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		// map可以使用[]取值
		map<int,int> temp;
		for(auto val:nums)
		    temp[val]++;

		vector<int> res;
		for(int i=1;i<nums.size()+1;i++)
		    if(temp[i]==0)
		        res.push_back(i);
		return res;

	}
};

// 更改原数组
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {

		vector<int> res;
		if (nums.empty()) return nums;
		for (int i = 0; i < nums.size(); i++)
		{
			int newIndex = abs(nums[i]) - 1;
			if (nums[newIndex] > 0)
				nums[newIndex] *= -1;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] <= nums.size())
				res.push_back(i + 1);
		}
		return res;
	}
};