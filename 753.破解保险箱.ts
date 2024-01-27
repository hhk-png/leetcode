// https://leetcode.cn/problems/cracking-the-safe/description/

function crackSafe(n: number, k: number): string {
  const highest: number = Math.pow(10, n - 1);
  let ans: string = "";
  const seen: Set<number> = new Set();
  const dfs = (node: number) => {
    for (let i = 0; i < k; i++) {
      const nextNode = node * 10 + i;
      if (!seen.has(nextNode)) {
        seen.add(nextNode);
        dfs(nextNode % highest);
        ans += i;
      }
    }
  }

  dfs(0);
  for (let i = 1; i < n; i++) {
    ans += "0";
  }
  return ans;
};

crackSafe(3, 10);
