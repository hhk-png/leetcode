// 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

var spiralOrder = function(matrix) {
  let ans = [];
  if(matrix.length ===0) {
    return ans;
  }
  let left = 0, top = 0;
  let right = matrix[0].length-1, bottom = matrix.length-1;
  while(left<=right && top<=bottom){
    for(let r = left; r<=right; r++) ans.push(matrix[top][r]);
    for(let c = top+1; c<=bottom; c++) ans.push(matrix[c][right]);
    if(left<right && top<bottom) {
        for(let rr = right-1; rr>left; rr--) ans.push(matrix[bottom][rr]);
        for(let cc = bottom; cc>top; cc--) ans.push(matrix[cc][left])
    }
    top++;
    left++;
    bottom--;
    right--;
  }
  return ans;
};