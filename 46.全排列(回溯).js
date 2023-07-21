// 给定一个没有重复数字的序列，返回其所有可能的全排列。
// 输入: [1,2,3]
// 输出:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]


// 主函数
// nums=[1]的时候，leetcode运行的结果和浏览器运行的结果不一样
let res = [];
function backtrack(nums, path) {
    // 触发结束条件
    if(path.length === nums.length) {
        res.push([...path])
        return;
    }
    for(let i = 0; i < nums.length; i++) {
        // 排除不合法的选择
        if(path.includes(nums[i])) 
            continue;
        // 做选择
        path.push(nums[i]);
        // 进入下一层决策树，此时path的长度比for循环之前多1
        backtrack(nums, path);
        // 取消选择
        path.pop();
    }
}

const permute = function(nums) {
    // 路径
    let path = [];
    backtrack(nums, path);
    return res;
};
