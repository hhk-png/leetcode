/*
    编写一个算法来判断一个数 n 是不是快乐数。

    「快乐数」定义为：

    对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
    然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
    如果 可以变为  1，那么这个数就是快乐数。
    如果 n 是快乐数就返回 true ；不是，则返回 false 。

     

    示例 1：
    输入：19
    输出：true
    解释：
      12 + 92 = 82
      82 + 22 = 68
      62 + 82 = 100
      12 + 02 + 02 = 1

    示例 2：
    输入：n = 2
    输出：false

    https://leetcode-cn.com/problems/happy-number/solution/kuai-le-shu-by-leetcode-solution/
*/

/*
  根据我们的探索，我们猜测会有以下三种可能。
    最终会得到 11。
    最终会进入循环。
*/
// 使用hash
const getNext = function (n) {
  let totalNum = 0;
  while (n > 0) {
    let d = n % 10;
    totalNum += d * d;
    n = Math.trunc(n / 10);
  }
  return totalNum;
};

var isHappy = function (n) {
  const hashSet = new Set();
  while (n !== 1 && !hashSet.has(n)) {
    hashSet.add(n);
    n = getNext(n);
  }

  return n === 1;
};

// 快慢指针
var isHappy2 = function (n) {
  let slowRunner = n;
  let fastRunner = getNext(n);
  // 停止条件：
  //    如果 n 是一个快乐数，即没有循环，那么快跑者最终会比慢跑者先到达数字 1。
  //    如果 n 不是一个快乐的数字，那么最终快跑者和慢跑者将在同一个数字上相遇。
  while (fastRunner === 1 || fastRunner !== slowRunner) {
    fastRunner = getNext(getNext(fastRunner));
    slowRunner = getNext(slowRunner);
  }

  return fastRunner === 1;
};
