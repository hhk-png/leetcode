// https://leetcode.cn/problems/sliding-puzzle/submissions/

function slidingPuzzle(board: number[][]): number {
  const neighbors: number[][] = [[1, 3], [0, 2, 4], [1, 5], [0, 4], [1, 3, 5], [2, 4]];
  const initial = board.flat().join('');
  if (initial === '123450') {
    return 0;
  }

  const getNextStatus = (status: string): string[] => {
    const res: string[] = [];
    const arr = Array.from(status);
    const zeroIndex = status.indexOf('0');
    for (const neighbor of neighbors[zeroIndex]) {
      [arr[zeroIndex], arr[neighbor]] = [arr[neighbor], arr[zeroIndex]];
      res.push(arr.join(''));
      [arr[zeroIndex], arr[neighbor]] = [arr[neighbor], arr[zeroIndex]];
    }
    return res;
  }
  
  const queue: string[] = [initial];
  const seen: Set<string> = new Set([initial]);
  let step = 0;
  while (queue.length) {
    step++;
    const n: number = queue.length;
    for (let i = 0; i < n; i++) {
      const status = queue.shift()!;
      for (const nextStatus of getNextStatus(status)) {
        if (!seen.has(nextStatus)) {
          if (nextStatus === '123450') {
            return step;
          }
          queue.push(nextStatus);
          seen.add(nextStatus);
        }
      }
    }
  }
  return -1;
};