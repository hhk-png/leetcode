// https://leetcode.cn/problems/beautiful-arrangement/submissions/

function population_32(int32: number): number {
    int32 -= (int32 >>> 1) & 0x55555555;
    int32 = (int32 & 0x33333333) + ((int32 >>> 2) & 0x33333333);
    int32 = (int32 + (int32 >>> 4)) & 0x0F0F0F0F;
    int32 = (int32 + (int32 >>> 8)) & 0x001F001F;
    return (int32 + (int32 >>> 16)) & 0x0000003F;
}

function countArrangement(n: number): number {
    const dp: number[] = new Array(1 << n).fill(0);
    dp[0] = 1;
    for (let mask = 1; mask < (1 << n); mask++) {
        const num = population_32(mask);
        for (let i = 0; i < n; i++) {
            if (
                (mask & (1 << i)) !==0
                && (
                    (num % (i + 1) === 0)
                    || ((i + 1) % num === 0)
                )
            ) {
                dp[mask] += dp[mask ^ (1 << i)];
            }
        }
    }
    return dp[(1 << n) - 1];
};
