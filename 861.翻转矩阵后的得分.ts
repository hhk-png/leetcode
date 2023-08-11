// https://leetcode.cn/problems/score-after-flipping-matrix/description/

function matrixScore2(grid: number[][]): number {
  const gridNeg: number[][] = grid.map(val => val[0] === 1 ? val : val.map(v => 1 - v))
  const n: number = grid[0].length
  const m: number = grid.length
  let res: number = 0
  for (let j = 0; j < n; j++) {
      const numsOfOne: number = gridNeg.reduce((acc, val) => acc + val[j], 0)
      const maxVal = Math.max(numsOfOne, m - numsOfOne)
      res += maxVal * (1 << (n - j - 1))
  }
  return res
};

function matrixScore(grid: number[][]): number {
  const m = grid.length
  const n = grid[0].length
  let res: number = m * (1 << (n - 1))

  // 横向
  for (let i = 1; i < n; i++) {
      let numOfOne: number = 0
      // 纵向
      for (let j = 0; j < m; j++) {
          if (grid[j][0] === 1) {
              numOfOne += grid[j][i]
          } else {
              numOfOne += (1 - grid[j][i])
          }
      }
      const maxVal = Math.max(numOfOne, m - numOfOne)
      res += maxVal * (1 << (n - i - 1))
  }
  return res
};