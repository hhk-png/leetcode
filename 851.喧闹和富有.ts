// https://leetcode.cn/problems/loud-and-rich/submissions/

function loudAndRich(richer: number[][], quiet: number[]): number[] {
  const n: number = quiet.length;
  const graph: number[][] = new Array(n).fill(0).map(() => []);
  for (const r of richer) {
    graph[r[1]].push(r[0]);
  }

  const dfs = (i: number) => {
    if (answer[i] !== -1) {
      return answer[i];
    }
    answer[i] = i;
    for (const child of graph[i]) {
      dfs(child);
      if (quiet[answer[child]] < quiet[answer[i]]) {
        answer[i] = answer[child];
      }
    }
  };

  const answer: number[] = new Array(n).fill(-1);
  for (let i = 0; i < n; i++) {
    dfs(i);
  }
  return answer;
}

var loudAndRich2 = function (richer: number[][], quiet: number[]) {
  const n: number = quiet.length;
  const graph: number[][] = new Array(n).fill(0).map(() => []);
  const inDeg: number[] = new Array(n).fill(0);
  for (const r of richer) {
    graph[r[0]].push(r[1]);
    inDeg[r[1]]++;
  }
  const q: number[] = [];
  for (let i = 0; i < n; ++i) {
    if (inDeg[i] === 0) {
      q.push(i);
    }
  }
  const answer: number[] = new Array(n).fill(-1);
  for (let i = 0; i < n; i++) {
    answer[i] = i;
  }

  while (q.length) {
    const val: number = q.shift()!;
    for (const child of graph[val]) {
      if (quiet[answer[child]] > quiet[answer[val]]) {
        answer[child] = answer[val];
      }
      if (--inDeg[child] === 0) {
        q.push(child);
      }
    }
  }

  return answer;
};
