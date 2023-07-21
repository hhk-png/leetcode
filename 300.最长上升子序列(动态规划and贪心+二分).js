/*
    给定一个无序的整数数组，找到其中最长上升子序列的长度。

    示例:

    输入: [10,9,2,5,3,7,101,18]
    输出: 4 
    解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
*/

/**
 * @param {number[]} nums
 * @return {number}
 */

/* 动态规划 */
/* O(n^2) */
var lengthOfLIS = function(nums) {
  // 数组为空返回0
  if(nums.length === 0) return 0;

  // dp数组存放的是从0~i最长上升子序列的长度
  // 初始化动态规划数组
  let dp = new Array(nums.length).fill(0),
      // 记录数组中最长上升序列的长度
      ans = 1;
  // 最长默认为1
  dp[0] = 1;

  for(let i = 1; i < nums.length; i++) {
    // 从 0~i 的dp数组的最大值
    let maxLen = 0;
    // 更新最大值
    for(let j = 0; j < i; j++) 
      // 此时
      if(nums[i] > nums[j])
        maxLen = Math.max(maxLen, dp[j]);
    
    // 更新dp[i]
    dp[i] = maxLen + 1;
    // 更新maxAns
    ans = Math.max(ans, dp[i]);
  }

  // 返回ans
  return ans;
};


/* 贪心 + 二分查找 */
/* O(nlogn) */
var lengthOfLIS = function(nums) {
  // 记录有序序列的长度
  let len = 1,
      // 数组长度
      n = nums.length,
      // 存放有序序列的数组
      d = Array(n+1).fill(0);
  // 数组为空，返回
  if(n == 0) return 0;
  // d数组以索引1为开始，
  d[len] = nums[0];

  for(let i = 1; i < n; i++) {
    // 说明nums[i]和d构成的是有序序列，向数组d中push添加nums[i]
    if(nums[i] > d[len]) d[++len] = nums[i];
    // 在数组中寻找可以替换成nums[i]的位置pos
    // 二分查找
    else {
      let l = 1, r = len, pos = 0;   // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
      while(l <= r) {
        let mid = (l+r) >> 1;
        if(d[mid] < nums[i]) {
          pos = mid;
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      d[pos+1] = nums[i];
    }
  }

  return len;
}