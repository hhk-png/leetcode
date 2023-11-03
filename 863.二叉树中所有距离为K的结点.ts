// https://leetcode.cn/problems/all-nodes-distance-k-in-binary-tree/submissions/

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


function distanceK(root: TreeNode | null, target: TreeNode | null, k: number): number[] {
  const parent: Map<number, TreeNode> = new Map();
  const ans: number[] = [];
  if (!root) return [];
  const findParent = (node: TreeNode) => {
    if (node.left) {
      parent.set(node.left.val, node);
      findParent(node.left);
    }
    if (node.right) {
      parent.set(node.right.val, node);
      findParent(node.right);
    }
  }

  findParent(root);

  // node: 下一个要遍历的节点
  // from: 遍历当前节点时，上一个经过的结点
  const findAns = (node: TreeNode | null, from: TreeNode | null, depth: number) => {
    if (!node) {
      return ;
    }
    if (depth === k) {
      ans.push(node.val);
      return ;
    }
    if (node.left !== from) {
      findAns(node.left, node, depth + 1);
    }
    if (node.right !== from) {
      findAns(node.right, node, depth + 1);
    }
    if (parent.get(node.val) !== from) {
      findAns(parent.get(node.val)!, node, depth + 1);
    }
  }

  findAns(target, null, 0);

  return ans;
};

