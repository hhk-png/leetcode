// https://leetcode.cn/problems/number-of-provinces/submissions/

function findCircleNum(isConnected: number[][]): number {
  let res: number = 0
  const visited: Set<number> = new Set()
  const dfs = (i: number) => {
    for (let j = 0; j < isConnected.length; j++) {
      if (isConnected[i][j] && !visited.has(j)) {
        visited.add(j)
        dfs(j)
      }
    }
  }

  for (let i = 0; i < isConnected.length; i++) {
    if (!visited.has(i)) {
      dfs(i)
      res++
    }
  }
  return res
};
