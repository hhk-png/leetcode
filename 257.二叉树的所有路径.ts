/**
 * 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

    叶子节点 是指没有子节点的节点。

 
 */

class TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }
}

function binaryTreePaths(root: TreeNode | null): string[] {
  const result: string[] = [];
  const ans: string = "";
  const dfs = (root: TreeNode | null, ans: string) => {
    if (!root.left && !root.right) {
      result.push(ans + root.val);
      return;
    }

    if (root.left) dfs(root.left, ans + root.val + "->");
    if (root.right) dfs(root.right, ans + root.val + "->");
  };

  dfs(root, ans);
  return result;
}
