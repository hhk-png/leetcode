/**
    给定一个未排序的整数数组，找出最长连续序列的长度。

    要求算法的时间复杂度为 O(n)。

    示例:

    输入: [100, 4, 200, 1, 3, 2]
    输出: 4
    解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
 */

var longestConsecutive = function(nums) {
  let hash = {};
  for(let val of nums) {
    hash[val] = true;
  }

  let longestStreak = 0;

  for(let val of nums) {
    // 查找范围为[val, ...)
    // !undefined  true
    if(!hash[val-1]) {
      // 记录查找开始值
      let currentNum = val;
      // 当前最大序列
      let currentStreak = 1;

      // 依次查找
      while(hash[currentNum+1]) {
        currentNum+=1;
        currentStreak+=1;
      }

      // update
      longestStreak = Math.max(currentStreak, longestStreak);
    }
  }

  return longestStreak;
}