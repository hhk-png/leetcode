// https://leetcode.cn/problems/binary-search-tree-iterator/

class TreeNode {
  val: number
  left: TreeNode | null
  right: TreeNode | null
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
  }
}

function* BSTGenerator(root: TreeNode | null) {
  let node: TreeNode | null = root;
  const stack: TreeNode[] = [];
  while (node || stack.length) {
    while (node) {
      stack.push(node);
      node = node.left;
    }
    const n = stack.pop();
    yield n;
    node = n!.right;
  }
}

const BSTLastNode = (root: TreeNode | null): TreeNode => {
  let res: TreeNode | null = root;
  while(res?.right) {
    res = res.right;
  }
  return res!;
}

class BSTIterator {
  it: Generator;
  lastNode: TreeNode | null;
  currNode: TreeNode | null;
  constructor(root: TreeNode | null) {
    this.it = BSTGenerator(root);
    this.lastNode = BSTLastNode(root);
    this.currNode = null;
  }

  next(): number {
    const curr = this.it.next();
    this.currNode = curr.value;
    return this.currNode!.val;
  }

  hasNext(): boolean {
    return this.currNode !== this.lastNode;
  }
}

