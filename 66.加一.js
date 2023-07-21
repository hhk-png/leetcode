// 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

// 你可以假设除了整数 0 之外，这个整数不会以零开头

// 输入: [1,2,3]
// 输出: [1,2,4]
// 解释: 输入数组表示数字 123

/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
  let len = digits.length;
  for(let i = len - 1; i >= 0; i--) {
      digits[i]++;
      // 此位置的数字为 9 时，加一得 10，模10后为0，在下一次进一；
      digits[i] %= 10;
      if(digits[i] !== 0) {
          return digits;
      }
  }
  // 全部为 9 的情况
  digits = [1,...digits];
  return digits;
};