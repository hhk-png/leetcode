// https://leetcode.cn/problems/base-7/submissions/

function convertToBase7(num: number): string {
    if (num === 0) {
        return '0'
    }
    if (num < 0) {
        return '-' + convertToBase7(-num)
    }
    let res: number[] = []
    while (num !== 0) {
        res.push(num % 7)
        num = Math.floor(num / 7)
    }
    return res.reverse().join('')
};
