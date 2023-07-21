/*
    给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

    你可以假设数组是非空的，并且给定的数组总是存在多数元素。

     

    示例 1:

    输入: [3,2,3]
    输出: 3
    示例 2:

    输入: [2,2,1,1,1,2,2]
    输出: 2
*/

// hash
var majorityElement = function(nums) {
  let obj = {};

  for(let i = 0; i < nums.length; i++) {
    if(!obj[nums[i]]) {
      obj[nums[i]] = 1;
    } else {
    obj[nums[i]] += 1;
    }
  }

  let num = Math.floor(nums.length/2);

  for(const key in obj) {
    if(obj[key] > num) {
      return key;
    }
  }
};

// Boyer-Moore 投票算法
var majorityElement = function(nums) {

  let count = 0;
  let candidate = -1;

  for (let num of nums) {
    if (count == 0) {
      candidate = num;
    }
    count += (num == candidate) ? 1 : -1;
  }

  return candidate;
};