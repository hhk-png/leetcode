// https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/

function canPartitionKSubsets(nums: number[], k: number): boolean {
  const sum = nums.reduce((acc, val) => acc + val, 0);
  if (sum % k !== 0) {
    return false;
  }
  const target = sum / k;
  const visited = new Array(nums.length).fill(false);
  nums.sort((a, b) => a - b);
  if (nums[nums.length - 1] > target) {
    return false;
  }
  const dfs = (index: number, curSum: number, count: number) => {
    if (count === k) {
      return true;
    }
    if (curSum === target) {
      return dfs(0, 0, count + 1);
    }
    for (let i = index; i < nums.length; i++) {
      if (visited[i]) {
        continue;
      }
      if (curSum + nums[i] > target) {
        continue;
      }
      visited[i] = true;
      if (dfs(i + 1, curSum + nums[i], count)) {
        return true;
      }
      visited[i] = false;
    }
    return false;
  }
  return dfs(0, 0, 0);
};

