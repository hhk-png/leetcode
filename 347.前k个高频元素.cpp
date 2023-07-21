/*

	给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

	示例 1:
	输入: nums = [1,1,1,2,2,3], k = 2
	输出: [1,2]

	示例 2:
	输入: nums = [1], k = 1
	输出: [1]

*/

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {

		//统计次数
		unordered_map<int, int> hash;

		for (int i = 0; i < nums.size(); ++i)
		{
			++hash[nums.at(i)];
		}

		//使用二维数组  统计次数作为第一维（如果统计次数有相同，则将值追加到桶中）
		vector<vector<int>> buckets(nums.size() + 1);

		for (auto iter = hash.begin(); iter != hash.end(); ++iter)
		{
			buckets.at(iter->second).push_back(iter->first);
		}

		//将buckets中前k个高频元素放入res中
		vector<int> res(k);
		int count = 0;
		for (int i = buckets.size() - 1; i >= 0; --i)
		{
			for (int j = 0; j < buckets.at(i).size(); ++j)
			{
				res.at(count) = buckets.at(i).at(j);
				++count;
				if (count == k)
					return res;
			}
		}


		return res;
	}
};