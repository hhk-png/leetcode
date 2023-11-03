// https://leetcode.cn/problems/cheapest-flights-within-k-stops/submissions/

function findCheapestPrice(n: number, flights: number[][], src: number, dst: number, k: number): number {
  const dp = new Array(k + 2).fill(0).map(() => new Array(n).fill(Infinity));
  dp[0][src] = 0;

  for (let t = 1; t < k + 2; t++) {
    for (const flight of flights) {
      const from: number = flight[0];
      const to: number = flight[1];
      const cost: number = flight[2];
      // 走这一段 flight，和不走这一段 flight
      dp[t][to] = Math.min(dp[t][to], dp[t - 1][from] + cost);
    }
  }

  let ans: number = Infinity;
  for (let t = 1; t < k + 2; t++) {
    ans = Math.min(ans, dp[t][dst]);
  }
  return isFinite(ans) ? ans : -1;
};

