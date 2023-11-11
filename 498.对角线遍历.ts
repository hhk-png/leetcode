// https://leetcode.cn/problems/diagonal-traverse/

function findDiagonalOrder(mat: number[][]): number[] {
  const m: number = mat.length;
  const n: number = mat[0].length;
  const res: number[] = [];
  let pos: number = 0;
  for (let i = 0; i < m + n - 1; i++) {
    if (i % 2 === 1) {
      let x: number = i < n ? 0 : i - n + 1;
      let y: number = i < n ? i : n  - 1;
      while (x < m && y >= 0) {
        res.push(mat[x][y]);
        x++;
        y--;
      }
    } else {
      let x: number = i < m ? i : m - 1;
      let y: number = i < m ? 0 : i - m + 1;
      while (x >= 0 && y < n) {
        res.push(mat[x][y]);
        x--;
        y++;
      }
    }
  }

  return res;
};

