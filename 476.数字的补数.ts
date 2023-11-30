// https://leetcode.cn/problems/number-complement/

function findComplement(num: number): number {
  let highbit = 0;
  for (let i = 1; i <= 30; ++i) {
    if (num >= 1 << i) {
      highbit = i;
    } else {
      break;
    }
  }
  const mask = highbit == 30 ? 0x7fffffff : (1 << (highbit + 1)) - 1;
  return num ^ mask;
};


