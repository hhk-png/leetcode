// https://leetcode.cn/problems/minimum-moves-to-equal-array-elements/

function minMoves(nums: number[]): number {
    const minNum = Math.min(...nums)
    let res: number = 0
    for (const num of nums) {
        res += num - minNum
    }
    return res
};
