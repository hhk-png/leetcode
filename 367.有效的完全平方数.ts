// https://leetcode.cn/problems/valid-perfect-square/

var isPerfectSquare2 = function(num: number) {
  const x = Math.floor(Math.sqrt(num));
  return x * x === num;
};

function isPerfectSquare(num: number): boolean {
  let left: number = 0;
  let right: number = num;
  
  while (left <= right) {
    const mid = left + Math.floor((right - left) / 2);
    const square = mid * mid;
    if (square < num) {
      left = mid + 1;
    } else if (square > num) {
      right = mid - 1;
    } else {
      return true;
    }
  }

  return false;
};


