// https://leetcode.cn/problems/battleships-in-a-board/submissions/

// var countBattleships = function(board) {
//   const row = board.length;
//   const col = board[0].length;
//   let ans = 0;
//   for (let i = 0; i < row; ++i) {
//       for (let j = 0; j < col; ++j) {
//           if (board[i][j] === 'X') {
//               board[i][j] = '.';
//               for (let k = j + 1; k < col && board[i][k] === 'X'; ++k) {
//                   board[i][k] = '.';
//               }                    
//               for (let k = i + 1; k < row && board[k][j] === 'X'; ++k) {
//                   board[k][j] = '.';
//               }
//               ans++;
//           }
//       }
//   }
//   return ans;
// };


function countBattleships(board: string[][]): number {
  const n: number = board.length
  const m: number = board[0].length
  let res: number = 0
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (board[i][j] === 'X') {
        if (board[i][j - 1] === 'X') {
          continue
        }
        if (board[i - 1][j] === 'X') {
          continue
        }
        res++
      }
    }
  }
  return res
};



