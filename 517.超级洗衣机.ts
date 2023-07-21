// https://leetcode.cn/problems/super-washing-machines/submissions/

function findMinMoves(machines: number[]): number {
  const total = machines.reduce((a, b) => a + b, 0)
  const n = machines.length
  if (total % n !== 0) {
    return -1
  }
  const avg = total / n
  let res: number = 0
  let sum: number = 0
  for (let num of machines) {
    num -= avg
    sum += num
    res = Math.max(res, Math.max(Math.abs(sum), num))
  }
  return res
};

