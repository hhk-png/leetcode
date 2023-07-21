// https://leetcode.cn/problems/largest-palindrome-product/

function largestPalindrome(n: number): number {
    if (n === 1) {
        return 9
    }
    const upper = 10 ** n - 1
    for (let left = upper; left > upper / 10; left--) {
        let right: string = String(left).split('').reverse().join('')
        let p: bigint = BigInt(String(left) + right)
        let x = BigInt(upper)
        while (x * x >= p) {
            if (p % x === BigInt(0)) {
                return Number(p % BigInt(1337))
            }
            x--
        }
    }
    return 0
};



