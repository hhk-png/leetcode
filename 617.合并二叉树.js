/**
    给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

    你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

    示例 1:

    输入: 
      Tree 1                     Tree 2                  
              1                         2                             
            / \                       / \                            
            3   2                     1   3                        
          /                           \   \                      
          5                             4   7                  
    输出: 
    合并后的树:
          3
          / \
        4   5
        / \   \ 
      5   4   7
    注意: 合并必须从两个树的根节点开始。
 */
// 递归
var mergeTrees = function(t1, t2) {
  // 判断t1或t2为null
  if (t1 === null) {
      return t2;
  }
  if (t2 === null) {
      return t1;
  }
  // 最后只剩下都不为null的情况
  t1.val += t2.val;
  // 没有想到使用返回值来构建二叉树
  // 左子树
  t1.left = mergeTrees(t1.left, t2.left);
  // 右子树
  t1.right = mergeTrees(t1.right, t2.right);

  // 最后返回root
  return t1;
};

// 迭代
// 判断
var mergeTrees = function (t1, t2) {
  // 分开判断t1 t2为null的情况
  if (t1 === null) {
    return t2;
  }
  // 栈
  let stack = [];
  // 成对插入
  stack.push([t1, t2]);

  // 栈不为空的时候停止
  while (stack.length !== 0) {
    // 拿出来一对
    let nodes = stack.pop();
    // 之前已经判断过 nodes[0] === null 的情况
    // 此时值判断node[1]的情况就可以
    if (nodes[1] === null) {
      // 两者都为null就continue
      continue;
    }
    // 只剩下都有值的情况，相加
    nodes[0].val += nodes[1].val;

    // 左子树
    // 就是这个时候判断的nodes[0]===null
    if (nodes[0].left === null) {
      nodes[0].left = nodes[1].left;
    } else {
      // nodes[0]的值存在，nodes[1]的值可能为null
      stack.push([nodes[0].left, nodes[1].left]);
    }
    
    // 右子树，同理
    if (nodes[0].right === null) {
      nodes[0].right = nodes[1].right;
    } else {
      stack.push([nodes[0].right, nodes[1].right]);
    }
  }

  // 最后的结果保存在 t1 内
  return t1;
}
