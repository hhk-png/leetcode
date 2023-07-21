var deleteBSTNode = function (root, key) {
  if (root === null) return null;
  if (root.val === key) {
    if(root.right === null) return root.left;
    if(root.left === null) return root.right;

    let minNode = getMin(root.right);
    root.val = minNode.val;
    root.right = deleteBSTNode(root.right, minNode.val);

  } else if (root.val < key) {
    // 该删除的结点在右子树
    root.right = deleteBSTNode(root.right, key);
  } else if (root.val > key) {
    // 该删除的结点在左子树
    root.left = deleteBSTNode(root.left, key);
  }
}

function getMin(root) {
  while(root !== null) 
    root = root.left;
  return root
}