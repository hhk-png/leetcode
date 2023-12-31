// 给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。

// 如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。

// 如果不存在最后一个单词，请返回 0 。

// 说明：一个单词是指仅由字母组成、不包含任何空格的 最大子字符串。

// 输入: "Hello World"
// 输出: 5


var lengthOfLastWord = function(s) {
  let end = s.length - 1;
  // 忽略字符串后面的空格
  while(end >= 0 && s[end] === ' ') {
    end--;
  }
  // 单空格
  if(end < 0) return 0;
  
  // 记录单词的长度
  let start = end;
  while(start >= 0 && s[start] !== ' ') {
    start--;
  }

  return end - start;
};