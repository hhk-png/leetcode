// https://leetcode.cn/problems/valid-triangle-number/submissions/

function triangleNumber(nums: number[]): number {
  const n: number = nums.length
  nums.sort((a, b) => a - b)
  let res: number = 0
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      let k: number = j + 1
      while (k < n && nums[i] + nums[j] > nums[k]) {
        k++
      }
      res += Math.max(k - j - 1, 0)
    }
  }
  return res
};
