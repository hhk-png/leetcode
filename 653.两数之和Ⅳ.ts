// https://leetcode.cn/problems/two-sum-iv-input-is-a-bst/solutions/

var findTarget = function(root: TreeNode | null, k: number) {
  const set = new Set();
  const queue = [];
  queue.push(root);
  while (queue.length) {
      const node = queue.shift();
      if (set.has(k - node.val)) {
          return true;
      }
      set.add(node.val);
      if (node.left) {
          queue.push(node.left);
      }
      if (node.right) {
          queue.push(node.right);
      }
  }
  return false;
};

var findTarget2 = function(root, k) {
  const list = [];
  const inorderTraversal = (node) => {
      if (!node) {
          return;
      }
      inorderTraversal(node.left);
      list.push(node.val);
      inorderTraversal(node.right);
  }
  inorderTraversal(root);
  let left = 0, right = list.length - 1;
  while (left < right) {
      if (list[left] + list[right] === k) {
          return true;
      }
      if (list[left] + list[right] < k) {
          left++;
      } else {
          right--;
      }
  }
  return false;
};

var findTarget3 = function(root, k) {
  const getLeft = (stack) => {
      const root = stack.pop();
      let node = root.right;
      while (node) {
          stack.push(node);
          node = node.left;
      }
      return root;
  }

  const getRight = (stack) => {
      const root = stack.pop();
      let node = root.left;
      while (node) {
          stack.push(node);
          node = node.right;
      }
      return root;
  };

  let left = root, right = root;
  const leftStack = [];
  const rightStack = [];
  leftStack.push(left);
  while (left.left) {
      leftStack.push(left.left);
      left = left.left;
  }
  rightStack.push(right);
  while (right.right) {
      rightStack.push(right.right);
      right = right.right;
  }
  while (left !== right) {
      if (left.val + right.val === k) {
          return true;
      }
      if (left.val + right.val < k) {
          left = getLeft(leftStack);
      } else {
          right = getRight(rightStack);
      }
  }
  return false;
}




