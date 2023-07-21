var romanTolet = function (s) {
  const map = new Map([
    ["I", 1],
    ["V", 5],
    ["X", 10],
    ["L", 50],
    ["C", 100],
    ["D", 500],
    ["M", 1000],
  ]);
  // 存储结果
  let sum = 0;
  // 前一个结果，用于比较
  let preNum = map.get(s[0]);
  for (let i = 1; i < s.length; i++) {
    // 当前字母
    let num = map.get(s[i]);
    if (preNum < num) { // 如果前一个数字小于后一个，则减
      sum -= preNum;
    } else { // 否则加
      sum += preNum;
    }
    preNum = num; // 替换preNum
  }

  sum += preNum; // 加上最后的结果
  return sum; // 返回
};
