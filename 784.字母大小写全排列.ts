// https://leetcode.cn/problems/letter-case-permutation/

function letterCasePermutation(s: string): string[] {
  const res: string[] = [];
  const dfs = (arr: string[], pos: number) => {
    while (arr[pos] && isDigit(arr[pos])) {
      pos++;
    }
    if (pos === arr.length) {
      res.push(arr.join(''));
      return;
    }

    arr[pos] = String.fromCharCode(arr[pos].charCodeAt(0) ^ (1 << 5));
    dfs(arr, pos + 1);
    arr[pos] = String.fromCharCode(arr[pos].charCodeAt(0) ^ (1 << 5));
    dfs(arr, pos + 1);
  };

  dfs([...s], 0);
  return res;
};

const isDigit = (c: string) => {
  return parseFloat(c).toString() === "NaN" ? false : true;
}
