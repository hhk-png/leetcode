// https://leetcode.cn/problems/create-maximum-number/solution/pin-jie-zui-da-shu-by-leetcode-solution/

// 获得最长单调递减子序列，限制长度为k
function getMaxSubsequence(nums: number[], k: number): number[] {
  let stack: number[] = [];
  // 需要扔掉的元素个数
  let drop = nums.length - k;
  for (let i = 0; i < nums.length; i++) {
    while (
      stack.length &&
      stack[stack.length - 1] < nums[i] &&
      drop > 0
    ) {
      stack.pop();
      drop--;
    }
    stack.push(nums[i]);
  }
  while (drop--) {
    stack.pop();
  }
  return stack;
}

function merge(subsequence1: number[], subsequence2: number[]): number[] {
  const m = subsequence1.length
  const n = subsequence2.length
  if (m === 0) {
    return subsequence2
  }
  if (n === 0) {
    return subsequence1
  }
  const mergeLength = m + n
  const merged = new Array(mergeLength).fill(0)
  let index1 = 0
  let index2 = 0
  for (let i = 0; i < mergeLength; i++) {
    if (compare(subsequence1, index1, subsequence2, index2) > 0) {
      merged[i] = subsequence1[index1++]
    } else {
      merged[i] = subsequence2[index2++]
    }
  }
  return merged;
}

function compare(subsequence1: number[], index1: number, subsequence2: number[], index2: number): number {
    const m = subsequence1.length
    const n = subsequence2.length
    while (index1 < m && index2 < n) {
        const difference = subsequence1[index1] - subsequence2[index2]
        if (difference !== 0) {
            return difference
        }
        index1++
        index2++
    }

    return (m - index1) - (n - index2)
}

function maxNumber(nums1: number[], nums2: number[], k: number): number[] {
  const m = nums1.length
  const n = nums2.length
  let maxSubsequence = new Array(k).fill(0)
  let start = Math.max(0, k - n)
  let end = Math.min(k, m)
  for (let i = start; i <= end; i++) {
    const subsequence1 = getMaxSubsequence(nums1, i)
    const subsequence2 = getMaxSubsequence(nums2, k - i)
    const curMaxSubsequence = merge(subsequence1, subsequence2)
    if (compare(curMaxSubsequence, 0, maxSubsequence, 0) > 0) {
      maxSubsequence = [...curMaxSubsequence]
    }
  }
  return maxSubsequence
};

