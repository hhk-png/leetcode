// https://leetcode.cn/problems/bitwise-and-of-numbers-range/solutions/384938/shu-zi-fan-wei-an-wei-yu-by-leetcode-solution/

function rangeBitwiseAnd(left: number, right: number): number {
  let shift = 0;
  // 找到公共前缀
  while (left < right) {
    left >>= 1;
    right >>= 1;
    ++shift;
  }
  return left << shift;
};

var rangeBitwiseAnd2 = function(m: number, n: number) {
  while (m < n) {
      // 抹去最右边的 1
      n = n & (n - 1);
  }
  return n;
};


