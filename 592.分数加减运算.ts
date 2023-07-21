// https://leetcode.cn/problems/fraction-addition-and-subtraction/submissions/

function fractionAddition(expression: string): string {
  let x = 0, y = 1; // 分子，分母
  let index = 0, n = expression.length;
  while (index < n) {
    // 读取分子
    let x1 = 0, sign = 1;
    if (expression[index] === '-' || expression[index] === '+') {
      sign = expression[index] === '-' ? -1 : 1;
      index++;
    }
    while (index < n && isDigit(expression[index])) {
      x1 = x1 * 10 + expression[index].charCodeAt(0) - '0'.charCodeAt(0);
      index++;
    }
    x1 = sign * x1;
    index++;

    // 读取分母
    let y1 = 0;
    while (index < n && isDigit(expression[index])) {
      y1 = y1 * 10 + expression[index].charCodeAt(0) - '0'.charCodeAt(0);
      index++;
    }

    x = x * y1 + x1 * y;
    y *= y1;
  }
  if (x === 0) {
    return "0/1";
  }
  const g = gcd(Math.abs(x), y); // 获取最大公约数
  return Math.floor(x / g) + "/" + Math.floor(y / g);
}

const gcd = (a: number, b: number) => {
  let remainder = a % b;
  while (remainder !== 0) {
    a = b;
    b = remainder;
    remainder = a % b;
  }
  return b;
};

const isDigit = (ch: string) => {
  return parseFloat(ch).toString() === "NaN" ? false : true;
}
