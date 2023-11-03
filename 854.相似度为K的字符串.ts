// https://leetcode.cn/problems/k-similar-strings/submissions/

var kSimilarity = function(s1: string, s2: string) {
  let str1 = '';
  let str2 = '';
  for (let i = 0; i < s1.length; i++) {
      if (s1[i] !== s2[i]) {
          str1 += s1[i];
          str2 += s2[i];
      }
  }
  const n = str1.length;
  if (n === 0) {
      return 0;
  }
  const smallCycles: number[] = [];
  const largeCycles: number[] = [];
  for (let i = 1; i < (1 << n); i++) {
      const cnt = new Array(6).fill(0);
      for (let j = 0; j < n; j++) {
          if ((i & (1 << j)) !== 0) {
              cnt[str1[j].charCodeAt(0) - 'a'.charCodeAt(0)]++;
              cnt[str2[j].charCodeAt(0) - 'a'.charCodeAt(0)]--;
          }
      }
      let isCycle = true;
      for (let j = 0; j < 6; j++) {
          if (cnt[j] !== 0) {
              isCycle = false;
              break;
          }
      }
      if (isCycle) {
          const size = bitCount(i);
          if (size <= 6) {
              smallCycles.push(i);
          } else {
              largeCycles.push(i);
          }
      }
  }
  smallCycles.sort((a, b) => bitCount(a) - bitCount(b));
  largeCycles.sort((a, b) => bitCount(a) - bitCount(b));
  const dp = new Array(1 << n).fill(1);
  dp[0] = 0;
  for (let i = 0; i < smallCycles.length; i++) {
      for (let j = 0; j < i; j++) {
          const x = smallCycles[i], y = smallCycles[j];
          if ((x & y) === y) {
              dp[x] = Math.max(dp[x], dp[y] + dp[x ^ y]);
          }
      }
  }
  for (const x of largeCycles) {
      for (const y of smallCycles) {
          if ((x & y) === y) {
              dp[x] = Math.max(dp[x], dp[y] + dp[x ^ y]);
          }
      }
  }
  return n - dp[(1 << n) - 1];
}

const bitCount = (num: number) => {
  return num.toString(2).split('0').join('').length;
}
