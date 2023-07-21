/*
    给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

    示例 1:
    输入: [1,3,4,2,2]
    输出: 2

    示例 2:
    输入: [3,1,3,4,2]
    输出: 3
*/

// HASH
var findDuplicate = function(nums) {
  // 建立hash
  let seen = new Set();
  for (let num of nums) {
    // 如果之前add过一个相同的数，直接返回
    if (seen.has(num)) {
      return num;
    }
    seen.add(num);
  }

  // 没有返回-1
  return -1;
};

// 循环检测
var findDuplicate = function(nums) {
  let slow = nums[0];
  let fast = nums[nums[0]];
  while(fast != slow) {
    slow = nums[slow];
    fast = nums[nums[fast]];
  }

  slow = 0;
  while(slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }

  return slow;
}