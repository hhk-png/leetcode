// https://leetcode.cn/problems/sum-of-square-numbers/submissions/

function judgeSquareSum(c: number): boolean {
  let left: number = 0;
  let right: number = Math.floor(Math.sqrt(c));

  while (left <= right) {
    const sum = left * left + right * right;
    if (sum === c) {
      return true;
    } else if (sum > c) {
      right--;
    } else {
      left++;
    }
  }

  return false;
};

