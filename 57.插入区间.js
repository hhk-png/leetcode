// 给出一个无重叠的 ，按照区间起始端点排序的区间列表。
// 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

// 输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]],
//       newInterval = [4,8]
// 输出: [[1,2],[3,10],[12,16]]

var insert = function(intervals, newInterval) {
  let res = [];
  let i = 0;
  let n = intervals.length;
  let newStart = newInterval[0];
  let newEnd = newInterval[1];

  // 不在合并的范围内
  while(i < n && newStart > intervals[i][1]) {
    res.push(intervals[i]);
    i++;
  }

  // 需要进行合并判断的区域
  while(i < n && newEnd >= intervals[i][0]) {
    newStart = Math.min(newStart, intervals[i][0]);
    newEnd = Math.max(newEnd, intervals[i][1]);
    i++;
  }
  res.push([newStart, newEnd]);

  // 最后不需要判断的区域
  while(i < n) {
    res.push(intervals[i]);
    i++;
  }

  return res;
};


