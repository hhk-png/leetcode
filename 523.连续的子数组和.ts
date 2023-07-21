/* https://leetcode.cn/problems/continuous-subarray-sum/

给你一个整数数组 nums 和一个整数 k ，编写一个函数来判断该数组是否含有同时满足下述条件的连续子数组：

子数组大小 至少为 2 ，且
子数组元素总和为 k 的倍数。
如果存在，返回 true ；否则，返回 false 。

如果存在一个整数 n ，令整数 x 符合 x = n * k ，则称 x 是 k 的一个倍数。0 始终视为 k 的一个倍数。

示例 1：

输入：nums = [23,2,4,6,7], k = 6
输出：true
解释：[2,4] 是一个大小为 2 的子数组，并且和为 6 。
示例 2：

输入：nums = [23,2,6,4,7], k = 6
输出：true
解释：[23, 2, 6, 4, 7] 是大小为 5 的子数组，并且和为 42 。 
42 是 6 的倍数，因为 42 = 7 * 6 且 7 是一个整数。
示例 3：

输入：nums = [23,2,6,4,7], k = 13
输出：false

*/

function checkSubarraySum(nums: number[], k: number): boolean {
    const n:number = nums.length
    // 
    if (n < 2) return false
    const mp:Map<number, number> = new Map()
    // 前缀和
    let prefix:number = 0
    // 设置一个 (0, -1) 的初始值
    mp.set(0, -1)
    for (let i:number = 0; i < n; i++) {
        // 对前缀和进行了处理 每次前缀和都要与 k 取模
        prefix = (prefix + nums[i]) % k
        // 如果之前有当前的 prefix, 说明这一段数组值的和与 k 取模后为0，是 k 的倍数
        if (mp.has(prefix)) {
            // 要保证这段数组的长度大于 2
            const prev:number = mp.get(prefix) as number
            if (i - prev >= 2) {
                return true
            }
        } else {
            // mp 中只需要保存第一次遇到的 prefix 值
            // 否则 [5,0,0,0] 3 => 不通过
            mp.set(prefix, i)
        }
    }
    return false
};