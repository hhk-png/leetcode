// https://leetcode.cn/problems/shortest-path-visiting-all-nodes/solutions/918311/fang-wen-suo-you-jie-dian-de-zui-duan-lu-mqc2/

function shortestPathLength(graph: number[][]): number {
  const n: number = graph.length;
  const queue: number[][] = [];
  const seen: boolean[][] = new Array(n).fill(0).map(() => new Array(1 << n).fill(false));
  for (let i = 0; i < n; i++) {
    queue.push([i, 1 << i, 0]);
    seen[i][1 << i] = true;
  }

  let res: number = 0;
  while (queue.length) {
    const temp: number[] = queue.shift()!;
    const index: number = temp[0];
    const mask: number = temp[1];
    const distance: number = temp[2];
    if (mask === (1 << n) - 1) {
      res = distance;
      break;
    }
    for (const node of graph[index]) {
      const maskNode = mask | (1 << node);
      if (!seen[node][maskNode]) {
        queue.push([node, maskNode, distance + 1]);
        seen[node][maskNode] = true;
      }
    }
  }
  return res;
};

