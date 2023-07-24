// https://leetcode.cn/problems/can-place-flowers/submissions/

function canPlaceFlowers(flowerbed: number[], n: number): boolean {
  const m: number = flowerbed.length
  let count: number = 0
  let prev = -1
  for (let i = 0; i < m; i++) {
      if (flowerbed[i] === 0) {
          continue
      }

      if (prev === -1) {
          count += Math.floor(i / 2)
      } else {
          count += Math.floor((i - prev - 2) / 2)
      }
      prev = i

  }
  if (prev === - 1) {
      count += (m + 1) / 2
  } else {
      count += (m - prev - 1) / 2
  }
  return count >= n
};
