/**
 * The rand7() API is already defined for you.
 * function rand7(): number {}
 * @return a random integer in the range 1 to 7
 */

// https://leetcode.cn/problems/implement-rand10-using-rand7/submissions/


function rand10(): number {
    let idx: number = 0
    let col: number = 0
    let row: number = 0
    do {
        row = rand7()
        col = rand7()
        idx = col + (row - 1) * 7
    } while (idx > 40)
    return 1 + (idx - 1) % 10
};