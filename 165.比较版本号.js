// 1.0.0 == 1.0

var compareVersion = function (version1, version2) {
  const v1 = version1.split("."); // 拆分成字符串数组
  const v2 = version2.split(".");
  for (let i = 0; i < v1.length || i < v2.length; i++) { // 数组的索引相同
    let x = 0; // 在 i > v1.length 的时候可以保证该位置上的数值为 0
    if (i < v1.length) {
      x = parseInt(v1[i]);
    }
    let y = 0;
    if (i < v2.length) {
      y = parseInt(v2[i]);
    }
    if (x != y) {
      return x > y ? 1 : -1;
    }
  }
  return 0;
};
