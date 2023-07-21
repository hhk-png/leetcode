// https://leetcode.cn/problems/k-th-smallest-prime-fraction/

function kthSmallestPrimeFraction(arr: number[], k: number): number[] {
  const n: number = arr.length
  let left: number = 0.0
  let right: number = 1.0
  while (true) {
    const mid = (left + right) / 2
    let count: number = 0
    let x: number = 0
    let y: number = 1
    for (let i = 1; i < n; i++) {
      let j = -1
      while (arr[j + 1] / arr[i] < mid) {
        if (arr[j] * y > arr[i] * x) {
          x = arr[j]
          y = arr[i]
        }
        j++
      }
      count += j + 1
    }

    if (count === k) {
      return [x, y]
    }

    if (count < k) {
      left = mid
    } else {
      right = mid
    }
  }
};
