/*
  给定一个整数 n，返回 n! 结果尾数中零的数量。

  示例 1:
  输入: 3
  输出: 0
  解释: 3! = 6, 尾数中没有零。

  示例 2:
  输入: 5
  输出: 1
  解释: 5! = 120, 尾数中有 1 个零.
    说明: 你算法的时间复杂度应为 O(log n) 。

  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/factorial-trailing-zeroes
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
  https://leetcode-cn.com/problems/factorial-trailing-zeroes/solution/jie-cheng-hou-de-ling-by-leetcode/
*/

var trailingZeroes = function (n) {
  let zeroCount = 0;
  for (let i = 5; i <= n; i += 5) {
    let currentFactor = i;
    while (currentFactor % 5 === 0) {
      zeroCount++;
      currentFactor /= 5;
    }
  }
  return zeroCount;


  // solution 2
  // let count = 0;
  // while (n > 0) {
  //   n = parseInt(n / 5);
  //   count += n;
  // }
  // return count;
};
