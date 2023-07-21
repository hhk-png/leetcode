/*
    https://leetcode.cn/problems/complex-number-multiplication/
*/

function complexNumberMultiply(num1: string, num2: string): string {
    const n1:[number, number] = getNum(num1)
    const n2:[number, number] = getNum(num2)
    const resultLeft = n1[0] * n2[0] - n1[1] * n2[1]
    const resultRight = n1[0] * n2[1] + n1[1] * n2[0]
    return '' + resultLeft + '+' + resultRight + 'i'
};

function getNum(num: string): [number, number] {
    const ans:string[] = num.split("+")
    const numLeft:number = parseInt(ans[0])
    const ans1:string = ans[1]
    const numRight:number = parseInt(ans1.substr(0, ans1.length - 1))
    return [numLeft, numRight]
}
