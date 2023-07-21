/*
    给你一个整数数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。

    你可以假设所有输入数组都可以得到满足题目要求的结果。

     

    示例 1：
      输入：nums = [1,5,1,1,6,4]
      输出：[1,6,1,5,1,4]
      解释：[1,4,1,5,1,6] 同样是符合题目要求的结果，可以被判题程序接受。

    示例 2：
      输入：nums = [1,3,2,2,3,1]
      输出：[2,3,1,3,1,2]
*/

// 没怎么看懂，运行速度也慢
// 快速选择 + 3-way-partition
var wiggleSort = function (nums) {
  let len = nums.length;
  let len2 = Math.trunc(len / 2);
  // 将中位数移到中间
  quickSelect(nums, 0, len, len2);
  // 获取中位数
  let mid = nums[len2];

  // 以中位数为分界点，分割数组
  let left = 0;
  let right = nums.length - 1;
  let move = 0;
  while (move < right) {
    if (nums[move] > mid) {
      swap(nums, move, right);
      right--;
    } else if (nums[move] < mid) {
      swap(nums, left++, move++);
    } else {
      move++;
    }
  }

  if (len % 2 === 1) len2++;
  const tmp1 = nums.slice(0, len2);
  const tmp2 = nums.slice(len2, nums.length);
  for (let i = 0; i < tmp1.length; i++) {
    nums[2 * i] = tmp1[tmp1.length - 1 - i];
  }
  for (let i = 0; i < tmp2.length; i++) {
    nums[2 * i + 1] = tmp2[tmp2.length - 1 - i];
  }
};

function quickSelect(nums, begin, end, n) {
  let randomValue = nums[end - 1],
    left = begin,
    move = begin;
  // 将小于t的元素移到数组最左边
  while (move < end) {
    if (nums[move] <= randomValue) {
      swap(nums, left++, move++);
    } else {
      move++;
    }
  }

  // 位置n+1(i)的元素为begin到end的中位数
  if (left > n + 1) {
    // n左边
    quickSelect(nums, begin, left - 1, n);
  } else if (left <= n) {
    // n右边
    quickSelect(nums, left, end, n);
  } else {
    return;
  }
}
function swap(nums, i, j) {
  let tmp = nums[i];
  nums[i] = nums[j];
  nums[j] = tmp;
}

// 方案2：排序
var wiggleSort = function (nums) {
  const clone = nums.slice(0, nums.length).sort((a, b) => a - b);
  let N = nums.length;
  for (let i = 1; i < nums.length; i += 2) {
    nums[i] = clone[--N];
  }
  for (let i = 0; i < nums.length; i += 2) {
    nums[i] = clone[--N];
  }
};
