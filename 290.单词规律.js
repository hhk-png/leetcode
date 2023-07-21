/*

  给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。

  这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。

   
  示例1:
    输入: pattern = "abba", s = "dog cat cat dog"
    输出: true

  示例 2:
    输入:pattern = "abba", s = "dog cat cat fish"
    输出: false

  示例 3:
    输入: pattern = "aaaa", s = "dog cat cat dog"
    输出: false

*/
var wordPattern = function (pattern, s) {
  // 建立双向的哈希表
  const word2ch = new Map();
  const ch2word = new Map();
  // 拆分成单词
  const words = s.split(" ");
  if (pattern.length !== words.length) {
    return false;
  }
  // 迭代
  for (const [i, word] of words.entries()) {
    const ch = pattern[i];
    // map 中的值不对等的时候，返回false
    if (
      (word2ch.has(word) && word2ch.get(word) != ch) ||
      (ch2word.has(ch) && ch2word.get(ch) !== word)
    ) {
      return false;
    }
    // set value
    word2ch.set(word, ch);
    ch2word.set(ch, word);
  }
  return true;
};
