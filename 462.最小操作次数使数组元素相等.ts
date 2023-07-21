// https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-ii/submissions/

function minMoves2(nums: number[]): number {
    nums.sort((a, b) => a - b)
    const target: number = nums[Math.floor(nums.length / 2)]
    let res: number = 0
    for (const num of nums) {
        res += Math.abs(num - target)
    }
    return res
};
