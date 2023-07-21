// https://leetcode.cn/problems/hand-of-straights/submissions/

function isNStraightHand(hand: number[], groupSize: number): boolean {
  const n: number = hand.length
  if (n % groupSize !== 0) {
    return false
  }
  hand.sort((a, b) => a - b)
  const count: Map<number, number> = new Map()
  hand.forEach(val => count.set(val, (count.get(val) || 0) + 1))

  for (const num of hand) {
    if (!count.has(num)) {
      continue
    }
    for (let i = 0; i < groupSize; i++) {
      const temp: number = num + i
      if (!count.has(temp)) {
        return false
      }
      count.set(temp, count.get(temp)! - 1)
      if (count.get(temp) === 0) {
        count.delete(temp)
      }
    }
  }
  return true
};

