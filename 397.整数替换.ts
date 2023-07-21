// https://leetcode.cn/problems/integer-replacement/submissions/

const memo: Map<number, number> = new Map()

function integerReplacement(n: number): number {
    if (n == 1) {
        return 0;
    }
    if (!memo.has(n)) {
        if (n % 2 === 0) {
            memo.set(n, 1 + integerReplacement(Math.floor(n / 2)));
        } else {
            memo.set(n, 2 + Math.min(integerReplacement(Math.floor(n / 2)), integerReplacement(Math.floor(n / 2) + 1)));
        }
    }

    return memo.get(n) as number;
};