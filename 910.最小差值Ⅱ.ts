// https://leetcode.cn/problems/smallest-range-ii/

function smallestRangeII(nums: number[], k: number): number {
  const n = nums.length
  nums.sort((a, b) => a - b)
  let ans = nums[n - 1] - nums[0]

  for (let i = 0; i < n - 1; i++) {
    const high = Math.max(nums[i] + k, nums[n - 1] - k)
    const low = Math.min(nums[i + 1] - k, nums[0] + k)
    ans = Math.min(ans, high - low)
  }

  return ans
};
