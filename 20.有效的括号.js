// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 注意空字符串可被认为是有效字符串。

// 示例 2:
// 输入: "()[]{}"
// 输出: true

// 示例 3:
// 输入: "(]"
// 输出: false

// 示例 5:
// 输入: "{[]}"
// 输出: true



// 1.不使用对象
var isValid = function(s) {
  // 空字符串
  if(s.length === 0) return true;
  // 长度为计数一定不匹配
  if(s.length%2 === 1) return false;

  // 充当栈的作用
  let arr = [];
  for(let i=0; i<s.length; i++) {
    let c = s[i];
    if(c === '(')
      arr.push(')');
    else if (c === '[') 
      arr.push(']');
    else if (c === '{') 
      arr.push('}');
    else if (arr.length === 0 || c !== arr.pop()) // 字符串还没有遍历结束，栈已空，则不匹配
      return false; // 栈不空的时候才进行下一步判断
  }

  return arr.length === 0;
};



// 2.使用对象
let allBracket = {
  '(':')',
  '[':']',
  '{':'}',
};
var isValid = function(s) {
  if(s.length === 0) return true;
  if(s.length%2 === 1) return false;
  let arr = [];
  for(let i=0; i<s.length; i++) {
    let c = s[i];
    if(allBracket[c]) 
      arr.push(c);
    else if (arr.length === 0 || allBracket[arr.pop()] !== c)
      return false;
  }
  return arr.length === 0;
}

// 两种解法思想相同