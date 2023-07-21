var threeSumClosest = function(nums, target){
    // 排序
    nums.sort((a, b) => a-b);
    let length = nums.length;
    let min = Number.POSITIVE_INFINITY;
    let res = 0;
    let sum = 0;
    for(let i=0; i<length-2; i++){
        let first = i+1;
        let last = length-1;
        while(first < last){
            // 计算和
            sum = nums[i] + nums[first] + nums[last];
            // 相差值的绝对值
            let temp = Math.abs(sum - target);
            // last自减
            if(sum > target){
                if(temp < min){
                    min = temp;
                    res = min;
                }
                last--;
            }
            // first自增
            else if(sum < target){
                if(temp < min){
                    min = temp;
                    res = min;
                }
                first++;
            }
            // target值就是最终值
            else{
                return target;
            }
            
        }// end while
    }// end for
    return res;
};