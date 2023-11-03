// https://leetcode.cn/problems/single-element-in-a-sorted-array/solutions/1252764/you-xu-shu-zu-zhong-de-dan-yi-yuan-su-by-y8gh/

function singleNonDuplicate(nums: number[]): number {
  let left: number = 0;
  let right: number = nums.length - 1;

  while (left < right) {
    const mid: number = left + Math.floor((right - left) / 2);
    if (nums[mid] === nums[mid ^ 1]) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return nums[left];
};

