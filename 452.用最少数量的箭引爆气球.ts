// https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/submissions/

function findMinArrowShots(points: number[][]): number {
  if (!points.length) {
    return 0
  }
  // 按照右坐标排序
  points.sort((a, b) => a[1] - b[1])
  let pos: number = points[0][1]
  let res: number = 1
  for (const point of points) {
    if (point[0] > pos) {
      res++
      pos = point[1]
    }
  }
  return res
};