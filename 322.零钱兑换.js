/*
    给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

    示例 1:
    输入: coins = [1, 2, 5], amount = 11
    输出: 3 
    解释: 11 = 5 + 5 + 1

    示例 2:
    输入: coins = [2], amount = 3
    输出: -1
*/

// 动态规划，自上而下
var coinChange = function(coins, amount) {
  // 需要凑成的硬币总额不合法时，
  if(amount < 1) return 0;
  // 剪枝数组，用来存放相应amount所对应的最少硬币个数
  let count = new Array(amount + 1).fill(0);
  return coinChanged(coins, amount, count);
}

function coinChanged(coins, nextAmount, count) {
  // 合法条件判断
  // 小于0，返回-1
  if(nextAmount < 0) return -1;
  // 等于0，意味着结束，返回0
  if(nextAmount == 0) return 0;
  // 如果之前有计算过的对应个数，就返回相应的个数
  if(count[nextAmount]) return count[nextAmount];

  // 用来确保count中存放的数值，是最小的
  let min = Infinity;
  // 逐步加大amount
  for(let coin of coins) {
    // 获取最小硬币个数
    let res = coinChanged(coins, nextAmount - coin, count);
    // 确保 0 <= res < min
    // 这样能够min的值在本循环中的值最小
    if(res >= 0 && res < min) {
      // 因为本身是一个循环，所以min的值会随循环的次数改变
      min = res + 1;
    }
  }
  // 存储对应金额的最小金币个数
  count[nextAmount] = (min === Infinity) ? -1 : min;
  // 返回
  return count[nextAmount];
}


// 动态规划，自下而上
var coinChange = function(coins, amount) {
  if(amount < 1) return 0;
  let dp = new Array(amount+1).fill(Infinity);
  // dp数组
  dp[0] = 0;
  for (let i = 1; i <= amount; i++) {
    for(let j = 0; j < coins.length; j++) {
      if(coins[j] <= i)
        dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
    }
  }

  return dp[amount] > amount ? -1 : dp[amount];
}