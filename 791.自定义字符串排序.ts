// https://leetcode.cn/problems/custom-sort-string/submissions/

function customSortString(order: string, s: string): string {
    const val: Array<number> = new Array(26).fill(0)
    const ACharCode: number = 'a'.charCodeAt(0)
    for (let i = 0; i < order.length; i++) {
        val[order[i].charCodeAt(0) - ACharCode] = i + 1
    }
    return Array.from(s).sort((s1: string, s2: string) => 
        val[s1.charCodeAt(0) - ACharCode] - val[s2.charCodeAt(0) - ACharCode]
    ).join('')
};