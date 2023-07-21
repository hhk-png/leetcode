var countPrimes = function (n) {
  const isPrime = new Array(n).fill(1);
  let ans = 0;
  for (let i = 2; i < n; ++i) {
    if (isPrime[i]) {
      ans += 1;
      // 如果x为质数，那么2x, 3x ... 一定不是质数
      for (let j = i * i; j < n; j += i) {
        isPrime[j] = 0;
      }
    }
  }
  return ans;
};
