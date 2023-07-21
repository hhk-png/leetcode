// 利用84题(柱状图中最大的矩形)
var leetcode84 = function(heights) {
  let stack = [];
  stack.push(-1);

  let maxarea = 0;

  for (let i = 0; i < heights.length; ++i) {
    while (stack[stack.length-1] != -1 && heights[stack[stack.length-1]] >= heights[i])
      maxarea = Math.max(maxarea, heights[stack.pop()] * (i - stack[stack.length-1] - 1));
    stack.push(i);
  }

  while (stack[stack.length-1] != -1)
    maxarea = Math.max(maxarea, heights[stack.pop()] * (heights.length - stack[stack.length-1] -1));
  
  return maxarea;
};

var maximalRectangle = function(matrix){
  if(matrix.length === 0) return 0;
  let dp = Array(matrix[0].length).fill(0);
  let maxArea = 0;

  for(let i = 0; i < matrix.length; i++) {
    for(let j = 0; j < matrix[0].length; j++) {
      dp[j] = matrix[i][j] === '1' ? dp[j] + 1: 0;
    }
    // 每一行处理后的结果当作一个柱状图
    maxArea = MAth.max(maxArea, leetcode84(dp));
  }

  return maxArea;
};



// 动态规划 --- 有点不懂
function maximalRectangle(matrix) {
  if(matrix.length == 0) return 0;
  let m = matrix.length;
  let n = matrix[0].length;

  let left = Array(n).fill(0); // initialize left as the leftmost boundary possible
  let right = Array(n).fill(n); // initialize right as the rightmost boundary possible
  let height = Array(n).fill(0);

  let maxarea = 0;
  for(let i = 0; i < m; i++) {
    let cur_left = 0, cur_right = n;

    // 不断向上方遍历，直到遇到“0”，以此找到矩形的最大高度。
    // update height
    for(let j = 0; j < n; j++) {
      if(matrix[i][j] == '1') 
        height[j]++;
      else 
        height[j] = 0;
    }

    // 向左右两边扩展，直到无法容纳矩形最大高度。
    // update left
    for(let j = 0; j < n; j++) {
      if(matrix[i][j]=='1') {
        left[j]=Math.max(left[j],cur_left);
      } else {
        left[j]=0;
        cur_left=j+1;
      }
    }

    // update right
    for(let j = n - 1; j >= 0; j--) {
      if(matrix[i][j] == '1') {
        right[j] = Math.min(right[j], cur_right);
      } else {
        right[j] = n;
        cur_right = j;
      }
    }

    // update area
    for(let j = 0; j < n; j++) {
      maxarea = Math.max(maxarea, (right[j] - left[j]) * height[j]);
    }

  }
  return maxarea;
}