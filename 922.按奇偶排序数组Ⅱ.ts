// https://leetcode.cn/problems/sort-array-by-parity-ii/submissions/

const swap = (nums: number[], i: number, j: number) => {
  const temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
};


function sortArrayByParityII(nums: number[]): number[] {
  const n: number = nums.length
  let j: number = 1

  for (let i = 0; i < n; i += 2) {
    if (nums[i] & 1) {
      while (nums[j] & 1) {
        j += 2
      }
      swap(nums, i, j)
    }

  }
  return nums
};
