// https://leetcode.cn/problems/maximum-product-of-three-numbers/

var maximumProduct = function(nums: number[]) {
  nums.sort((a, b) => a - b);
  const n = nums.length;
  // 两个最小负数和一个最大正数
  //  三个最大正数
  return Math.max(nums[0] * nums[1] * nums[n - 1], nums[n - 1] * nums[n - 2] * nums[n - 3]);
};
