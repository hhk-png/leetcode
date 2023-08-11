// https://leetcode.cn/problems/couples-holding-hands/submissions/

function minSwapsCouples(row: number[]): number {
  const total: number = row.length / 2

  const graph: number[][] = new Array(total).fill(0).map(() => new Array())
  for (let i = 0; i < row.length; i += 2) {
      let left: number = Math.floor(row[i] / 2)
      let right: number = Math.floor(row[i + 1] / 2)
      if (left !== right) {
          graph[left].push(right)
          graph[right].push(left)
      }
  }

  let res: number = 0
  const visited: boolean[] = new Array(total).fill(false)
  for (let i = 0; i < total; i++) {
      if (!visited[i]) {
          visited[i] = true
          let count: number = 0
          const queue: number[] = [i]
          while (queue.length) {
              let x = queue.shift()!
              count++
              for (let y of graph[x]) {
                  if (!visited[y]) {
                      visited[y] = true
                      queue.push(y)
                  }
              }
          }
          res += (count - 1)
      }
  }
  return res
};