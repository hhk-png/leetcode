/**
 * 
 * 
 * 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。

    示例 1:
      输入: [1,2,1]
      输出: [2,-1,2]
      解释: 第一个 1 的下一个更大的数是 2；
            数字 2 找不到下一个更大的数； 
            第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
 * 
 * 
 * 
 */


/* % n */

class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    // 数组长度
    int n = nums.size();
    // 存放结果的数组
    vector<int> res(n);
    // 单调栈
    stack<int> s;
    // 相当于反向遍历两次数组
    for (int i = 2 * n - 1; i >= 0; i--) {

      // 小的数被去除
      while (!s.empty() && s.top() <= nums[i % n]) {
        s.pop();
      }
      
      res[i % n] = s.empty() ? -1 : s.top();

      s.push(nums[i % n]);
    }

    return res;
  }
};

