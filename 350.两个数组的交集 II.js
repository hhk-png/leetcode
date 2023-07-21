/*
    给定两个数组，编写一个函数来计算它们的交集。


    示例 1：
      输入：nums1 = [1,2,2,1], nums2 = [2,2]
      输出：[2,2]

    示例 2:
      输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
      输出：[4,9]
     

    说明：
      输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
      我们可以不考虑输出结果的顺序。

    进阶：
      如果给定的数组已经排好序呢？你将如何优化你的算法？
      如果 nums1 的大小比 nums2 小很多，哪种方法更优？
      如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
*/
// Hash
var intersect1 = function (nums1, nums2) {
  if (nums1.length > nums2.length) {
    return intersect(nums2, nums1);
  }

  const hash = {};
  const result = [];
  // 构建hash
  for (const num of nums1) {
    if (hash[num]) {
      hash[num]++;
    } else {
      hash[num] = 1;
    }
  }

  // 进行判断
  for (const num of nums2) {
    if (hash[num]) {
      result.push(num);
      hash[num]--;
    }
  }

  return result;
}


// 排序 + 双指针
var intersect1 = function(nums1, nums2) {
  // 排序
  nums1.sort((a, b) => a - b);
  nums2.sort((a, b) => a - b);

  let index1 = 0;
  let index2 = 0;
  const result = [];

  while (index1 < nums1.length && index2 < nums2.length) {
    if (nums1[index1] < nums2[index2]) {
      index1++;
    } else if (nums2[index2] < nums1[index1]) {
      index2++;
    } else {
      result.push(nums1[index1]);
      index1++;
      index2++;
    }
  }

  return result;
}
