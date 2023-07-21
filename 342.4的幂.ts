// https://leetcode.cn/problems/power-of-four/submissions/

function isPowerOfFour(n: number): boolean {
    const num: number = Math.log2(n)
    return num % 2 === 0
};
