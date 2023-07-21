// https://leetcode.cn/problems/fair-candy-swap/

function fairCandySwap(aliceSizes: number[], bobSizes: number[]): number[] {
  const sumAlice: number = aliceSizes.reduce((acc, val) => acc + val, 0)
  const sumBob: number = bobSizes.reduce((acc, val) => acc + val, 0)
  const delta: number = Math.floor((sumAlice - sumBob) / 2)
  const hash = new Set(aliceSizes)
  let res = [0, 0]

  for (const b of bobSizes) {
    const x = b + delta
    if (hash.has(x)) {
      res = [x, b]
      break
    }
  }

  return res
};

