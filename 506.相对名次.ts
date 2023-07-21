// https://leetcode.cn/problems/relative-ranks/submissions/

function findRelativeRanks(score: number[]): string[] {
  const scoreSort: number[] = score.slice().sort((a, b) => b - a)
  const map: Map<number, number> = new Map()
  const desc: string[] = ["Gold Medal", "Silver Medal", "Bronze Medal"]
  for (const [index, val] of scoreSort.entries()) {
      map.set(val, index + 1)
  }
  const res: string[] = []
  for (const s of score) {
      let tempStr: string
      const index = map.get(s)!
      tempStr = desc[index - 1] || String(index)
      // if (index === 1) {
      //     tempStr = 'Gold Medal'
      // } else if (index === 2) {
      //     tempStr = 'Silver Medal'
      // } else if (index === 3) {
      //     tempStr = 'Bronze Medal'
      // } else {
      //     tempStr = String(index)
      // }
      res.push(tempStr)
  }
  return res
};

// var findRelativeRanks2 = function(score: number[]) {
//   const n = score.length;
//   const desc = ["Gold Medal", "Silver Medal", "Bronze Medal"];
//   const arr = new Array(n).fill(0).map(() => new Array(2).fill(0));

//   for (let i = 0; i < n; ++i) {
//       arr[i][0] = score[i];
//       arr[i][1] = i;
//   }
//   arr.sort((a, b) => b[0] - a[0]);
//   const ans = new Array(n).fill(0);
//   for (let i = 0; i < n; ++i) {
//       if (i >= 3) {
//           ans[arr[i][1]] = '' + (i + 1);
//       } else {
//           ans[arr[i][1]] = desc[i];
//       }
//   }
//   return ans;
// };
