// 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

// candidates 中的数字可以无限制重复被选取。

// 输入: candidates = [2,3,6,7], target = 7,
// 所求解集为:
// [
//   [7],
//   [2,2,3]
// ]

var combinationSum = function (candidates, target) {
  // 由大到小排序
  candidates.sort((a, b) => b - a);

  let res = [], path = [];
  let len = candidates.length,
      minNum = candidates[len - 1]; // 缓存长度

  get_combine(target, 0, path);

  return res;
};
// main
// candidates: 数组对象
// target: 目标值，随着递归的深入不断改变
// start: 开始查找的位置
// path: 递归路线，也就是每一个可能值
function get_combine(target, start, path) {
  if (target == 0) {
    return res.push(path.slice());
  }

  // 这里不用小于 0，小于最小的数就可以返回了
  if (target < minNum) return;

  for (let i = start; i < len; i++) {
    path.push(candidates[i]);
    get_combine(target - candidates[i], i, path);
    path.pop();
  }
}