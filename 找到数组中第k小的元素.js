function exchange(a, i, j) {
  let temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}
function partition(a, lo, hi) { // 快速排序的切分
  let i = lo, j = hi + 1;
  let val = a[lo];

  while (true) {
    // a[...i] < val < a[j...]
    while (a[++i] < val);
    // if (i === hi) break; // 可以省略
    while (val < a[--j]);
    // if (j === lo) break; // 可以省略
    if (i >= j) break;
    exchange(a, i, j);
  }
  exchange(a, lo, j);
  return j;
}
// 找到数组中第k小的元素
function select(a, k) {
  // debugger
  let lo = 0, hi = a.length - 1;
  while (hi > lo) {
    let j = partition(a, lo, hi);
    if (j == k) return a[k];
    else if (j > k)
      hi = j - 1;
    else if (j < k)
      lo = j + 1;
  }
  return a[k];
}