// 给定一个可包含重复数字的序列，返回所有不重复的全排列。
var permuteUnique = function(nums) {
    let n = nums.length;
    nums = nums.sort((a,b) => {return a - b});
    let res = [];
    let tmpPath = [];
    let hash = {};
    let backtrack = (tmpPath) => {
        if(tmpPath.length == n){
            res.push(tmpPath);
            return;
        }
        for (let i = 0; i < n; i++) {
            if (hash[i] || (i > 0 && !hash[i - 1] && nums[i - 1] == nums[i]))
                continue;
            hash[i] = true;
            tmpPath.push(nums[i]);
            // 这里使用slice()：
            //      如果不使用slice的话，传进去的就是数组的引用，而不是再复制一个数组，但是数组是会随着程序的运行而变化的，
            //      这里要求传进去的数组是不会变化的，而且其中的元素要与此时数组的元素相同，所以要复制一份
            backtrack(tmpPath.slice());
            hash[i] = false;
            tmpPath.pop();
        }
    }
    backtrack(tmpPath);
    return res;
};