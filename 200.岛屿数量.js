/*
    给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

    示例 1:
    输入:
    11110
    11010
    11000
    00000
    输出: 1

    示例 2:
    输入:
    11000
    11000
    00100
    00011
    输出: 3
*/
// 深度优先搜索 dfs
function dfs(grid, r, n) {
  let rc = grid.length;
  let nc = grid[0].length;

  if(r < 0 || n < 0 || r >= rc || n >= nc || grid[r][n] === '0') {
      return ;
  }

  grid[r][n] = '0';
  dfs(grid, r+1, n);
  dfs(grid, r-1, n);
  dfs(grid, r, n+1);
  dfs(grid, r, n-1);
}
var numIslands = function(grid) {
  if(!grid.length) return 0;
  let rc = grid.length;
  let nc = grid[0].length;
  let island = 0;

  for(let r = 0; r < rc; r++) {
      for(let n = 0; n < nc; n++) {
          if(grid[r][n] === '1') {
              ++island;
              dfs(grid, r, n);
          }
      }
  }
  return island;
};