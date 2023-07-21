// https://leetcode.cn/problems/total-hamming-distance/


function totalHammingDistance(nums: number[]): number {
    let res: number = 0
    let n: number = nums.length
    for (let i = 0; i < 30; i++) {
        let c: number = 0
        for (const num of nums) {
            c += (num >> i) & 1
        }
        res += c * (n - c)
    }
    return res
};

