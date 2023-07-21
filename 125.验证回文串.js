/*
  给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

  说明：本题中，我们将空字符串定义为有效的回文串。

  示例 1:
  输入: "A man, a plan, a canal: Panama"
  输出: true
  
  示例 2:
  输入: "race a car"
  输出: false

  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/valid-palindrome
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 双指针
var isPalindrome = function (s) {
  let left = 0;
  let right = s.length - 1;
  let isalnum = /[a-zA-Z0-9]/;

  while (left <= right) {
    // 屏蔽非字母和数字
    if (!isalnum.test(s[left])) {
      left++;
      continue;
    } else if (!isalnum.test(s[right])) {
      right--;
      continue;
    }

    // 进行判断
    if (s[left].toLowerCase() === s[right].toLowerCase()) {
      left++;
      right--;
    } else {
      return false;
    }
  }

  return true;
};
