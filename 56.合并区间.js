// 给出一个区间的集合，请合并所有重叠的区间。
// 输入: [[1,3],[2,6],[8,10],[15,18]]
// 输出: [[1,6],[8,10],[15,18]]
// 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].


// shift() 方法用于把数组的第一个元素从其中删除，并返回第一个元素的值。
// 会直接修改原数组

var merge = function(intervals) {
  // 初始化
	if(!intervals || intervals.length <= 1) return intervals;
	intervals.sort((a, b) => a[0] - b[0]);
	let  res = [];
	let first = intervals.shift();
	let second = intervals.shift();


	while(second) {
		if(first[1] >= second[0]) {
      // 合并数组
			first[1] = Math.max(first[1], second[1])
		} else {
      // 插入，并选择进行下一次合并
			res.push(first);
			first = second;
    }
    // 跳入到下一个元素
		second = intervals.shift();
	}

  // 少了一次插入的循环
	res.push(first);
	return res;
};