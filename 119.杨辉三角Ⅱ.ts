// https://leetcode.cn/problems/pascals-triangle-ii/submissions/

function getRow(rowIndex: number): number[] {
    const result: Array<number> = new Array(rowIndex + 1).fill(0)
    result[0] = 1
    for (let i = 1; i <= rowIndex; i++) {
        for (let j = i; j > 0; j--) {
            result[j] += result[j - 1]
        }
    }

    return result
};