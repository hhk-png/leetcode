
class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null
    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.left = (left===undefined ? null : left)
        this.right = (right===undefined ? null : right)
    }
}


class CBTInserter {
  root: TreeNode
  canidates: TreeNode[]
  constructor(root: TreeNode) {
    this.root = root;
    this.canidates = [];
    
    const queue: TreeNode[] = [root];
    while (queue.length) {
      const node = queue.shift()!;
      if (node.left) {
        queue.push(node.left);
      }
      if (node.right) {
        queue.push(node.right);
      }
      if (!(node.left && node.right)) {
        this.canidates.push(node!);
      }
    }
  }

  insert(val: number): number {
    const child: TreeNode = new TreeNode(val);
    const node: TreeNode = this.canidates[0];
    const ret: number = node.val;
    if (!node.left) {
      node.left = child;
    } else {
      node.right = child;
      this.canidates.shift();
    }
    this.canidates.push(child);
    return ret;
  }

  get_root(): TreeNode | null {
    return this.root;
  }
}
