// https://leetcode.cn/problems/advantage-shuffle/submissions/

function advantageCount(nums1: number[], nums2: number[]): number[] {
  const n: number = nums1.length
  const index1 = new Array(n).fill(0).map((val, index) => index)
  const index2 = new Array(n).fill(0).map((val, index) => index)

  index1.sort((a, b) => nums1[a] - nums1[b])
  index2.sort((a, b) => nums2[a] - nums2[b])

  const ans = new Array(n).fill(0)
  let left: number = 0
  let right: number = n - 1
  for (let i = 0; i < n; i++) {
    const num1: number = nums1[index1[i]]
    const num2: number = nums2[index2[left]]
    if (num1 > num2) {
      ans[index2[left]] = num1
      left++
    } else {
      ans[index2[right]] = num1
      right--
    }
  }
  return ans
};



