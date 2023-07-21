// https://leetcode.cn/problems/friends-of-appropriate-ages/

function numFriendRequests2(ages: number[]): number {
  const n: number = ages.length
  ages.sort((a, b) => a - b)
  let left: number = 0
  let right: number = 0
  let res: number = 0
  for (const age of ages) {
    if (age < 15) {
      continue
    }

    while (ages[left] <= 0.5 * age + 7) {
      left++
    }

    while (right + 1 < n && ages[right + 1] <= age) {
      right++
    }

    res += right - left
  }

  return res
};

function numFriendRequests(ages: number[]): number {
  const cnt = new Array(121).fill(0)
  for (const age of ages) {
    cnt[age]++
  }

  const pre = new Array(121).fill(0)
  for (let i = 1; i < 121; i++) {
    pre[i] = pre[i - 1] + cnt[i]
  }
  let res: number = 0
  for (let i = 15; i < 121; i++) {
    const bound = Math.floor(0.5 * i + 8)
    res += cnt[i] * (pre[i] - pre[bound - 1] - 1)
  }

  return res
};

