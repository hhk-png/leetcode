// https://leetcode.cn/problems/max-increase-to-keep-city-skyline/submissions/

function maxIncreaseKeepingSkyline(grid: number[][]): number {
  // 从左边看和从右边看是等价的
  const n: number = grid.length
  const colsMax: number[] = new Array(n).fill(-1)
  const rowsMax: number[] = new Array(n).fill(-1)
  for (let i = 0; i < n; i++) {
      for (let j = 0; j < n; j++) {
          colsMax[j] = Math.max(colsMax[j], grid[i][j])
          rowsMax[i] = Math.max(rowsMax[i], grid[i][j])
      }
  }
  let res: number = 0
  for (let i = 0; i < n; i++) {
      for (let j = 0; j < n; j++) {
          res += Math.min(colsMax[j], rowsMax[i]) - grid[i][j]
      }
  }
  return res
};
