// https://leetcode.cn/problems/find-right-interval/

function findRightInterval(intervals: number[][]): number[] {
  const n: number = intervals.length
  const startIndex: number[][] = new Array(n).fill(0).map(() => new Array(2).fill(0))
  const endIndex: number[][] = new Array(n).fill(0).map(() => new Array(2).fill(0))
  for (let i = 0; i < n; i++) {
    startIndex[i][0] = intervals[i][0]
    startIndex[i][1] = i
    endIndex[i][0] = intervals[i][1]
    endIndex[i][1] = i
  }
  startIndex.sort((a, b) => a[0] - b[0])
  endIndex.sort((a, b) => a[0] - b[0])

  let j: number = 0
  const res: number[] = []
  for (let i = 0; i < n; i++) {
    // 将 endIndex[i] 作为锚定点，找到最接近的区间
    //  如果将 startIndex[i] 作为锚定点，并且反向遍历的话，则找的是左区间
    while (j < n && (endIndex[i][0] > startIndex[j][0])) {
      j++
    }
    if (j < n) {
      res[endIndex[i][1]] = startIndex[j][1]
    } else {
      res[endIndex[i][1]] = -1
    }
  }
  return res
};
