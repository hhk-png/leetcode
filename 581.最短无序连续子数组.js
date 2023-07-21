/*
    给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

    你找到的子数组应是最短的，请输出它的长度。

    示例 1:

    输入: [2, 6, 4, 8, 10, 9, 15]
    输出: 5
    解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
    说明 :

    输入的数组长度范围在 [1, 10,000]。
    输入的数组可能包含重复元素 ，所以升序的意思是<=。
*/

var findUnsortedSubarray = function (nums) {
  var stack = [],
      left = nums.length,
      right = 0;
  // 
  for(let i = 0; i < nums.length; i++) {
    while(stack.length !== 0 && (nums[i] < nums[stack[stack.length - 1]])) {
      left = Math.min(left, stack.pop());
    }
    stack.push(i);
  }

  stack = [];
  for(let i = nums.length-1; i >= 0; i--) {
    while(stack.length !== 0 && (nums[i] > nums[stack[stack.length - 1]])) {
      right = Math.max(right, stack.pop());
    }
    stack.push(i);
  }

  return right - left < 0 ? 0 : right - left + 1;
}
var findUnsortedSubarray = function (nums) {
  let max = -Infinity,
      min = Infinity;
  for (let i = 1; i < nums.length; i++) {
    if (nums[i - 1] > nums[i])
      min = Math.min(min, nums[i]);
  }
  for (let i = nums.length - 2; i >= 0; i--) {
    if (nums[i] > nums[i + 1])
      max = Math.max(max, nums[i]);
  }

  let l, r;
  for (l = 0; l < nums.length; l++) {
    if (min < nums[l])
      break;
  }
  for (r = nums.length - 1; r >= 0; r--) {
    if (max > nums[r])
      break;
  }
  return r - l < 0 ? 0 : r - l + 1;
}