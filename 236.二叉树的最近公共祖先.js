
// 递归
let ans;
var lowestCommonAncestor = function(root, p, q) {
  recurseTree(root, p, q);
  return ans;
}
function recurseTree(currentNode, p, q) {
  
  // If reached the end of a branch, return false.
  if (currentNode == null) {
    return false;
  }

  // true和left若为true
  // 可以通过mid + left + right > 0一直向上延续
  // Left Recursion. If left recursion returns true, set left = 1 else 0
  let left = recurseTree(currentNode.left, p, q) ? 1 : 0;

  // Right Recursion
  let right = recurseTree(currentNode.right, p, q) ? 1 : 0;

  // If the current node is one of p or q
  let mid = (currentNode == p || currentNode == q) ? 1 : 0;


  // If any two of the flags left, right or mid become True
  if (mid + left + right >= 2) {
    ans = currentNode;
  }

  // Return true if any one of the three bool values is True.
  return (mid + left + right > 0);
}

// 使用父指针迭代
var lowestCommonAncestor = function(root, p, q) {
  let stack = new Array();
  let parent = new Map();

  parent.set(root, null);
  stack.push(root);

  // Iterate until we find both the nodes p and q
  while(!parent.has(p) || !parent.has(q)) {
    let node = stack.shift();

    // While traversing the tree, keep saving the parent pointers.
    if(node.left !== null) {
      parent.set(node.left, node);
      stack.push(node.left);
    }
    if(node.right !== null) {
      parent.set(node.right, node);
      stack.push(node.right);
    }
  }

  // q 和 p一定相交于同一个父节点
  let ancester = new Set();
  while(p !== null) {
    ancester.add(p);
    p = parent.get(p);
  }
  while(!ancester.has(q)) {
    q = parent.get(q);
  }

  return q;
}