// https://leetcode.cn/problems/minimum-area-rectangle/submissions/

// 没通过，不知道什么原因
// function minAreaRect(points: number[][]): number {
//   const rows: Map<number, number[]> = new Map()
//   for (const [x, y] of points) {
//     if (!rows.has(x)) {
//       rows.set(x, [])
//     }
//     rows.get(x)?.push(y)
//   }
//   let res: number = Number.MAX_VALUE
//   const lastX: Map<number, number> = new Map()
//   for (const [x, row] of rows.entries()) {
//     row.sort((a, b) => a - b)
//     for (let i = 0; i < row.length; i++) {
//       for (let j = i + 1; j < row.length; j++) {
//         const y1 = row[i]
//         const y2 = row[j]
//         const code = 40001 * y1 + y2
//         if (lastX.has(code)) {
//           res = Math.min(res, Math.abs((x - lastX.get(code)!) * (y2 - y1)))
//         }
//         lastX.set(code, x)
//       }
//     }

//   }
//   return Number.MAX_VALUE === res ? 0 : res;
// };



function minAreaRect(points: number[][]): number {
  const pointSet: Set<number> = new Set(points.map(p => hash(p[0], p[1])))

  let res: number = Number.MAX_VALUE
  for (let i = 0; i < points.length; i++) {
    for (let j = i + 1; j < points.length; j++) {
      // 两点在对角线上
      //  有对应的另一条对角线
      if (
        points[i][0] !== points[j][0] && points[i][1] !== points[j][1]
        && pointSet.has(hash(points[i][0], points[j][1])) && pointSet.has(hash(points[j][0], points[i][1]))
      ) {
        res = Math.min(res, Math.abs(points[j][0] - points[i][0]) * Math.abs(points[j][1] - points[i][1]))
      }
    }
  }

  return Number.isFinite(res) ? res : 0;
};

const hash = (a: number, b: number) => {
  return 40001 * a + b
}






