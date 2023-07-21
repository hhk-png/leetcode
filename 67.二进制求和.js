// 给定两个二进制字符串，返回他们的和（用二进制表示）。

// 输入为非空字符串且只包含数字 1 和 0。

// 示例1:
// 输入: a = "11", b = "1"
// 输出: "100"

// 示例2:
// 输入: a = "1010", b = "1011"
// 输出: "10101"

var addBinary = function(a, b) {
  let n = a.length; let m = b.length;
  // 1.同时处理n>m 和m>n两种情况，要加return
  if(n < m) return addBinary(b, a); // ！！！
  let L = n;

  // 2.初始化
  // 进位
  let carry = 0;
  // 存放结果的字符串
  let res = '';
  let j = m-1;
  for(let i = L-1; i > -1; i--) {
    // 3.如果最后一位为一，就放在carry的计算并且进位
    if(a[i] === '1') carry++;
    if(j > -1 && b[j--] === '1') carry++;

    // 4.进位判断
    if(carry % 2 === 1) {
        res = '1' + res;
    } else {
        res = '0' + res;
    }
    // 5.二进制右移一位，js可以保留小数，需要向下取整
    carry = Math.floor(carry/2);
  }

  // 6.最后的处理
  if(carry === 1) {
    res = '1' + res;
  }

  // 7.
  return res;

};