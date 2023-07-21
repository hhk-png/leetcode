#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
示例 2：

输入：nums = []
输出：[]
示例 3：

输入：nums = [0]
输出：[]
*/
class Solution {
public: 
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int first = 0; first < n; first++) {
      if (first > 0 && nums[first] == nums[first - 1]) {
        continue;
      }
      int third = n - 1;
      // int target = -nums[first];

      for (int second = first + 1; second < n; second++) {
        if (second > first + 1 && nums[second] == nums[second - 1]) {
          continue;
        }

        while (third > second && (nums[first] + nums[second] + nums[third] > 0)) {
          third--;
        }

        if (second == third) {
          break;
        }

        if (nums[first] + nums[second] + nums[third] == 0) {
          res.push_back({nums[first], nums[second], nums[third]});
        }
      }

    }

    return res;
  }
};