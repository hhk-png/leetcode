/*
  给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

  请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

  说明:
  不允许旋转信封。

  示例:
  输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
  输出: 3 
  解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
*/


/**
 * 
 * 未看题解
 */


var maxEnvelopes = function(envelopes) {
  // 按照envelope[0]升序，envelopes[1]降序排列
  envelopes.sort((a, b) => {
    return a[0]===b[0] ? b[1] - a[1] : a[0] - b[0];
  })
  
  // 获取envelope[1]s
  let height = new Array(envelopes.length).fill(0);
  for (let i = 0; i < envelopes.length; i++) {
    height[i] = envelopes[i][1];
  }
  
  return lengthOfLIS(height)
};


// 300.最长上升子序列
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



