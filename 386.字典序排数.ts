// https://leetcode.cn/problems/lexicographical-numbers/submissions/

function lexicalOrder(n: number): number[] {
  let num = 1
  const res: number[] = []
  for (let i = 0; i < n; i++) {
    res.push(num)
    if (num * 10 <= n) {
      num *= 10
    } else {
      while (num % 10 === 9 || num + 1 > n) {
        num = Math.floor(num / 10)
      }
      num++
    }
  }
  return res
};


