// https://leetcode.cn/problems/monotone-increasing-digits/submissions/
function monotoneIncreasingDigits(n: number): number {
  // 123456 388
  const nums = String(n).split('').map(Number)
  let i: number = 0;
  while (i < nums.length && nums[i] <= nums[i + 1]) {
      i++
  }
  // i 在 6 的位置
  if (i < nums.length) {
      while (i >= 0 && nums[i] > nums[i + 1]) {
          nums[i] -= 1
          i--
      }
      // i 在 5 的位置
      console.log(nums[i])
      i += 2
      // i 在 3 的位置
      //  将 6 之后的数字全部变成 9
      while (i < nums.length) {
          nums[i] = 9
          i++
      }
  }
  return parseInt(nums.join(''))
};


