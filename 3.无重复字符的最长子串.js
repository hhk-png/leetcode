/*
    给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

    示例 1:
    输入: "abcabcbb"
    输出: 3 
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
    
    示例 2:
    输入: "bbbbb"
    输出: 1
    解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
*/

// 滑动窗口，推荐使用
var lengthOfLongestSubstring = function (s) {
  // 哈希集合，记录每个字符是否出现过
  const occ = new Set();
  const n = s.length;
  // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
  let rk = -1;
  let ans = 0;
  for (let i = 0; i < n; ++i) {
    if (i != 0) {
      // 左指针向右移动一格，移除一个字符
      occ.delete(s.charAt(i - 1));
    }
    while (rk + 1 < n && !occ.has(s.charAt(rk + 1))) {
      // 不断地移动右指针
      occ.add(s.charAt(rk + 1));
      ++rk;
    }
    // 第 i 到 rk 个字符是一个极长的无重复字符子串
    ans = Math.max(ans, rk - i + 1);
  }
  return ans;
};

/* c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 哈希集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};
*/

var lengthOfLongestSubstring = function (s) {
  // num保存最长字符串的长度
  let num = 0,
    j = 0,
    t = 0;

  for (let i = 0; i < s.length; i++) {
    // 检查在截取的字符串中是否含有下一个元素，
    t = s.slice(j, i).indexOf(s[i]);
    // 如果没有，t为-1，重新计算num的值
    if (t == -1) {
      num = Math.max(num, i - j + 1);
    }
    // 如果有的话，那么就将j的值设置为重复元素的索引值+1
    else {
      // j+t就是重复元素在数组s中的索引值
      j = j + t + 1;
    }
  }
  return num;
};

var lengthOfLongestSubstring = function (s) {
  let max = 0;
  let index = 0;
  let length = s.length;
  let i = 1;
  let j = index;
  if (length === 1) {
    return 1;
  }
  while (i < length) {
    if (s[i] === s[j]) {
      index = j + 1;
      i++;
      j = index;
      max = max > i - index ? max : i - index;
      continue;
    }

    if (j + 1 !== i) {
      j++;
    } else {
      i++;
      j = index;
      max = max > i - index ? max : i - index;
    }
  }
  return max;
};
