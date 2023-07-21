var isPowerOfThree = function (n) {
  // 将n转换为三进制
  return /^10*$/.test(n.toString(3));
};

// 如果是3的幂，则一定能被三除尽
var isPowerOfThree = function (n) {
  if (n < 1) return false;
  while (n % 3 === 0) {
    n /= 3;
  }
  return n === 1;
};


// 它是安全整数范围内，3的幂次方的最大值，可以被任何3的幂次方整除
var isPowerOfThree = function(n) {
  return n > 0 && 5559060566555523 % n === 0
};
