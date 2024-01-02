// https://leetcode.cn/problems/next-greater-element-i/submissions/

function nextGreaterElement(nums1: number[], nums2: number[]): number[] {
  const stack: number[] = [];
  const map = new Map<number, number>();
  for (let i = nums2.length - 1; i >= 0; i--) {
    const num: number = nums2[i];
    while (stack.length && stack[stack.length - 1] <= num) {
      stack.pop();
    }
    map.set(num, stack.length ? stack[stack.length - 1] : -1);
    stack.push(num);
  }
  const res: number[] = nums1.map(val => map.get(val)!);
  return res;
};
