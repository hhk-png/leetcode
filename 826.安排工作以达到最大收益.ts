// https://leetcode.cn/problems/most-profit-assigning-work/

function maxProfitAssignment(difficulty: number[], profit: number[], worker: number[]): number {
  const jobs: [number, number][] = difficulty.map((val, index) => [val, profit[index]])
  jobs.sort((a, b) => a[0] - b[0])

  let res: number = 0
  let best: number = 0
  const n: number = difficulty.length
  let i: number = 0
  worker.sort((a, b) => a - b)
  for (const skill of worker) {
    while (i < n && skill >= jobs[i][0]) {
      best = Math.max(best, jobs[i][1])
      i++
    }
    res += best
  }
  return res
};

