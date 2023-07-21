// https://leetcode.cn/problems/perfect-number/submissions/

function checkPerfectNumber(num: number): boolean {
    if (num === 1) {
        return false
    }

    let sum: number = 1
    for (let d = 2; d * d <= num; d++) {
        if (num % d === 0) {
            sum += d
            if (d * d < num) {
                sum += (num / d)
            }
        }
    }
    return sum === num
};
function checkPerfectNumber2(num: number): boolean {
    return num === 6 || num === 28 || num === 496 || num === 8128 || num === 33550336;
};

