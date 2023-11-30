// https://leetcode.cn/problems/stickers-to-spell-word/description/

function minStickers(stickers: string, target: string): number {
  const m = target.length;
  const memo = new Array(1 << m).fill(-1);
  memo[0] = 0;

  const dfs = (mask: number) => {
    if (memo[mask] < 0) {
      let res = m + 1;
      for (const sticker of stickers) {

        const cnt = new Array(26).fill(0);
        for (let i = 0; i < sticker.length; i++) {
          cnt[sticker[i].charCodeAt(0) - 'a'.charCodeAt(0)]++;
        }

        let left = mask;
        for (let i = 0; i < target.length; i++) {
          const c = target[i];
          if (((mask >> i) & 1) && cnt[c.charCodeAt(0) - 'a'.charCodeAt(0)] > 0) {
            cnt[c.charCodeAt(0) - 'a'.charCodeAt(0)]--;
            left ^= (1 << i);
          }
        }

        if (left < mask) {
          res = Math.min(res, dfs(left) + 1);
        }
      }
      memo[mask] = res;
    }
    return memo[mask];
  };

  const res = dfs((1 << m) - 1);
  return res <= m ? res : -1;
};


