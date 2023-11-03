// https://leetcode.cn/problems/smallest-subtree-with-all-the-deepest-nodes/

class TreeNode {
  val: number
  left: TreeNode | null
  right: TreeNode | null
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
      this.val = (val === undefined ? 0 : val)
      this.left = (left === undefined ? null : left)
      this.right = (right === undefined ? null : right)
  }
}

function subtreeWithAllDeepest(root: TreeNode | null): TreeNode | null {
  const dfs = (node: TreeNode | null): [number, TreeNode | null] => {
    if (!node) {
      return [0, node];
    }

    const [leftDepth, leftNode] = dfs(node.left);
    const [rightDepth, rightNode] = dfs(node.right);

    if (leftDepth === rightDepth) {
      return [leftDepth + 1, node];
    }

    if (leftDepth > rightDepth) {
      return [leftDepth + 1, leftNode];
    }

    if (leftDepth < rightDepth) {
      return [rightDepth + 1, rightNode];
    }

    return [0, null];
  }

  return dfs(root)![1];
};


