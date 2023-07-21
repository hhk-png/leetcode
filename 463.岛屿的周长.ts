// https://leetcode.cn/problems/island-perimeter/


function islandPerimeter(grid: number[][]): number {
  const dx: number[] = [0, 1, 0, -1]
  const dy: number[] = [1, 0, -1, 0]
  const n: number = grid.length
  const m: number = grid[0].length
  const dfs = (x: number, y: number): number => {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] === 0) {
      return 1
    }
    if (grid[x][y] === 2) {
      return 0
    }
    grid[x][y] = 2
    let res: number = 0
    for (let i = 0; i < 4; i++) {
      const tx: number = x + dx[i]
      const ty: number = y + dy[i]
      res += dfs(tx, ty)
    }
    return res
  }

  let res: number = 0
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (grid[i][j] === 1) {
        res += dfs(i, j)
      }
    }
  }
  return res
};


