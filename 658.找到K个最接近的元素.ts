// https://leetcode.cn/problems/find-k-closest-elements/submissions/

// var findClosestElements = function(arr, k, x) {
//   const list = [...arr];
//   list.sort((a, b) => {
//       if (Math.abs(a - x) !== Math.abs(b - x)) {
//           return Math.abs(a - x) - Math.abs(b - x);
//       } else {
//           return a - b;
//       }
//   });
//   const ans = list.slice(0, k);
//   ans.sort((a, b) => a - b);
//   return ans;
// };



function findClosestElements(arr: number[], k: number, x: number): number[] {
  let right: number = binarySearch(arr, x)
  let left: number = right - 1
  while (k-- > 0) {
    if (left < 0) {
      right++;
    } else if (right >= arr.length) {
      left--;
    } else if (x - arr[left] <= arr[right] - x) {
      left--;
    } else {
      right++;
    }
  }
  // const ans: number[] = [];
  // for (let i = left + 1; i < right; i++) {
  //   ans.push(arr[i]);
  // }
  return arr.slice(left + 1, right);
};

const binarySearch = (arr: number[], target: number) => {
  let left: number = 0
  let right: number = arr.length - 1
  while (left < right) {
    const mid = left + Math.floor((right - left) / 2)
    if (arr[mid] > target) {
      right = mid
    } else {
      left = mid + 1
    }
  }
  return left
}
