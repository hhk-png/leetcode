// https://leetcode.cn/problems/making-a-large-island/solutions/1828969/zui-da-ren-gong-dao-by-leetcode-solution-lehy/

function largestIsland(grid: number[][]): number {
  const dirs: number[][] = [[-1, 0], [1, 0], [0, -1], [0, 1]];
  const n: number = grid.length;
  let res: number = 0;
  const tag: number[][] = new Array(n).fill(0).map(() => new Array(n).fill(0));
  const area: Map<number, number> = new Map();
  
  const dfs = (x: number, y: number, hash: number): number => {
    let res: number = 1;
    // 保存 hash 值，每个岛屿的 hash 值相同
    tag[x][y] = hash;
    for (let i = 0; i < 4; i++) {
      const x1: number = x + dirs[i][0];
      const x2: number = y + dirs[i][1];
      if (valid(x1, x2) && grid[x1][x2] === 1 && tag[x1][x2] === 0) {
        res += dfs(x1, x2, hash);
      }
    }
    return res;
  }

  const valid = (x: number, y: number): boolean => {
    return x >= 0 && x < n && y >= 0 && y < n;
  }

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (grid[i][j] === 1 && tag[i][j] === 0) {
        // 将对应位置的面积用 area 保存起来
        const hash: number = i * n + j + 1;
        area.set(hash, dfs(i, j, hash));
        // 先寻找到最大的面积
        res = Math.max(res, area.get(hash)!);
      }
    }
  }

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      // 寻找两座岛屿之间的 0
      if (grid[i][j] === 0) {
        let temp: number = 1;
        // 每一个点都初始化一个 connected
        const connected: Set<number> = new Set();
        for (let k = 0; k < 4; k++) {
          const x: number = i + dirs[k][0];
          const y: number = j + dirs[k][1];
          if (!valid(x, y) || tag[x][y] === 0 || connected.has(tag[x][y])) {
            continue;
          }
          temp += area.get(tag[x][y])!;
          connected.add(tag[x][y]);
        }
        res = Math.max(res, temp);
      }
    }
  }

  return res;
};



