/*
    给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

    示例:
    输入: [1,2,3,4]
    输出: [24,12,8,6]
*/

// 两次遍历
var productExceptSelf = function (nums) {
  let v = 1;
  let result = [1];
  for(let i = 1; i < nums.length; i++) {
    v *= nums[i-1];
    result[i] = v;
  }

  v = 1;
  for(let i = nums.length-1; i > 0; i--) {
    v *= nums[i];
    result[i-1] *= v;
  }

  return result;
};