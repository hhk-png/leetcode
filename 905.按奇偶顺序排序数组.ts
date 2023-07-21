// https://leetcode.cn/problems/sort-array-by-parity/submissions/

var sortArrayByParity = function(nums: number[]) {
  let left = 0, right = nums.length - 1;
  while (left < right) {
      while (left < right && nums[left] % 2 === 0) {
          left++;
      }
      while (left < right && nums[right] % 2 === 1) {
          right--;
      }
      if (left < right) {
          const temp = nums[left];
          nums[left] = nums[right];
          nums[right] = temp;
          left++;
          right--;
      }
  }
  return nums;
};


