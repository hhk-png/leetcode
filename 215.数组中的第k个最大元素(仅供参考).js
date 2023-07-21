/*
    在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

    示例 1:
    输入: [3,2,1,5,6,4] 和 k = 2
    输出: 5

    示例 2:
    输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
    输出: 4
*/

// 不能用

function swap(a, b, nums) {
  let temp = nums[a];
  nums[a] = nums[b];
  nums[b] = temp;
}

function partition(left, right, pivot_index, nums) {
  let pivot = nums[pivot_index];

  // 1. move pivot to end
  swap(pivot_index, right, nums);
  let store_index = left;

  // 2. move all smaller elements to the left
  for(let i = left; i <= right; i++) {
    if(nums[i] < pivot) {
      swap(store_index, i, nums);
      store_index++;
    }
  }

  // 3. move pivot to its final place
  swap(store_index, right, nums);

  return store_index;
}

function quickSelect(left, right, k_smallest, nums) {
  // If the list contains only one element,
  if(left === right) 
    return nums[left];
  
  // select a random pivot_index
  let pivot_index = (Math.random() * (right - left - 1) + left) | 0;

  pivot_index = left + partition(left, right, pivot_index, nums);

  // the pivot is on (N - k)th smallest position
  if(k_smallest == pivot_index) 
    return nums[k_smallest];
  // go left side
  else if (k_smallest < pivot_index)
    return quickSelect(left, pivot_index-1, k_smallest, nums);
  
  // go right side
  return quickSelect(pivot_index+1, right, k_smallest, nums);

}

var findKthLargest = function(nums, k) {
  let size = nums.length;
  // kth largest is (N - k)th smallest
  return quickSelect(0, size-1, size-k, nums);
}
