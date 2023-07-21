/*
    给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

    具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

    
    示例 1：
    输入："abc"
    输出：3
    解释：三个回文子串: "a", "b", "c"

    示例 2：
    输入："aaa"
    输出：6
    解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
*/

/**
 * @param {string} s
 * @return {number}
 */
var countSubstrings = function(s) {
  // 字符串长度
  let len = s.length,
    // 回文子串数量
    ans = 0;
  // 中心：字母，或两个字母中间。
  // (2*len - 1) 个中心
  for (let center = 0; center < 2*len - 1; center++) {
    // 这种方式可以实现每次移动0.5的距离
    let left = Math.trunc(center / 2);
    let right = left + center % 2;

    // 从中间逐步向两端扩展
    // 如果 left 和 right 位置字符串相等，则说明是回文字符串
    while (left >= 0 
        && right < len 
        && s.charAt(left) === s.charAt(right)) {
      left--;
      right++;
      ans++;
    }
  }
  return ans;
};