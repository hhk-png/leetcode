// https://leetcode.cn/problems/similar-string-groups/

function numSimilarGroups(strs: string[]): number {
  const n: number = strs.length;
  const m: number = strs[0].length;
  const f: number[] = new Array(n).fill(0).map((element, index) => index);

  const find = (x: number): number => {
    return f[x] === x ? x : (f[x] = find(f[x]));
  }

  // 检测是否是相似字符串
  const check = (a: string, b: string): boolean => {
    let num: number = 0;
    for (let i = 0; i < a.length; i++) {
      if (a[i] !== b[i]) {
        num++;
        if (num > 2) {
          return false;
        }
      }
    }
    return true;
  }

  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n;j++) {
      const findI: number = find(i);
      const findJ: number = find(j);
      if (findI === findJ) {
        continue;
      }
      if (check(strs[i], strs[j])) {
        f[findI] = findJ;
      }
    }
  }

  let ret: number = 0;
  for (let i = 0; i < n; i++) {
    if (f[i] === i) {
      ret++;
    }
  }
  return ret;
};

