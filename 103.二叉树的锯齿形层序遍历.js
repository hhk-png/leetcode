/*
    给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

    例如：
    给定二叉树 [3,9,20,null,null,15,7],

        3
       / \
      9  20
        /  \
       15   7
    返回锯齿形层序遍历如下：

    [
      [3],
      [20,9],
      [15,7]
    ]
*/

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var zigzagLevelOrder = function (root) {
    // 特判
    if (!root) return [];
    // result
    const result = [];
    // 用于遍历
    const queue = [root];
    // 层级
    let level = 0;

    while (queue.length) {
        // 先开辟一个新数组，用于存放本层的结果
        result.push([]);
        // 用于判断向数组中添加数据的方式
        let isOrder = level % 2 === 0;
        for (let i = 0, len = queue.length; i < len; i++) {
            let node = queue.shift();
            if (isOrder)
                result[level].push(node.val)
            else 
                result[level].unshift(node.val)
            

            // 准备下一层需要遍历的结点
            if (node.left) queue.push(node.left);
            if (node.right) queue.push(node.right);

        }
        // 本层遍历完毕，进入下一层
        level++;
    }

    return result;
};