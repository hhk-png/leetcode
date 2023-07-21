// 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

// 例如，给出 n = 3，生成结果为：

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

// 1.回溯
var generateParenthesis = function(n) {
  if( n === 0 ) return [];
  let ans = [];
  dfs(ans, '', 0, 0, n);
  return ans;
};

function dfs (ans, str, open, close, max) {
  if(str.length === max*2) {
      ans.push(str);
      return;
  }
  // close -> open -> max
  if(open < max) {
      dfs(ans, str + '(', open + 1, close, max);
  }

  if(close < open) {
      dfs(ans, str + ')', open, close + 1, max);
  }
}