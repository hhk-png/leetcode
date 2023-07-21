/*
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

进阶：

一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个仅使用常量空间的解决方案吗？
*/


var setZeroes = function(matrix) {
  let R = matrix.length;
  let C = matrix[0].length;
  let rows = new Set();
  let cols = new Set();

  // 不能再本次扫描过程中，进行置0的操作
  //  会影响扫描的正常运行，只能再扫描完成之后再进行置0
  for (let r = 0; r < R; r++) {
      for (let c = 0; c < C; c++) {
          if (matrix[r][c] === 0) {
              rows.add(r);
              cols.add(c);
          }
      }
  }


  for (let i = 0; i < R; i++) {
      for (let j = 0; j < C; j++) {
          if (cols.has(j) || rows.has(i)) {
              matrix[i][j] = 0;
          }
      }
  }

};