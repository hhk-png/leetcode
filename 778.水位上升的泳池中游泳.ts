// https://leetcode.cn/problems/swim-in-rising-water/submissions/

function swimInWater(grid: number[][]): number {
  const dirs: number[][] = [[0, 1], [0, -1], [1, 0], [-1, 0]];
  const n: number = grid.length;

  // 在路线上的值都小于 threshold 的情况下，看是否存在一条由 [0, 0] 到 [n - 1, n - 1] 的路线
  const bfs = (threshold: number) => {
      const queue: number[][] = [[0, 0]];
      const visited: boolean[][] = new Array(n).fill(0).map(val => new Array(n).fill(false));
      visited[0][0] = true;

      while (queue.length) {
          const loc: number[] = queue.shift()!;
          const x = loc[0];
          const y = loc[1];
          for (const dir of dirs) {
              const newX = x + dir[0];
              const newY = y + dir[1];
              if (
                  newX >= 0 && newX < n && newY >= 0 && newY < n &&
                  !visited[newX][newY] && grid[newX][newY] <= threshold) {
                  if (newX === n - 1 && newY === n - 1) {
                      return true;
                  }

                  queue.push([newX, newY]);
                  visited[newX][newY] = true;
              }
          }
      }

      return false;
  }

  let left: number = 0;
  let right: number = n * n - 1;

  while (left < right) {
      const mid = left + Math.floor((right - left) / 2);
      if (grid[0][0] <= mid && bfs(mid)) {
          // 需要保证初始位置的值小于 mid
          right = mid;
      } else {
          left = mid + 1;
      }

  }
  return left;
};
