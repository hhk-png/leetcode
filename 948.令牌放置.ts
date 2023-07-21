// https://leetcode.cn/problems/bag-of-tokens/

function bagOfTokensScore(tokens: number[], power: number): number {
  const n: number = tokens.length
  let low: number = 0
  let high: number = tokens.length - 1
  let res: number = 0
  let points: number = 0
  tokens.sort((a, b) => a - b)
  while (low <= high && (power >= tokens[low] || points >= 1)) {
    while (low <= high && power >= tokens[low]) {
      points++
      power -= tokens[low]
      low++
    }
    res = Math.max(res, points)
    if (low <= high && points >= 1) {
      points--
      power += tokens[high]
      high--
    }
  }
  return res
};
