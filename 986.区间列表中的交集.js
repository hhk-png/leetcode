/*
  给定两个由一些 闭区间 组成的列表，每个区间列表都是成对不相交的，并且已经排序。

  返回这两个区间列表的交集。

  （形式上，闭区间 [a, b]（其中 a <= b）表示实数 x 的集合，而 a <= x <= b。两个闭区间的交集是一组实数，要么为空集，要么为闭区间。例如，[1, 3] 和 [2, 4] 的交集为 [2, 3]。）


  C:/Users/郝洪坤/Desktop/素材/图片/interval1.png
  输入：A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
  输出：[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
*/

var intervalIntersection = function(A, B) {
  // 存放结果数据的数组
  const ans = [];
  // 控制两个数组的指针
  let i = 0,
      j = 0;

  // 以一方指针到达尽头后退出循环
  while(i < A.length && j < B.length) {
    // Let's check if A[i] intersects B[j].
    // lo - the startpoint of the intersection
    // hi - the endpoint of the intersection
    let lo = Math.max(A[i][0], B[j][0]);
    let hi = Math.min(A[i][1], B[j][1])

    // 添加结果，[i, i]也算
    if (lo <= hi) 
      ans.push([lo, hi]);
    
    // Remove the interval with the smallest endpoint
    if (A[i][1] < B[j][1]) {
      i++;
    } else {
      j++;
    }
  }

  return ans;

}

