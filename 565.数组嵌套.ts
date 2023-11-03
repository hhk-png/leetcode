// https://leetcode.cn/problems/array-nesting/submissions/

function arrayNesting(nums: number[]): number {
  let res: number = 0
  const n: number = nums.length
  const visited: boolean[] = new Array(n).fill(false)
  for (let i = 0; i < n; i++) {
      let count: number = 0
      // 不断沿着索引走，直到走到已经走过的索引
      let temp: number = i
      while (!visited[temp]) {
          visited[temp] = true
          temp = nums[temp]
          count++
      }
      res = Math.max(res, count)
  }
  return res
};

