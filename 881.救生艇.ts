// https://leetcode.cn/problems/boats-to-save-people/submissions/

function numRescueBoats(people: number[], limit: number): number {
  const n: number = people.length
  let light: number = 0
  let heavy: number = n - 1
  people.sort((a, b) => a - b)
  let res: number = 0
  while (light <= heavy) {
      if (people[light] + people[heavy] <= limit) {
          ++light
      }
      --heavy
      res++
  }
  return res
};

