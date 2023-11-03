// https://leetcode.cn/problems/minesweeper/description/

function updateBoard(board: string[][], click: number[]): string[][] {
  const dirX: number[] = [0, 1, 0, -1, 1, 1, -1, -1]
  const dirY: number[] = [1, 0, -1, 0, 1, -1, 1, -1]
  const bfs = (x: number, y: number) => {
    // bfs 主要是计算周围的地雷数量，
    //  如果有地雷，就标记为地雷数量，
    //  如果没有地雷，就标记为 B，然后继续遍历周围的格子
    const queue: number[][] = []
    const visited: boolean[][] = new Array(board.length).fill(0).map(item => new Array(board[0].length).fill(false))
    queue.push([x, y])
    visited[x][y] = true
    while (queue.length) {
      const pos: number[] = queue.pop()!
      const currX: number = pos[0]
      const currY: number = pos[1]
      let count: number = 0
      // 统计周围格子为 M 的数量，未挖出的地雷的数量
      for (let i = 0; i < 8; i++) {
        const newX = currX + dirX[i]
        const newY = currY + dirY[i]
        if (newX < 0 || newX >= board.length || newY < 0 || newY >= board[0].length) {
          continue
        }
        count += Number(board[newX][newY] === 'M')
      }
      // 有相邻的炸弹
      if (count > 0) {
        // 未挖出炸弹的数量
        board[currX][currY] = String(count)
      } else {
        // 没有相邻的炸弹，为B 的情况，周围没有已挖出的空白方块
        board[currX][currY] = 'B'
        for (let i = 0; i < 8; i++) {
          const newX = currX + dirX[i]
          const newY = currY + dirY[i]
          // 这种情况下就不需要访问周围未挖出的空方块 和 已经访问的方块
          if (newX < 0 || newX >= board.length || newY < 0 || newY >= board[0].length || board[newX][newY] != 'E' || visited[newX][newY]) {
            continue
          }
          queue.push([newX, newY])
          visited[newX][newY] = true
        }
      }
    }
  }

  const x: number = click[0]
  const y: number = click[1]
  if (board[x][y] == 'M') {
    board[x][y] = 'X'
  } else {
    bfs(x, y)
  }
  return board
};

