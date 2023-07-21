// https://leetcode.cn/problems/reordered-power-of-2/submissions/

function reorderedPowerOf2(n: number): boolean {
  const backtrack = (nums: string[], index: number, num: number): boolean => {
    if (index >= nums.length) {
      return isPowerOfTwo(num)
    }
    for (let i = 0; i < nums.length; i++) {
      if (
        (num === 0 && nums[i] === '0') || 
        vis[i] || 
        (i > 0 && !vis[i] && nums[i] === nums[i - 1])
      ) {
        continue
      }
      vis[i] = true
      if (backtrack(nums, index + 1, num * 10 + nums[i].charCodeAt(0) - '0'.charCodeAt(0))) {
        return true
      }
      vis[i] = false
    }
    return false
  }

  const nums = Array.from('' + n)
  nums.sort()
  const vis: boolean[] = new Array(nums.length).fill(false)
  return backtrack(nums, 0, 0)
}

function isPowerOfTwo(n: number) {
  return (n & (n - 1)) === 0
}




function reorderedPowerOf2_(n: number): boolean {
  const record: Set<string> = new Set()

  for (let i = 1; i <= 1e9; i <<= 1) {
    record.add(countDigit(i))
  }

  return record.has(countDigit(n))
};

function countDigit(n: number) {
  const arr: number[] = new Array(10).fill(0)
  while (n) {
    arr[n % 10]++
    n = Math.floor(n / 10)
  }
  return arr.join('')
}