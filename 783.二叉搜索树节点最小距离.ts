// https://leetcode.cn/problems/minimum-distance-between-bst-nodes/submissions/

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

function minDiffInBST(root: TreeNode | null): number {
  let res: number = Infinity;
  let pre: number = -1;

  const dfs = (root: TreeNode | null) => {
    if (!root) {
      return;
    }

    dfs(root.left);
    if (pre === -1) {
      pre = root.val;
    } else {
      res = Math.min(res, root.val - pre);
      pre = root.val;
    }
    dfs(root.right);

  };

  dfs(root);
  return res;
};
