/*
    给定一个二叉树，它的每个结点都存放着一个整数值。

    找出路径和等于给定数值的路径总数。

    路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

    二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

    示例：

    root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

          10
        /  \
        5   -3
      / \    \
      3   2   11
    / \   \
    3  -2   1

    返回 3。和等于 8 的路径有:

    1.  5 -> 3
    2.  5 -> 2 -> 1
    3.  -3 -> 11
*/
/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {number}
 */
// 计算以当前节点为路径终点的所有路径和
// array保存的是一条线上的数值
var pathSum = function(root, sum) {
  return innerPathSum(root, sum, new Array(), 0);
};

function innerPathSum(node, sum, array, p) {
  // 节点为空，返回0
  if(!node) return 0;

  // 记录此节点的值
  let tmp = node.val;
  // 如果此节点刚好等于sum，n初始化为1
  let n = (tmp === sum) ? 1 : 0;
  // 向上查看array的元素
  for(let i = p-1; i >= 0; i--) {
      tmp += array[i];
      if(tmp === sum) 
          n++;
  }

  // 记录此节点的值
  array[p] = node.val;

  let n1 = innerPathSum(node.left, sum, array, p + 1);
  let n2 = innerPathSum(node.right, sum, array, p + 1);
  return n + n1 + n2;
}