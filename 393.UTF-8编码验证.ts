// https://leetcode.cn/problems/utf-8-validation/description/

const MASK1 = 1 << 7;
const MASK2 = (1 << 7) + (1 << 6);

function validUtf8(data: number[]): boolean {
  const m = data.length;
  let index = 0;
  while (index < m) {
    const num = data[index];
    const n = getFirstBytes(num);
    if (n < 0 || index + n > m) {
      return false;
    }
    // 解析后面的 n - 1 个字节，判断前两位是否是 10
    for (let i = 1; i < n; i++) {
      if (!isValid(data[index + i])) {
        return false;
      }
    }
    index += n;
  }
  return true;
};

// 解析 UTF-8 编码的第一个字节
const getFirstBytes = (num: number) => {
  // 0xxxxxxx 一个字节
  if ((num & MASK1) === 0) {
    return 1;
  }

  let n: number = 0;
  let mask = MASK1;
  while ((num & mask) !== 0) {
    n++;
    // 不能大于 4 个子节
    if (n > 4) {
      return -1;
    }
    mask >>= 1;
  }

  return n >= 2 ? n : -1;
}

const isValid = (num: number) => {
  return (num & MASK2) === MASK1;
}

