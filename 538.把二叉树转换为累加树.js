/*
    给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

     

    例如：

    输入: 原始二叉搜索树:
                  5
                /   \
              2     13

    输出: 转换为累加树:
                18
                /   \
              20     13
*/


var convertBST = function(root) {
  // 判断
  if (!root) return root;
  // 从右往左的累加和，最右边时为0
  let shareNum = 0;
  // convert函数
  let convert = (root) => {
      if(!root) return ;
      // 右子树
      convert(root.right);
      // root
      // 更新root.val
      root.val += shareNum;
      // 更新shareNum
      shareNum = root.val;
      // 左子树
      convert(root.left);
  }
  // 调用
  convert(root);
  // 返回
  return root;
};

// 栈
var convertBST = function(root) {
  if (root === null) return null;
  let stack = [],
      sum = 0;
  let node = root;
  while (stack.length > 0 || node !== null) {
      if (node) {
          stack.push(node);
          node = node.right;
      } else {
          node = stack.pop();
          sum += node.val;
          node.val = sum;
          node = node.left;
      }
  }
  return root;
};