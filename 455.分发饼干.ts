// https://leetcode.cn/problems/assign-cookies/submissions/

function findContentChildren(g: number[], s: number[]): number {
  g.sort((a, b) => a - b)
  s.sort((a, b) => a - b)
  let i: number = 0
  let j: number = 0
  const m: number = g.length
  const n: number = s.length
  let res: number = 0
  while (i < m && j < n) {
    if (g[i] <= s[j]) {
      res++
      i++
    }
    j++
  }
  return res
};