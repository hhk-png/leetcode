// https://leetcode.cn/problems/n-ary-tree-level-order-traversal/submissions/

class TNode {
  val: number
  children: TNode[]
  constructor(val?: number) {
      this.val = (val===undefined ? 0 : val)
      this.children = []
  }
}


function levelOrder(root: TNode | null): number[][] {
if (!root) {
      return []
  }
  const res: number[][] = []
  const queue: TNode[] = []
  queue.push(root)
  while (queue.length) {
      const temp: number[] = []
      const n: number = queue.length
      for (let i = 0; i < n; i++) {
          const node: TNode = queue.shift()!
          temp.push(node.val)
          for (const child of node.children) {
              if (child) {
                  queue.push(child)
              }
          }
      }
      res.push(temp)
  }
  return res
};