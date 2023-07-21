/*
    给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

    说明：
    拆分时可以重复使用字典中的单词。
    你可以假设字典中没有重复的单词。

    示例 1：
    输入: s = "leetcode", wordDict = ["leet", "code"]
    输出: true
    解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。

    示例 2：
    输入: s = "applepenapple", wordDict = ["apple", "pen"]
    输出: true
    解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
         注意你可以重复使用字典中的单词。

    示例 3：
    输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
    输出: false
*/

/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {boolean}
 */

// 动态规划
var wordBreak = function(s, wordDict) {
  let word = new Set(wordDict);

  // 记录的是 [0,i]
  let dp = Array(s.length+1).fill(false);
  dp[0] = true;

  // [i, s.length];
  // i 是标志
  for (let i = 1; i <= s.length; i++) {
    for (let j = 0; j < i; j++) {
      if (dp[j] && word.has(s.slice(j, i))) {
        dp[i] = true;
        break;
      }
    }
  }
  return dp[s.length];
};


// 超时
var wordBreak = function(s, wordDict) {

  let word = new Set(wordDict);

  let boo = Array(s.length).fill(false);

  return word_Break(s, word, 0, boo);
};

function word_Break(s, word, start, boo) {
  if(start === s.length) {
    return true;
  }
  // 
  if(boo[start]) {
    return boo[start];
  }
  for(let end = start+1; end <= s.length; end++) {
    if(word.has(s.slice(start,end)) && word_Break(s, word, end, boo)){
      return boo[start] = true;
    }
  }
  return boo[start] = false;
}

