var convert = function(s, numRows){
    if(numRow == 1){
        return s;
    }

    // 对存放结果的数组进行处理
    const len = Math.min(s.length, numRows);
    let row = [];
    for(let i=0; i<len; i++) row[i] = "";

    // 分配字符串s
    let loc = 0;
    let down = false;
    for(const c of s){
        row[loc] += c;
        // 当loc为0 或者 到达了数组的最后一个位置时，进行down的翻转
        if(loc == 0 || loc == numRows-1){
            down = !down;
        }
        loc += down? 1:-1;
    }

    // 对数组中的元素拼串
    let ans = "";
    for(const row of row){
        ans += row;
    }

    return ans;
};