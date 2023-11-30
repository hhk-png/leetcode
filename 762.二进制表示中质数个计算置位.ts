// https://leetcode.cn/problems/prime-number-of-set-bits-in-binary-representation/

function countPrimeSetBits(left: number, right: number): number {
  let res: number = 0;
  for (let i = left; i <= right; i++) {
    if (isPrime(bitCount(i))) {
      res++;
    }
  }
  return res;
  /**
    let ans = 0;
    for (let x = left; x <= right; ++x) {
      if (((1 << bitCount(x)) & 665772) != 0) {
        ++ans;
      }
    }
    return ans;
  */
};

const bitCount = (num: number): number => {
  return num.toString(2).split('0').join('').length;
}

const isPrime = (num: number): boolean => {
  if (num < 2) {
    return false;
  }
  for (let i = 2; i * i <= num; ++i) {
    if (num % i === 0) {
      return false;
    }
  }
  return true;
}

