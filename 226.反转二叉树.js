/*
    翻转一棵二叉树。

    示例：
    输入：
        4
      /   \
      2     7
    / \   / \
    1   3 6   9

    输出：
        4
      /   \
      7     2
    / \   / \
    9   6 3   1
*/


// 递归
var invertTree = function(root) {

  if(!root) return null;

  let left = root.left;
  root.left = root.right;
  root.right = left;

  invertTree(root.left);
  invertTree(root.right);
  
  return root;
};


// 迭代
var invertTree = function(root) {

  if(!root) return null;

  let queue = Array();
  queue.push(root);

  while(queue.length !== 0) {
    let curr = queue.shift();
    let temp = curr.left;
    curr.left = curr.right;
    curr.right = temp;

    if(curr.left) queue.push(curr.left);
    if(curr.right) queue.push(curr.right);

  }

  return root;
};