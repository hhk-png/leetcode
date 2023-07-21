/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function(nums) {
  // 获取数组长度，为0直接返回false
  let len = nums.length;
  if(len === 0) return false;

  // 数组各元素的和
  let sum = nums.reduce((acc, num) => acc += num);

  // 如果为奇数，就不符合要求，因为 奇数/2 有.5
  if((sum & 1) === 1 ) return false;

  // 目标值
  let target = sum >> 1;

  // 初始化二维数组
  let dp = new Array();
  for(let i = 0; i <= len; i++) {
    dp[i] = new Array(target+1);
  }
  // 第 1 个数只能让容积为它自己的背包恰好装满
  if (nums[0] <= target) {
    dp[0][nums[0]] = true;
  }

  // 动态规划主体
  for(let i = 1; i < len; i++) {
    for(let j = 0; j <= target; j++) {
      
      // 可以看作是 nums[i] > target(j)
      // 那么使用nums[0, i-1]之间的数，就可以判断是否能填满target(j)
      dp[i][j] = dp[i-1][j];

      // 如果相等，num[i]本身就能填满target(j)
      if(nums[i] === j) {
        dp[i][j] = true;
        // 并且跳过本次循环
        continue;
      }
        
      // nums[i] < target(j)的话，
      // 说明本身的nums[i]不能填满target(j)
      // 需要使用nums[0, i]之间的数，才能判断是否能填满target(j)
      if(nums[i] < j) {
        // dp[i - 1][j]
        // 从第 i-1 行搜索能否填满 j - nums[i]
        // dp[i - 1][j - nums[i]]
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
      }
        
    }

    /*
      for (let j = 0; j <= target; j++) {

        dp[i][j] = dp[i - 1][j];

        if (nums[i] <= j) {
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
        }
      }

      // 由于状态转移方程的特殊性，提前结束，可以认为是剪枝操作
      if (dp[i][target]) {
          return true;
      }
    */
  
  }

  // 返回
  return dp[len-1][target] === undefined ? false : dp[len-1][target];
}

// 一维数组
var canPartition = function(nums) {
  let len = nums.length;
  if(len === 0) return false;

  let sum = nums.reduce((acc, num) => acc += num);

  if((sum & 1) === 1 ) return false;

  let target = sum >> 1;

  let dp = new Array(target+1).fill(0);

  dp[0] = true;

  for (let i = 1; i < len; i++) {
    for (let j = target; nums[i] <= j; j--) {
      if (dp[target]) {
        return true;
      }

      dp[j] = dp[j] || dp[j - nums[i]];
    }
  }
  return dp[target];
}