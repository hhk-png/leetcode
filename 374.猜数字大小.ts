// https://leetcode.cn/problems/guess-number-higher-or-lower/submissions/

/** 
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * var guess = function(num) {}
 */


 var guessNumber = function(n:number) {
  let left = 1, right = n;
  while (left < right) { // 循环直至区间左右端点相同
      const mid = Math.floor(left + (right - left) / 2); 
      if (guess(mid) < 0) {
          right = mid - 1; // 答案在区间 [left, mid] 中
      } else if (guess(mid) > 0) {
          left = mid + 1; // 答案在区间 [mid+1, right] 中
      } else {
          return mid;
      }
  }
  // 此时有 left == right，区间缩为一个点，即为答案
  return left;
};
