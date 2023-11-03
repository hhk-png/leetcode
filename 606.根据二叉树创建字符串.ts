// https://leetcode.cn/problems/construct-string-from-binary-tree/solutions/1343920/gen-ju-er-cha-shu-chuang-jian-zi-fu-chua-e1af/

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


function tree2str(root: TreeNode | null): string {
  if (!root) {
      return ''
  }
  if (!root.left && !root.right) {
      return '' + root.val
  }
  // 右子树为空，则右子树不需要空括号
  if (!root.right) {
      return root.val + '(' + tree2str(root.left) + ')'
  }
  // 左子树为空的情况，需要加上空括号
  return root.val + '(' + tree2str(root.left) + ')(' + tree2str(root.right) + ')'
};


