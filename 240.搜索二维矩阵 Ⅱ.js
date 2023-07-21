/*
    编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

    每行的元素从左到右升序排列。
    每列的元素从上到下升序排列。

    示例:
    现有矩阵 matrix 如下：
    [
      [1,   4,  7, 11, 15],
      [2,   5,  8, 12, 19],
      [3,   6,  9, 16, 22],
      [10, 13, 14, 17, 24],
      [18, 21, 23, 26, 30]
    ]
    
    给定 target = 5，返回 true。
    给定 target = 20，返回 false。
*/
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
/*
    选左上角，往右走和往下走都增大，不能选

    选右下角，往上走和往左走都减小，不能选

    选左下角，往右走增大，往上走减小，可选

    选右上角，往下走增大，往左走减小，可选
 */
var searchMatrix = function(matrix, target) {
  if(matrix === null || matrix.length === 0) {
      return false;
  }
  let down = matrix.length - 1;
  let left = 0;

  while(left < matrix[0].length && down >= 0) {
    if(matrix[down][left] > target) {
      down--;
    } else if (matrix[down][left] < target) {
      left++;
    } else {
      return true;
    }
  }

  return false;
}

// 二分法
function binarySearch(matrix, target, start, vertical) {
  let lo = start;
  let hi = vertical ? matrix[0].length-1 : matrix.length-1;

  while(lo <= hi) {
    let mid = Math.floor((lo+hi)/2);
    if(vertical) {
      if(matrix[start][mid] < target) {
        lo = mid+1;
      } else if(matrix[start][mid] > target) {
        hi = mid-1;
      } else {
        return true;
      }
    } else {
     if(matrix[mid][start] < target) {
       lo = mid+1;
     } else if(matrix[mid][start] > target) {
       hi = mid-1;
     } else{
       return true;
     }
    }
  }

  return false;
}

var searchMatrix = function(matrix, target) {
  if(matrix.length === 0) {
    return false;
  }

  let row = matrix[0].length;
  let col = matrix.length;
  let shortLen = Math.min(row, col);

  for(let i = 0; i < shortLen; i++) {
    let verticalFound = binarySearch(matrix, target, i, true);
    let horizontalFound = binarySearch(matrix, target, i, false);
    if(verticalFound || horizontalFound) {
      return true;
    }
  }

  return false;
}

