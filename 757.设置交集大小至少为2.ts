// https://leetcode.cn/problems/set-intersection-size-at-least-two/submissions/

function intersectionSizeTwo(intervals: number[][]): number {
  intervals.sort((a, b) => a[1] - b[1])
  let left: number = intervals[0][1] - 1
  let right: number = intervals[0][1]
  const n: number = intervals.length
  let res: number = 2
  for (let i = 1; i < n; i++) {
    let interLeft: number = intervals[i][0]
    let interRight: number = intervals[i][1]

    if (left >= interLeft && right <= interRight) {
      continue
    } else if (right < interLeft) {
      res += 2
      left = interRight - 1
      right = interRight
    } else if (left < interLeft) {
      res++
      if (right === interRight) {
        left = right - 1
      } else {
        left = right
        right = interRight
      }
    }
  }
  return res
};