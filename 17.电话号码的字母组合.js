// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

// C:/Users/郝洪坤/Desktop/素材/图片/17_telephone_keypad.png
// 输入："23"
// 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

// 在全局中定义输出数组，使局部作用域中能够访问的到，在低版本浏览器中可能不适用
let output = [];
let phone = {
  2: 'abc',
  3: 'def',
  4: 'ghi',
  5: 'jkl',
  6: 'mno',
  7: 'pqrs',
  8: 'tuv',
  9: 'wxyz',
};
// 递归函数
function backtrack (combination, next_digits) {
  if(next_digits.length === 0) {
    output.push(combination);
  } else {
    // 获取下一个数字
    let next_number = next_digits.substr(0, 1);
    // 数字对应的字符串
    let next_string = phone[next_number];

    for(let i=0; i< next_string.length; i++) {
      // 截取对应的字符串
      let letter = next_string.substr(i, 1);
      // 递归
      backtrack(combination + letter, next_digits.substr(1));
    }
  }
}
var letterCombinations = function(digits) {
  // 空字符串时候的情况
  if(digits.length === 0) return [];
  if (digits.length !== 0)
    backtrack('', digits);
  return output;
};