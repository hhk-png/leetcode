// https://leetcode.cn/problems/maximum-swap/submissions/

const swap = (charArray: string[], i: number, j: number) => {
  const temp = charArray[i];
  charArray[i] = charArray[j];
  charArray[j] = temp;
};

function maximumSwap(num: number): number {
  const arr: string[] = (num + '').split('')
  const n: number = arr.length
  let maxId: number = n - 1
  let index1: number = -1
  let index2: number = -1
  for (let i = n - 1; i >= 0; i--) {
      if (arr[i] > arr[maxId]) {
          maxId = i
      } else if (arr[i] < arr[maxId]) {
          index1 = i
          index2 = maxId
      }
  }
  if (index1 >= 0) {
      swap(arr, index1, index2)
      return parseInt(arr.join(''))
  }
  return num
};

