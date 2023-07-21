// 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

// 说明：每次只能向下或者向右移动一步。

// 输入:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// 输出: 7
// 解释: 因为路径 1→3→1→1→1 的总和最小。

/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
  let R = grid.length;
  let C = grid[0].length;
  // 从左上到右下
  for(let i = 0; i < R; i++) {
      for(let j = 0; j < C; j++) {
          // 在上边缘
          if(i === 0 && j !== 0) {
              grid[i][j] = grid[i][j] + grid[i][j-1];
          } 
          // 在左边缘
          else if (j === 0 && i !== 0) {
              grid[i][j] = grid[i][j] + grid[i-1][j];
          }
          // 不贴近左右边缘
          else if (i !== 0 && j !== 0) {
              grid[i][j] = grid[i][j] + Math.min(grid[i-1][j], grid[i][j-1]);
          }
      }
  }
  
  return grid[R-1][C-1];
};