// https://leetcode.cn/problems/rotate-function/submissions/

function maxRotateFunction(nums: number[]): number {
    const n: number = nums.length
    const numSum: number = nums.reduce((acc: number, val: number) => acc += val, 0)
    // f(0)
    let f: number = nums.reduce((acc: number, val: number, index: number) => acc += val * index, 0)

    // 初始为 f(0)
    let res: number = f
    for (let i = n - 1; i > 0; i--) {
        f += numSum - n * nums[i]
        res = Math.max(res, f);
    }

    return res
};