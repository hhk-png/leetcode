// https://leetcode.cn/problems/sum-of-distances-in-tree/solutions/437205/shu-zhong-ju-chi-zhi-he-by-leetcode-solution/

function sumOfDistancesInTree(n: number, edges: number[][]): number[] {
  const res = new Array(n).fill(0);
  const dp = new Array(n).fill(0);
  const count = new Array(n).fill(0);
  const graph: number[][] = new Array(n).fill(0).map(() => []);

  const dfs = (u: number, from: number) => {
    count[u] = 1;
    dp[u] = 0;
    for (const v of graph[u]) {
      if (v === from) {
        continue;
      }
      dfs(v, u);
      dp[u] += dp[v] + count[v];
      count[u] += count[v];
    }
  }

  const dfs2 = (u: number, from: number) => {
    res[u] = dp[u];
    for (const v of graph[u]) {
      if (v === from) {
        continue;
      }
      const dpU = dp[u]
      const dpV = dp[v];
      const countU = count[u];
      const countV = count[v];

      dp[u] -= dp[v] + count[v];
      count[u] -= count[v];
      dp[v] += dp[u] + count[u];
      count[v] += count[u];

      dfs2(v, u);

      dp[u] = dpU;
      dp[v] = dpV;
      count[u] = countU;
      count[v] = countV;
    }
  }

  for (const [u, v] of edges) {
    graph[u].push(v);
    graph[v].push(u);
  }

  dfs(0, -1);
  dfs2(0, -1);
  return res;
};
