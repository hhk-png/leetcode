// https://leetcode.cn/problems/add-digits/submissions/

function addUp(num: number) {
    let result: number = 0
    while (num !== 0) {
        const temp: number = num % 10
        result += temp
        num = Math.floor(num / 10)
    }
    return result
}

function isSingledigit(num: number) {
    return !(num > 9)
}

function addDigits(num: number): number {
    if (isSingledigit(num)) {
        return num
    }
    while (!isSingledigit(num)) {
        num = addUp(num)
    }
    return num
};


