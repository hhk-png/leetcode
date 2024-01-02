// https://leetcode.cn/problems/car-pooling/submissions/

function carPooling(trips: number[][], capacity: number): boolean {
  const toMax: number = Math.max(...trips.map((val) => val[2]));
  const diff: number[] = new Array(toMax + 1).fill(0);
  for (const trip of trips) {
    const numPassenger: number = trip[0];
    diff[trip[1]] += numPassenger;
    diff[trip[2]] -= numPassenger;
  }

  let count: number = 0;
  for (let i = 0; i < toMax + 1; i++) {
    count += diff[i];
    if (count > capacity) {
      return false;
    }
  }

  return true;
}
