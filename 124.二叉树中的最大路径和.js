/*
    给定一个非空二叉树，返回其最大路径和。

    本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

    示例 1:
    输入: [1,2,3]

          1
          / \
        2   3

    输出: 6

    示例 2:
    输入: [-10,9,20,null,null,15,7]

       -10
       / \
      9  20
        /  \
       15   7

    输出: 42
*/

// Number.MIN_VALUE 是无限趋近于0的值，大于0

var maxPathSum = function(root) {
  // 设置为负无穷
  let maxSum = -Infinity;
  let maxRoot = function(node) {
    // node没有根节点的情况
    if(node == null) return 0;

    // 计算左右路径的最大值
    let left_node = Math.max(maxRoot(node.left), 0);
    let right_node = Math.max(maxRoot(node.right), 0);

    // 检查是维护旧路径还是创建新路径
    let nodeSum = node.val + left_node + right_node;
    // 当新路径更好的时候更新maxSum
    maxSum = Math.max(nodeSum, maxSum);

    // 对于递归返回的到当前节点的一条最大路径
    return node.val + Math.max(left_node, right_node);
  }
  maxRoot(root);
  return maxSum;
};