// https://leetcode.cn/problems/n-ary-tree-preorder-traversal/description/

class TNode {
  val: number
  children: TNode[]
  constructor(val?: number) {
      this.val = (val===undefined ? 0 : val)
      this.children = []
  }
}


function preorder(root: TNode | null): number[] {
  const res: number[] = []
  const helper = (node: TNode | null) => {
      if (!node) {
          return
      }
      res.push(node.val)
      for (const child of node.children) {
          helper(child)
      }
  }
  helper(root)
  return res
};


function preorder2(root: TNode | null): number[] {
  if (!root) {
      return []
  }
  const res: number[] = []
  const stack: (TNode | null)[] = []
  // nodeIndex 是为了保存前一个遍历过的节点
  const nodeIndex: Map<TNode, number> = new Map()
  let node: TNode | null = root
  while (stack.length || node) {
      while (node) {
          stack.push(node)
          res.push(node.val)
          if (!node.children) {
              break
          }
          // 叶子节点不需要放到 nodeIndex 中，该叶子节点的值已经被添加到了 res 中
          nodeIndex.set(node, 1)
          node = node.children[0]
      }
      // 取父节点
      node = stack[stack.length - 1]!
      // 父节点的 index
      const index = nodeIndex.get(node)!
      // 横向遍历
      if (index < node.children.length) {
          // 为的是保存前一个遍历过的节点，当前节点
          nodeIndex.set(node, index + 1)
          // 前往下一个兄弟节点，并且更新 nodeIndex 中
          node = node.children[index]
      } else {
          stack.pop()
          nodeIndex.delete(node)
          node = null
      }
  }
  return res
};

