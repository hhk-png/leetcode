// https://leetcode.cn/problems/construct-quad-tree/submissions/480974600/

class TreeNode {
  val: boolean
  isLeaf: boolean
  topLeft: Node | null
  topRight: Node | null
  bottomLeft: Node | null
  bottomRight: Node | null
  constructor(val?: boolean, isLeaf?: boolean, topLeft?: Node, topRight?: Node, bottomLeft?: Node, bottomRight?: Node) {
    this.val = (val === undefined ? false : val)
    this.isLeaf = (isLeaf === undefined ? false : isLeaf)
    this.topLeft = (topLeft === undefined ? null : topLeft)
    this.topRight = (topRight === undefined ? null : topRight)
    this.bottomLeft = (bottomLeft === undefined ? null : bottomLeft)
    this.bottomRight = (bottomRight === undefined ? null : bottomRight)
  }
}

function construct(grid: number[][]): TreeNode | null {
  const dfs = (r0: number, c0: number, r1: number, c1: number) => {
    let isSame: boolean = true;
    for (let i = r0; i < r1; i++) {
      for (let j = c0; j < c1; j++) {
        if (grid[i][j] !== grid[r0][c0]) {
          isSame = false;
          break;
        }
      }
      if (!isSame) {
        break;
      }
    }

    if (isSame) {
      return new TreeNode(grid[r0][c0] === 1, true);
    }

    return new TreeNode(
      true,
      false,
      dfs(r0, c0, (r0 + r1) >> 1, (c0 + c1) >> 1),
      dfs(r0, (c0 + c1) >> 1, (r0 + r1) >> 1, c1),
      dfs((r0 + r1) >> 1, c0, r1, (c0 + c1) >> 1),
      dfs((r0 + r1) >> 1, (c0 + c1) >> 1, r1, c1)
    )
  }

  return dfs(0, 0, grid.length, grid.length);
};
