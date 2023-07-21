// https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/submissions/

function maxDepth(root: Node | null): number {
  let res = 0;
  const dfs = (node: Node, depth: number) => {
    if (!node) {
      return
    }
    res = Math.max(res, depth)
    if (node.children.length) {
      for (const child of node.children) {
        dfs(child!, depth + 1)
      }
    }
  }
  dfs(root!, 1)
  return res
};