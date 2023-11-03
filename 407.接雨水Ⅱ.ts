// https://leetcode.cn/problems/trapping-rain-water-ii/submissions/

function trapRainWater(heightMap: number[][]): number {
  const dirX = [-1, 0, 1, 0]
  const dirY = [0, 1, 0, -1]
  const m: number = heightMap.length
  const n: number = heightMap[0].length
  // heightMap 的最大值
  let maxHeight: number = 0
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      maxHeight = Math.max(maxHeight, heightMap[i][j])
    }
  }
  // 初始化 water，默认值为 maxHeight
  const water = new Array(m).fill(0).map(() => new Array(n).fill(maxHeight));
  const queue: number[][] = []
  // 将 water 四周的值设置为 heightMap 的值，并将四周的坐标加入 queue
  for (let i = 0; i < m; ++i) {
    for (let j = 0; j < n; ++j) {
      if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
        if (water[i][j] > heightMap[i][j]) {
          water[i][j] = heightMap[i][j];
          queue.push([i, j]);
        }
      }
    }
  }

  while (queue.length) {
    const loc: number[] = queue.shift()!
    const x: number = loc[0]
    const y: number = loc[1]
    // 遍历四周的坐标
    for (let i = 0; i < 4; i++) {
      const nx = x + dirX[i]
      const ny = y + dirY[i]
      if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
        continue
      }
      // x，y 周围的坐标高，
      //  heightMap 对应的值小于 water，此条件是为了防止不必要的访问
      if (water[x][y] < water[nx][ny] && water[nx][ny] > heightMap[nx][ny]) {
        // water 的值最小为 heightMap 的值
        water[nx][ny] = Math.max(water[x][y], heightMap[nx][ny])
        queue.push([nx, ny])
      }
    }
  }

  let res: number = 0
  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      res += water[i][j] - heightMap[i][j]
    }
  }

  return res
};
