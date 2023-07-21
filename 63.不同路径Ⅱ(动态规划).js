// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

// 网格中的障碍物和空位置分别用 1 和 0 来表示。

// 说明：m 和 n 的值均不超过 100。

// 示例
// 输入:
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// 输出: 2

var uniquePathsWithObstacles = function(obstacleGrid) {
  // 说明start位置有障碍物，机器人不能做任何移动
  if(obstacleGrid[0][0] === 1) {
      return 0;
  }

  let R = obstacleGrid.length;
  let C = obstacleGrid[0].length;

  obstacleGrid[0][0] = 1;
  /*
   第一行
   通过前面的值去控制后面的值
   如果只是将第一行(列)的值取反
   [
     [0, 0],
     [1, 1],
     [0, 0]
   ]
   这种情况就会报错，
   因为如果第一行(列)出现了'1'那么它之后的内容就应该全部是0
   */
  for(let i=1; i<C; i++) {
      obstacleGrid[0][i] = (obstacleGrid[0][i - 1] == 1 && obstacleGrid[0][i] == 0) ? 1 : 0;
  }

  // 第一列
  for(let j=1; j<R; j++) {
      obstacleGrid[j][0] = (obstacleGrid[j - 1][0] == 1 && obstacleGrid[j][0] == 0) ? 1 : 0;
  }

  for(let m = 1; m < R; m++) {
      for(let n = 1; n < C; n++) {
          if(obstacleGrid[m][n] === 0) {
              obstacleGrid[m][n] = obstacleGrid[m-1][n] + obstacleGrid[m][n-1];
          }else {
              obstacleGrid[m][n] = 0;
          }
      }
  }

  return obstacleGrid[R-1][C-1];
};