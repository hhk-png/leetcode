/*
    给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

    你的算法时间复杂度必须是 O(log n) 级别。

    如果数组中不存在目标值，返回 [-1, -1]。

    示例 1:
    输入: nums = [5,7,7,8,8,10], target = 8
    输出: [3,4]

    示例 2:
    输入: nums = [5,7,7,8,8,10], target = 6
    输出: [-1,-1]
*/
// 二分查找函数
function extremeInsertionIndex (nums, target, isLeft) {
  let left = 0;
  let right = nums.length;

  while (left < right) {
      let mid = Math.floor(left + (right - left) / 2);
      // 通过isLeft判断是在左部分还是在右部分查找
      if(nums[mid] > target || (isLeft && nums[mid] === target)) {
          right = mid;
      } else {
          left = mid + 1;
      }
  }

  return left;
}

var searchRange = function(nums, target) {
  let indexArr = [-1, -1];
  let leftIndex = extremeInsertionIndex(nums, target, true);

  // 出现越界或者没有target的情况
  if(leftIndex >= nums.length || nums[leftIndex] !== target) {
      return indexArr;
  }

  indexArr[0] = leftIndex;
  // 再次查找，向右找到右边界
  indexArr[1] = extremeInsertionIndex(nums, target, false) -1;

  // 返回数组
  return indexArr;
};