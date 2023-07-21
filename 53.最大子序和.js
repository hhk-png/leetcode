// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

var maxSubArray = function(nums) {
  // 存储最大值
  let ans = nums[0];
  let sum = 0;
  for(const num of nums) {
      if(sum > 0) {
          sum += num;
      } else {            // 
          sum = num;
      }
      // 更新最大值
      ans = Math.max(ans, sum);
  }
  return ans;
};
