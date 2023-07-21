/*
    在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

    示例:
    输入: 
    1 0 1 0 0
    1 0 1 1 1
    1 1 1 1 1
    1 0 0 1 0
    输出: 4
*/


/**
 * @param {character[][]} matrix
 * @return {number}
 */
// 动态规划方程
// dp(i, j)=min(dp(i−1, j), dp(i−1, j−1), dp(i, j−1))+1
var maximalSquare = function(matrix) {
  let rows = matrix.length, cols = rows > 0 ? matrix[0].length : 0;
  let prev = 0, temp = 0;
  let maxLen = 0;
  let dp = new Array(cols+1).fill(0);

  for(let i = 1; i <= rows; i++) {
    for(let j = 1; j <= cols; j++) {
      let temp = dp[j];
      if(matrix[i-1][j-1] === '1') {
        dp[j] = Math.min(prev, dp[j], dp[j-1]) + 1;
        maxLen = Math.max(maxLen, dp[j]);
      } else {
        dp[j] = 0;
      }
      prev = temp;
    }
  }

  return maxLen*maxLen;
};