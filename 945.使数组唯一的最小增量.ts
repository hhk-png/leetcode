// https://leetcode.cn/problems/minimum-increment-to-make-array-unique/submissions/

function minIncrementForUnique(nums: number[]): number {
  let res: number = 0
  nums.sort((a, b) => a - b)
  for (let i = 1; i < nums.length; i++) {
    if (nums[i - 1] >= nums[i]) {
      res += nums[i - 1] - nums[i] + 1
      nums[i] = nums[i - 1] + 1
    }
  }

  return res
};

