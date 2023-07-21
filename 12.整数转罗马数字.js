// 整数转罗马数字
function T12(num){
    if(num>9999) return '';
    // 各个阿拉伯数字对应的罗马数字
    var nums = [9000, 5000, 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
    var romans = ['M*', '*', 'M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I'];
    var numText = '';
    // for循环15次对应各个基数
    for(var i=0; i<nums.length; i++){
        while(num >= nums[i]){
            numText += romans[i];
            num -= nums[i];
        }
    }
    return numText;
}