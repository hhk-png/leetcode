// https://leetcode.cn/problems/arranging-coins/submissions/

var arrangeCoins = function(n: number): number {
    let left: number = 1
    let right: number = n;
    while (left < right) {
        const mid: number = Math.floor((right - left + 1) / 2) + left;
        if (mid * (mid + 1) <= 2 * n) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
};

function arrangeCoins2(n: number): number {
    let sum: number = 0
    let count: number = 0
    while (sum <= n) {
        count++
        sum += count
    }
    return count - 1
};
