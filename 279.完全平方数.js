/* 
    给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

    示例 1:
    输入: n = 12
    输出: 3 
    解释: 12 = 4 + 4 + 4.

    示例 2:
    输入: n = 13
    输出: 2
    解释: 13 = 4 + 9.
*/
// 动态规划
var numSquares = function(n) {
  let dp = Array(n+1).fill(Infinity);
  dp[0] = 0;

  // 
  let max_square_index = Math.floor(Math.sqrt(n)) + 1;

  // 找到小于等于这个数的所有平方数集合
  let square_nums = Array(max_square_index);
  for(let i = 1; i < max_square_index; i++) {
    square_nums[i] = i * i;
  }

  for(let i = 1; i <= n; i++) {
    for(let s = 1; s < max_square_index; s++) {
      // 需要 i - square_nums[s] > 0
      if(i < square_nums[s]) 
        break;
      // 动态规划方程
      dp[i] = Math.min(dp[i], dp[i-square_nums[s]] + 1);
    }
  }

  return dp[n];
}

// 数学
// 四平方和定理
// 三平方定理
function isSquare(n) {
  let sq = Math.floor(Math.sqrt(n));
  return sq * sq == n;
}

var numSquares = function(n) {
  let nn = n;
  while(n % 4 === 0) 
    n /= 4;
  if(n % 8 === 7)
    return 4;
  
  if(isSquare(nn))
    return 1;
  

  for(let i = 1; i * i <= nn; i++) {
    if(isSquare(nn - i * i))
      return 2;
  }

  return 3;
}


// BFS
var numSquares = function(n) {
  // 初始化n的所有平方数集合
  let square_nums = [];
  for(let i = 1; i <= n; i++) {
    square_nums.push(i * i);
  }

  // BFS队列  初始为n
  let queue = new Set();
  queue.add(n);

  // 深度
  let level = 0;

  while(queue.size > 0) {
    // 每一层深度+1
    level += 1;
    // 声明下一层需要遍历的数
    let next_queue = new Set();

    for(let remainder of queue) {
      for(let square of square_nums) {
        if(remainder === square) {
          return level;
        } else if(remainder < square) {
          break;
        } else {
          next_queue.add(remainder - square);
        }
      }
    }
    // 进入下一层
    queue = next_queue;
  }
  return level;
}