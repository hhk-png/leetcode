
/*

序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。

设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。

编码的字符串应尽可能紧凑。

 

示例 1：

输入：root = [2,1,3]
输出：[2,1,3]
示例 2：

输入：root = []
输出：[]

*/

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
 var serialize = function(root) {
  const queue = [];
  queue.push(root);
  let result = "";

  while (queue.length) {
      const currNode = queue.shift();
      if (currNode) {
          result += currNode.val;
          result += ',';
          queue.push(currNode.left);
          queue.push(currNode.right);
      } else {
          result += '#,';
      }
  }

  return result.substr(0, result.length - 1);
};

/**
* Decodes your encoded data to tree.
*
* @param {string} data
* @return {TreeNode}
*/
var deserialize = function(data) {
  if (!data) return new TreeNode();

  const nodes = data.split(',').map(val => val == '#' ? null : new TreeNode(parseInt(val)));

  const root = nodes.shift();
  const queue = [root];

  while (queue.length) {
      const currNode = queue.shift();
      if (currNode) {
          const left = nodes.shift();
          const right = nodes.shift();
          queue.push(left);
          queue.push(right);
          currNode.left = left;
          currNode.right = right;
      }
  }

  return root;
  
};

/**
* Your functions will be called as such:
* deserialize(serialize(root));
*/