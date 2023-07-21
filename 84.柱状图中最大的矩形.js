// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

// 求在该柱状图中，能够勾勒出来的矩形的最大面积。

// 输入: [2,1,5,6,2,3]
// 输出: 10

// 1、
// 分治 O(nlogn) ~ O(n^2)
function calculateArea(heights, start, end) {
  if (start > end)
    return 0;
  let minindex = start;
  for (let i = start; i <= end; i++)
    if (heights[minindex] > heights[i])
      minindex = i;
  return Math.max(heights[minindex] * (end - start + 1), calculateArea(heights, start, minindex - 1), calculateArea(heights, minindex + 1, end));
}
var largestRectangleArea = function(heights) {
  return calculateArea(heights, 0, heights.length - 1)
};



// 2、
// 使用stack[stack.length-1] 替代java的stack.peek()
var largestRectangleArea = function(heights) {
  let stack = [];
  // -1为栈底
  stack.push(-1);

  let maxarea = 0;
  for (let i = 0; i < heights.length; ++i) {
    // 遇到height[i-1] >= height[i]的情况
    while (stack[stack.length-1] != -1 && heights[stack[stack.length-1]] >= heights[i])
      // 求最大值
      maxarea = Math.max(maxarea, heights[stack.pop()] * (i - stack[stack.length-1] - 1));
    // 每个数组元素都进行压栈
    stack.push(i);
  }
  // 剩下的元素
  while (stack[stack.length-1] != -1)
    maxarea = Math.max(maxarea, heights[stack.pop()] * (heights.length - stack[stack.length-1] -1));
  return maxarea;
};

/* java O(n)
    public class Solution {
      public int largestRectangleArea(int[] heights) {
          Stack < Integer > stack = new Stack < > ();
          stack.push(-1);
          int maxarea = 0;
          for (int i = 0; i < heights.length; ++i) {
              while (stack.peek() != -1 && heights[stack.peek()] >= heights[i])
                  maxarea = Math.max(maxarea, heights[stack.pop()] * (i - stack.peek() - 1));
              stack.push(i);
          }
          while (stack.peek() != -1)
              maxarea = Math.max(maxarea, heights[stack.pop()] * (heights.length - stack.peek() -1));
          return maxarea;
      }
    }
*/