/**
    给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

    示例 1 :

    输入:nums = [1,1,1], k = 2
    输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
    说明 :

    数组的长度为 [1, 20,000]。
    数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
 */

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function(nums, k) {
  let map = new Map();
  // 初始化，刚开始acc为0的组合个数为1
  map.set(0, 1);
  let acc = 0,
      count = 0;

  for (const num of nums) {
    acc += num;
    // sum[j] - sum[i] === k
    // 如果含有acc-k，说明从数组 j ~ i 之间的数字之和为 k
    // 数组从0开始遍历，可以保证 0 ~ i 之间的数字之和为 nk (n > 0)
    // 因为在没有组成第一个k之前，for循环体中执行的只是最下面else中的代码
    if (map.has(acc - k)) 
      count += map.get(acc - k);
    // 出现重复的acc，更新之前的acc，
    // 因为map可以自动去重，所以不会造成其他影响
    if (map.has(acc)) 
      map.set(acc, map.get(acc)+1);
    // 基本上每次都会执行，除非更新acc
    else 
      map.set(acc, 1);
  }

  console.log(map)
  console.log(map.keys())
  return count;
};

console.log(subarraySum([3,5,2,-2,4,1], 8))

