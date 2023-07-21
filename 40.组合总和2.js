// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
// 所求解集为:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]

var combinationSum2 = function(candidates, target) {
    let n = candidates.length;
    let res = [];
    let tmpPath = [];
    // 排序
    candidates = candidates.sort((a,b) => {return a - b});
    // 递归函数
    let backtrack = (tmpPath,target,start) => {
        // 
        if(target == 0){
            res.push(tmpPath);
            return;
        }
        for(let i = start;i < n;i++){
            if(target < candidates[i]){
                break;
            }
            if(i > start && candidates[i-1] == candidates[i]){
                continue;
            }
            tmpPath.push(candidates[i]);
            backtrack(tmpPath.slice(),target - candidates[i],i + 1);
            tmpPath.pop();
        }
    }
    backtrack(tmpPath,target,0);
    return res;
};

// 39改
var combinationSum = function (candidates, target) {
    candidates.sort((a, b) => b - a);
  
    let res = [], path = [];
    let len = candidates.length, minNum = candidates[len - 1];
  
    get_combin(target, 0, path);

    function get_combin(target, start, path) {
        if (target == 0) {
            return res.push(path.slice());
        }
    
        // 这里不用小于 0，小于最小的数就可以返回了
        if (target < minNum) return;
    
        for (let i = start; i < len; i++) {
            // 如果本次循环的数组元素与上一个的元素相同就跳过本次循环，否则会出现相同path
            // 并且在i>start的条件下，
            // 只是为了消除[1,1,2,3]这种循环到第二个1这种情况
            if(i > start && candidates[i-1] == candidates[i]){
                continue;
            }
            path.push(candidates[i]);
            // i ==> i+1
            get_combin(target - candidates[i], i + 1, path);
            path.pop();
        }
    }
  
    return res;
};