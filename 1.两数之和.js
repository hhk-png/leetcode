// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

// 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

// 使用对象进行数据的存储与查找
// 对象的hasOwnProperty()方法的使用
var twoSum = function (nums, target) {
  let map = {};

  for (let i = 0; i < nums.length; i++) {
    let n = target - nums[i];
    let hasVal = map.hasOwnProperty(n);
    if (hasVal) {
      return [map[n], i];
    }
    // 如果map对象中没有n，那么就将此次遍历的数据元素存储在map中
    map[nums[i]] = i;
  }
  return [];
};


// c++
// class Solution {
//   public:
//       vector<int> twoSum(vector<int>& nums, int target) {
//           unordered_map<int, int> hashtable;
//           for (int i = 0; i < nums.size(); i++) {
//               int find_num = target - nums[i];
//               auto it = hashtable.find(find_num);
//               if (it != hashtable.end()) {
//                   return {it->second, i};
//               }
//               hashtable[nums[i]] = i;
//           }
//           return {};
//       }
//   };