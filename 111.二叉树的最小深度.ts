// https://leetcode.cn/problems/minimum-depth-of-binary-tree/submissions/

function minDepth(root: TreeNode | null): number {
  if (!root) {
      return 0;
  }
  if (!root.left && !root.right) {
      return 1;
  }
  let depth: number = Number.POSITIVE_INFINITY;
  if (root.left !== null) {
      depth = Math.min(depth, minDepth(root.left))
  }
  if (root.right !== null) {
      depth = Math.min(depth, minDepth(root.right))
  }
  return depth + 1
};