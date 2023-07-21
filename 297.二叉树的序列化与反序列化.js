/*
    序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

    请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

    示例: 

    你可以将以下二叉树：

        1
      / \
      2   3
        / \
        4   5

    序列化为 "[1,2,3,null,null,4,5]"
*/

/**
* Encodes a tree to a single string.
*
* @param {TreeNode} root
* @return {string}
*/
var serialize = function(root) {
  if(!root) return "";

  // 存储数据的字符串
  let data = "",
      // 遍历队列
      queue = [root];
  // queue为空时退出
  while(queue.length) {
    // 遍历queue的操作
    let node = queue.shift();
    // node可能为null
    // node为空时用"#"表示，使用","隔开
    if(node) {
      data = data + node.val + ",";
      // 先加入左节点
      queue.push(node.left);
      // 后加入右节点
      queue.push(node.right);
    } else {
      // 为空时,添加"#"
      data += "#,";
    }
  }

  // 去掉最后一个逗号
  return data.substring(0, data.length-1);
};

/**
* Decodes your encoded data to tree.
*
* @param {string} data
* @return {TreeNode}
*/
var deserialize = function(data) {
  // 数据为空时,返回null
  if(!data.length) return null;

  // 通过split转化为一个存放数据数组
  let nodes = data.split(",");
  // 弹出第一个数据为根节点
  let root = new TreeNode(nodes.shift());
  // 建造二叉树使用的队列
  let queue = [root];

  // queue为空时返回
  while(queue.length) {
    // 建造二叉树的操作
    let node = queue.shift();
    // 先左值
    let leftVal = nodes.shift();
    // 为空时跳过
    if(leftVal !== "#") {
      // 创造节点
      node.left = new TreeNode(leftVal);
      // 向队列中加入左节点
      queue.push(node.left);
    }

    // 后右值
    let rightVal = nodes.shift();
    if(rightVal !== "#") {
      // 创造右节点
      node.right = new TreeNode(rightVal);
      // 向队列中push
      queue.push(node.right);
    }
  }

  // 返回二叉树的根节点
  return root;
};

/**
* Your functions will be called as such:
* deserialize(serialize(root));
*/