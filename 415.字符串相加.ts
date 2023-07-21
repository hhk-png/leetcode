// https://leetcode.cn/problems/add-strings/

function addStrings(num1: string, num2: string): string {
    let i: number = num1.length - 1
    let j: number = num2.length - 1
    let carry: number = 0
    const res: number[] = []
    while (i >= 0 || j >= 0 || carry != 0) {
        const x: number = i >= 0 ? num1.charCodeAt(i) - '0'.charCodeAt(0) : 0
        const y: number = j >= 0 ? num2.charCodeAt(j) - '0'.charCodeAt(0) : 0
        const result = x + y + carry
        res.unshift(result % 10)
        carry = Math.floor(result / 10)
        i--
        j--
    }
    return res.join('')
};
