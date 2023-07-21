// https://leetcode.cn/problems/max-chunks-to-make-sorted/submissions/

function maxChunksToSorted(arr: number[]): number {
  const stack: number[] = []
  for (const num of arr) {
    if (stack.length === 0 || num >= stack[stack.length - 1]) {
      stack.push(num)
    } else {
      const temp = stack.pop()
      while (stack.length && num < stack[stack.length - 1]) {
        stack.pop()
      }
      stack.push(temp!)
    }
  }
  return stack.length
};
