// https://leetcode.cn/problems/longest-harmonious-subsequence/submissions/

function findLHS(nums: number[]): number {
  const map: Map<number, number> = new Map()
  for (const num of nums) {
      map.set(num, (map.get(num) || 0) + 1)
  }
  let res: number = 0
  for (const num of map.keys()) {
      if (map.has(num + 1)) {
          res = Math.max(res, map.get(num)! + map.get(num + 1)!)
      }
  }
  return res
};
