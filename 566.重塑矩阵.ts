// https://leetcode.cn/problems/reshape-the-matrix/

function matrixReshape(mat: number[][], r: number, c: number): number[][] {
  const m: number = mat.length;
  const n: number = mat[0].length;
  
  if (m * n !== r * c) {
    return mat;
  }

  const res: number[][] = new Array(r).fill(0).map(() => new Array(c).fill(0));;
  const len: number = m * n;
  for (let i = 0; i < len; i++) {
    res[Math.floor(i / c)][i % c] = mat[Math.floor(i / n)][i % n];
  }

  return res;

};
