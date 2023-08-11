// https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/description/

function minAddToMakeValid(s: string): number {
  // 括号添加的数量与最终是否合法无关
  let res: number = 0
  let leftCount: number = 0
  for (const c of s) {
      if (c === '(') {
          leftCount++
      } else {
          if (leftCount > 0) {
              leftCount--
          } else {
              res++
          }
      }
  }
  res += leftCount
  return res
};