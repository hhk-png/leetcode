// https://leetcode.cn/problems/count-complete-tree-nodes/submissions/

class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.left = (left===undefined ? null : left)
        this.right = (right===undefined ? null : right)
    }
}

const exists = (root: TreeNode | null, level: number, k: number) => {
  let bits = 1 << (level - 1);
  let node = root;
  while (node !== null && bits > 0) {
      if (!(bits & k)) {
          node = node.left;
      } else {
          node = node.right;
      }
      bits >>= 1;
  }
  return node !== null;
}

var countNodes = function(root: TreeNode | null) {
  if (root === null) {
      return 0;
  }
  let level = 0;
  let node = root;
  while (node.left !== null) {
      level++;
      node = node.left;
  }
  let low = 1 << level, high = (1 << (level + 1)) - 1;
  while (low < high) {
      const mid = Math.floor((high - low + 1) / 2) + low;
      if (exists(root, level, mid)) {
          low = mid;
      } else {
          high = mid - 1;
      }
  }
  return low;
};
