// https://leetcode.cn/problems/third-maximum-number/submissions/
var thirdMax = function (nums: number[]) {
  let a = -Number.MAX_VALUE, b = -Number.MAX_VALUE, c = -Number.MAX_VALUE;
  for (const num of nums) {
    if (num > a) {
      c = b;
      b = a;
      a = num;
    } else if (a > num && num > b) {
      c = b;
      b = num;
    } else if (b > num && num > c) {
      c = num;
    }
  }
  return c === -Number.MAX_VALUE ? a : c;
};
