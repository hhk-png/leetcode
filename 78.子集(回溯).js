/*
    给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

    说明：解集不能包含重复的子集。

    示例:

    输入: nums = [1,2,3]
    输出:
    [
      [3],
      [1],
      [2],
      [1,2,3],
      [1,3],
      [2,3],
      [1,2],
      []
    ]
*/

// 右边回溯(currentIndex ~ nums.length)
// 需要的条件，用于保存结果的数组(output)，存放子结果的数组(curr)，每次开始查找的位置(currentIndex);
var subsets = function(nums) {
  if(nums.length === 0) return [[]];
  let output = [];
  let curr = [];
  let n = nums.length;
  
  // 函数
  const backtrack = (curr, currentIndex) => {

    // 退出条件
    output.push(curr);
    if(curr.length >= n) return;
      
    // 回溯主体
    for(let i = currentIndex; i < n; i++) {
        curr.push(nums[i]);
        backtrack(curr.slice(), i+1);
        curr.pop();
    }
  }

  backtrack(curr, 0);
  return output;
};


// java版，
// 从左边回溯(0 ~ currentIndex(0-nums.length))
// class Solution {
//   let output = []
//   int n, k;

//   public void backtrack(int first, ArrayList<Integer> curr, int[] nums) {

//     if (curr.size() == k)
//       output.add(new ArrayList(curr));

//     for (int i = first; i < n; ++i) {

//       curr.add(nums[i]);

//       backtrack(i + 1, curr, nums);

//       curr.remove(curr.size() - 1);
//     }
//   }

//   public List<List<Integer>> subsets(int[] nums) {
//     n = nums.length;
//     for (k = 0; k < n + 1; ++k) {
//       backtrack(0, new ArrayList<Integer>(), nums);
//     }
//     return output;
//   }
// }