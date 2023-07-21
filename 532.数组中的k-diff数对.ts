
/* https://leetcode.cn/problems/k-diff-pairs-in-an-array/

给你一个整数数组 nums 和一个整数 k，请你在数组中找出 不同的 k-diff 数对，并返回不同的 k-diff 数对 的数目。

k-diff 数对定义为一个整数对 (nums[i], nums[j]) ，并满足下述全部条件：

0 <= i, j < nums.length
i != j
nums[i] - nums[j] == k
注意，|val| 表示 val 的绝对值。

 

示例 1：

输入：nums = [3, 1, 4, 1, 5], k = 2
输出：2
解释：数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
尽管数组中有两个 1 ，但我们只应返回不同的数对的数量。
示例 2：

输入：nums = [1, 2, 3, 4, 5], k = 1
输出：4
解释：数组中有四个 1-diff 数对, (1, 2), (2, 3), (3, 4) 和 (4, 5) 。
示例 3：

输入：nums = [1, 3, 1, 5, 4], k = 0
输出：1
解释：数组中只有一个 0-diff 数对，(1, 1) 。

*/

function findPairs2(nums: number[], k: number): number {
    const visited:Set<number> = new Set()
    const result:Set<number> = new Set()
    for (const num of nums) {
        // 只将数对的较小值放入 visited 中
        // visited 中的值不为负数
        // num - num[i] = k => num[i] = num - k
        if (visited.has(num - k)) {
            result.add(num - k)
        }
        //  num[i] - num = k => num[i] = num + k
        if (visited.has(num + k)) {
            result.add(num)
        }
        // 放入当前元素
        visited.add(num)
    }
    return result.size
};

function findPairs(nums: number[], k: number): number {
    nums.sort((a:number, b:number) => a - b)
    const n = nums.length
    let j = 0
    let res = 0

    for (let i:number = 0; i < n; i++) {
        if (i == 0 || (nums[i] != nums[i - 1])) {
            while (j < n && (nums[j] < nums[i] + k || j <= i)) {
                j++
            }
            if (j < n && nums[j] === nums[i] + k) {
                res++
            }
        }
    }

    return res
};

