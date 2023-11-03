// https://leetcode.cn/problems/n-ary-tree-postorder-traversal/description/

class TNode {
  val: number
  children: TNode[]
  constructor(val?: number) {
      this.val = (val===undefined ? 0 : val)
      this.children = []
  }
}


function postorder(root: TNode | null): number[] {
  const res: number[] = []
  const helper = (node: TNode | null) => {
      if (!node) {
          return
      }
      for (const child of node.children) {
          helper(child)
      }
      res.push(node.val)
  }
  helper(root)
  return res
};