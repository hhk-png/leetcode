// https://leetcode.cn/problems/reorder-data-in-log-files/

// 字母日志放在数字日志的前面
// 数字日志保持相对位置
// 字母日志内容不相同时，按内容排序，
//  内容相同时，按标识排序

var reorderLogFiles = function(logs: string[]) {
  const arr: [string, number][] = logs.map((val, index) => [val, index])
  arr.sort((a, b) => logCompare(a, b));
  const reordered = arr.map(val => val[0])
  return reordered
}

const logCompare = (log1: [string, number], log2: [string, number]) => {
  // 拆分成[log, log number]
  const split1 = split(log1[0])
  const split2 = split(log2[0])
  const isDigit1 = isDigit(split1[1][0])
  const isDigit2 = isDigit(split2[1][0])
  // 都是数字
  if (isDigit1 && isDigit2) {
      return log1[1] - log2[1];
  }
  // 都不是数字，都是字母
  if (!isDigit1 && !isDigit2) {
      const res = compareTo(split1[1], split2[1]);
      if (res !== 0) {
          return res;
      }
      // 内容相同，按标识符排序
      return compareTo(split1[0], split2[0]);
  }
  // 字母放在数字的前面
  return isDigit1 ? 1 : -1;
};

const split = (str: string) => {
  const spaceIndex = str.indexOf(' ')
  return [
      str.slice(0, spaceIndex), 
      str.slice(spaceIndex + 1)
  ]
}

const isDigit = (ch: string) => {
  return ch <= "9" && ch >= "0";
}

const compareTo = (left: string, right: string) => {
  for (let i = 0; i < Math.min(left.length, right.length); i++) {
      if (left[i].charCodeAt(0) < right[i].charCodeAt(0)) {
          return -1;
      }
      if (left[i].charCodeAt(0) > right[i].charCodeAt(0)) {
          return 1;
      }
  }
  // 到了这里，已经比较过的字符串全部相等
  if (left.length === right.length) {
      return 0;
  }
  if (left.length > right.length) {
      return 1;
  }
  return -1;
}




