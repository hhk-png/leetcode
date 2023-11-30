function hasAlternatingBits(n: number): boolean {
  let prev = 2;
  while (n !== 0) {
    const curr = n % 2;
    if (curr === prev) {
      return false;
    }
    prev = curr;
    n = Math.floor(n / 2);
  }
  return true;

  // const a = n ^ (n >> 1);
  // return (a & (a + 1)) === 0;

};