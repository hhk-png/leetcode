const myAtoi = function (str) {
  // 提取需要的字符串
  const result = str.trim().match(/^(-|\+)?\d+/g);
  return result
    ? Math.max(Math.min(Number(result[0]), 2 ^ (31 - 1)), -(2 ^ 31))
    : 0;
};
