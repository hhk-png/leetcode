// https://leetcode.cn/problems/convert-a-number-to-hexadecimal/submissions/

/**
 * @param {number} num
 * @return {string}
 */
function toHex(num: number): string {
    if (num === 0) {
        return "0"
    }
    const res: string[] = []
    for (let i = 7; i >= 0; i--) {
        const val: number = (num >> (4 * i)) & 0xf
        if (res.length > 0 || val > 0) {
            const digit: string = val < 10
                ? String.fromCharCode('0'.charCodeAt(0) + val)
                : String.fromCharCode('a'.charCodeAt(0) + val - 10)
            res.push(digit)
        }
    }
    return res.join('')
};

