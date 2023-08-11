// https://leetcode.cn/problems/di-string-match/submissions/
// 如果 s[0]=‘I’，那么令 perm[0]=0，则无论 perm[1] 为何值都满足 perm[0]<perm[1]；
// 如果 s[0]=‘D’，那么令 perm[0]=n，则无论 perm[1] 为何值都满足 perm[0]>perm[1]


function diStringMatch(s: string): number[] {
  const n: number = s.length
  let low: number = 0
  let high: number = n
  const res = new Array(n + 1).fill(0)
  for (let i = 0; i < n; i++) {
      res[i] = s[i] === 'I' ? low++ : high--
  }
  res[n] = low
  return res
};
