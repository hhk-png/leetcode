// https://leetcode.cn/problems/snakes-and-ladders/submissions/

function snakesAndLadders(board: number[][]): number {
  const n: number = board.length;
  const vis: boolean[] = new Array(n * n + 1).fill(false);
  const queue: [number, number][] = [[1, 0]];
  
  const indexToPos = (index: number): [number, number] => {
    let row: number = Math.floor((index - 1) / n);
    let col: number = (index - 1) % n;
    if (row % 2 === 1) {
      col = n - col - 1;
    }
    return [n - row - 1, col];
  };


  while (queue.length) {
    const pos = queue.shift()!;
    for (let i = 1; i <= 6; i++) {
      let nextPos: number = pos[0] + i;
      if (nextPos > n * n) {
        break;
      }
      const [row, col] = indexToPos(nextPos);
      if (board[row][col] > 0) {
        nextPos = board[row][col];
      }
      if (nextPos === n * n) {
        return pos[1] + 1;
      }
      if (!vis[nextPos]) {
        vis[nextPos] = true;
        queue.push([nextPos, pos[1] + 1]);
      }
    }
  }

  return -1;
};