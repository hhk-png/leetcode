/*
    给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

    示例 1:
    输入: s = "anagram", t = "nagaram"
    输出: true

    示例 2:
    输入: s = "rat", t = "car"
    输出: false
*/

var isAnagram = function (s, t) {
  if (s.length !== t.length) return false;
  const hash = new Array(26).fill(0);
  for (const value of s) {
    hash[value.charCodeAt() - 97]++;
  }

  for (const value of t) {
    const resValue = value.charCodeAt() - 97;
    hash[resValue]--;
    if (hash[resValue] < 0) {
      return false;
    }
  }

  return true;
};
