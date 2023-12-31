/*
    给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

    说明：
    你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

    示例 1:
    输入: root = [3,1,4,null,2], k = 1
      3
      / \
    1   4
      \
       2
    输出: 1

    示例 2:
    输入: root = [5,3,6,2,4,null,null,1], k = 3
          5
          / \
        3   6
        / \
      2   4
      /
    1
    输出: 3
*/
/**
 * 
 * 二叉树的中序遍历
 */
/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function (root, k) {
  let stack = [];

  while (true) {
    while (root) {
      stack.push(root);
      root = root.left;
    }
    root = stack.pop();
    if (--k === 0) return root.val;
    root = root.right;
  }
};
