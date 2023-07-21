// https://leetcode.cn/problems/orderly-queue/submissions/

var orderlyQueue = function (s: string, k: number) {
  if (k === 1) {
    let ans = s
    for (let i = 0; i < s.length - 1; ++i) {
      const n = s.length
      s = s.substring(1, n) + s[0]
      ans = ans < s ? ans : s
    }
    return ans
  }
  return [...s].sort().join('')
};