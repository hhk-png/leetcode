// https://leetcode.cn/problems/array-of-doubled-pairs/submissions/

function canReorderDoubled(arr: number[]): boolean {
  const count = new Map<number, number>()
  for (const val of arr) {
    const temp = count.get(val) || 0
    count.set(val, temp + 1)
  }
  if (((count.get(0) || 0)! % 2) !== 0) {
    return false
  }
  const vals = [...count.keys()]
  vals.sort((a, b) => Math.abs(a) - Math.abs(b))

  for (const val of vals) {
    const val2 = count.get(2 * val) || 0
    const valOrigin = count.get(val)!
    if (val2 < valOrigin) {
      return false
    }
    count.set(2 * val, val2 - valOrigin)
  }

  return true
};

