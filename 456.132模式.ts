// https://leetcode.cn/problems/132-pattern/

function find132pattern(nums: number[]): boolean {
  const n: number = nums.length;
  const candidate: number[] = [nums[n - 1]];
  // 存储 candidate 中最大的数
  let max_k: number = -Infinity;

  for (let i = n - 2; i >= 0; i--) {
    if (nums[i] < max_k) {
      return true;
    }

    while (candidate.length && nums[i] > candidate[candidate.length - 1]) {
      max_k = candidate.pop()!;
    }

    if (nums[i] > max_k) {
      candidate.push(nums[i]);
    }
  }

  return false;
};

