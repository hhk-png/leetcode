function TreeNode(val) {
  this.val = val;
  this.left = this.right = null;
}

var arr = [5,4,8,11,null,13,4,7,2,null,null,5,1];

// 按照层次来生成二叉树节点
function getTree(arr){
  // 存放每一层节点的数组
  var nodeArr = [];
  // 生成根节点，并push到nodeArr中
  var value = arr.shift();
  var root = new TreeNode(value);
  nodeArr.push(root);
  // 数组不为空，就说明还有节点
  while(arr.length > 0) {
    // 存放下一层需要生成左右子树的节点
    var tempArr = [];
    // 每一次for循环生成一层，左右子树节点
    for(let i = 0; i< nodeArr.length && arr.length != 0; i++) {
      // 节点数组不为空，还有节点存在
      if(nodeArr[i] != null) {
        // 需要生成左右子树的节点
        let e = nodeArr[i];
        // 左节点
        let leftNode = arr.shift()
        if(leftNode === null) {
          left = null;
        }else {
          left = new TreeNode(leftNode);
        }
        // 右节点
        let rightNode = arr.shift();
        if(rightNode === null) {
          right = null;
        }else {
          right = new TreeNode(rightNode);
        }

        // 构建
        e.left = left;
        e.right = right;
        // push
        tempArr.push(left);
        tempArr.push(right);
      }
    }
    // 下一层
    nodeArr = tempArr;
  }
  return root;
}