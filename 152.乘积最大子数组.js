/*
    给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字）。


    示例 1:
    输入: [2,3,-2,4]
    输出: 6
    解释: 子数组 [2,3] 有最大乘积 6。
    
    示例 2:
    输入: [-2,0,-1]
    输出: 0
    解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
*/
// 动态规划
var maxProduct = function(nums) {
  let n = nums.length;
  if(n === 1 || n === 0) {
      return nums[0];
  }

  let res = nums[0];
  let maxP = nums[0];
  let minP = nums[0];
  for(let i = 1; i < n; i++) {
      let t = maxP;
      maxP = Math.max(nums[i], maxP * nums[i], minP * nums[i]);
      // 负数相乘可能为正数
      minP = Math.min(nums[i], t * nums[i], minP * nums[i]);
      res = Math.max(maxP, res);
  }
  return res;
};