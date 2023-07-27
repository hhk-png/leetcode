// https://leetcode.cn/problems/valid-palindrome-ii/submissions/
const isPalindrome = (str: string, left: number, right: number) => {
  while (left < right) {
      if (str[left] !== str[right]) {
          return false
      }
      left++
      right--
  }
  return true
}
function validPalindrome(str: string): boolean {
  let left: number = 0
  let right: number = str.length - 1
  while (left < right) {
      if (str[left] === str[right]) {
          left++
          right--
      } else {
          return isPalindrome(str, left, right - 1) || isPalindrome(str, left + 1, right)
      }
  }
  return true
};
