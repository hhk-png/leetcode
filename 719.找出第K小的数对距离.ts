// https://leetcode.cn/problems/find-k-th-smallest-pair-distance/submissions/

function smallestDistancePair(nums: number[], k: number): number {
  nums.sort((a, b) => a - b)
  const n: number = nums.length
  let left: number = 0
  let right: number = nums[n - 1] - nums[0]
  while (left <= right) {
    const mid: number = Math.floor((left + right) / 2);
    let cnt: number = 0
    let i: number = 0
    for (let j = 0; j < n; j++) {
      while (nums[j] - nums[i] > mid) {
        i++
      }
      cnt += (j - i)
    }
    if (cnt >= k) {
      right = mid - 1
    } else {
      left = mid + 1
    }
  }
  return left
};

const binarySearch = (nums: number[], end: number, target: number) => {
  let left = 0, right = end;
  while (left < right) {
      const mid = Math.floor((left + right) / 2);
      if (nums[mid] < target) {
          left = mid + 1;
      } else {
          right = mid;
      }
  }
  return left;
}



