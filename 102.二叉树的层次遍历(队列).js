/*
    给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

    例如:
    给定二叉树: [3,9,20,null,null,15,7],

        3
      / \
      9  20
        /  \
      15   7
    返回其层次遍历结果：

    [
      [3],
      [9,20],
      [15,7]
    ]
*/


// dfs
var levelOrder = function(root) {
  if(!root) return [];
  let output = [];
  dfs(output, root, 0);
  return output;
};
function dfs(output, root, level){
  if(!root) return;

  // 向output添加完'[]'之后，长度加1，因此每层只会添加一次
  if(level === output.length) output.push([]);
  output[level].push(root.val);

  dfs(output, root.left, level+1);
  dfs(output, root.right, level+1);
}

// 迭代
// 一层一层的遍历，使用push()和shift()
var levelOrder = function(root) {
  // 数组为空
  if(!root) return[];

  // 层级
  let level = 0;
  // 存放最终结果的二维数组
  let output = [];
  // 用来存放每一层的结点
  let queue = [];
  // 初始为第一层
  queue.push(root);

  // 分别遍历每个层级的结点
  while(queue.length !== 0) {
    // 每一层的值都在一个数组中    
    output.push([]);
    let qLen = queue.length;  
    for(let i = 0; i < qLen; i++) {    // queue的长度一直在变化，所以不能使用i<queue.length
      // push每个结点的值
      let node = queue.shift();
      output[level].push(node.val);

      if(node.left) queue.push(node.left);
      if(node.right) queue.push(node.right); 
    }

    // 增加层级
    level++;
  }
  return output;
};