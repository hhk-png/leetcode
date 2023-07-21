// https://leetcode.cn/problems/set-mismatch/submissions/

function findErrorNums(nums: number[]): number[] {
  const res: number[] = []
  let sumNums: number = 0
  let sumAll: number = 0
  const numSet: Set<number> = new Set()
  nums.forEach((val, index) => {
      sumNums += val
      sumAll += (index + 1)
      if (numSet.has(val)) {
          res.push(val)
      }
      numSet.add(val)
  })
  const temp: number = sumAll - sumNums
  res.push(temp + res[0])
  return res
};

var findErrorNums2 = function(nums) {
  const errorNums = new Array(2).fill(0);
  const n = nums.length;
  const map = new Map();
  for (const num of nums) {
      map.set(num, (map.get(num) || 0) + 1);
  }
  for (let i = 1; i <= n; i++) {
      const count = map.get(i) || 0;
      if (count === 2) {
          errorNums[0] = i;
      } else if (count === 0) {
          errorNums[1] = i;
      }
  }
  return errorNums;
};
