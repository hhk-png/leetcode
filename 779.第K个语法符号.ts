// https://leetcode.cn/problems/k-th-symbol-in-grammar/submissions/

function kthGrammar(n: number, k: number): number {
  k--;
  let res = 0;
  while (k > 0) {
    k &= k - 1;
    res ^= 1;
  }
  return res;
};
