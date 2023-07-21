function repearStr(target, n) {
  let s = target,
    total = "";
  while (n > 0) {
    if (n % 2 == 1) {
      total += s;
    }
    if (n == 1) {
      break;
    }
    s += s;
    n = n >> 1;
  }

  return total;
}

console.log(repearStr("12", 6));

// debugger
function decode(str) {
  let res = "";
  let repeatTimes = 0;
  let stack = [];
  for (let i = 0; i < str.length; i++) {
    if (parseInt(str[i])) {
      let num = parseInt(str[i]);
      repeatTimes = repeatTimes * 10 + num;
    } else if (str[i] === "[") {
      stack.push([res, repeatTimes]);
      res = "";
      repeatTimes = 0;
    } else if (str[i] === "]") {
      let tmp = stack.pop();
      res = tmp[0] + (tmp[1] === 0 ? "" : repearStr(res, tmp[1]));
    } else {
      res += str[i];
    }
  }

  return res;
}
