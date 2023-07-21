/**
 * // Definition for a Node.
 * function Node(val, left, right, next) {
 *    this.val = val === undefined ? null : val;
 *    this.left = left === undefined ? null : left;
 *    this.right = right === undefined ? null : right;
 *    this.next = next === undefined ? null : next;
 * };
 */

/**
 * @param {Node} root
 * @return {Node}
 */

// 层次遍历，
var connect = function (root) {
  if (root === null) return root;
  let queue = [root];

  while (queue.length !== 0) {
    let len = queue.length;
    // for (let i = 0; i < len; i++) {
    //     queue[i].next = queue[i + 1] ? queue[i + 1] : null;
    // }
    for (let i = 0; i < len; i++) {
      let node = queue.shift();

      // 处理核心
      if (i < len - 1) node.next = queue[0];

      if (node.left) queue.push(node.left);
      if (node.right) queue.push(node.right);
    }
  }

  return root;
};
