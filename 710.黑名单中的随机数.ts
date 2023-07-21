
/* https://leetcode.cn/problems/random-pick-with-blacklist/

给定一个整数 n 和一个 无重复 黑名单整数数组 blacklist 。
    设计一种算法，从 [0, n - 1] 范围内的任意整数中选取一个 未加入 黑名单 blacklist 的整数。
    任何在上述范围内且不在黑名单 blacklist 中的整数都应该有 同等的可能性 被返回。

优化你的算法，使它最小化调用语言 内置 随机函数的次数。

实现 Solution 类:

Solution(int n, int[] blacklist) 初始化整数 n 和被加入黑名单 blacklist 的整数
int pick() 返回一个范围为 [0, n - 1] 且不在黑名单 blacklist 中的随机整数

*/

class Solution {
    bound: number
    b2w: Map<number, number>
    constructor(n: number, blacklist: number[]) {
        // [0, n - m) 为白名单 有 n - m 个元素
        // [n - m, n) 为黑名单 有 m 个元素
        const m: number = blacklist.length
        this.bound = n - m
        const black: Set<number> = new Set()
        for (const blk of blacklist) {
            // 找到blacklist 中大于等于 n - m 的值，添加到black 中
            //  black 中的值不需要映射
            if (blk >= this.bound) {
                black.add(blk)
            }
        }
        
        // 只有小于bound 的值需要映射

        this.b2w = new Map()
        // 在黑名单的起始位置开始寻找
        let w: number = this.bound
        // 再次遍历 blacklist，找到需要映射的值
        for (const b of blacklist) {
            if (b < this.bound) {
                // 在黑名单的界限中找到一个不在black 中的值，也就是需要进行映射，
                //  此值为黑名单中的值，但是在白名单的范围中
                while (black.has(w)) {
                    w++
                }
                // 设置映射
                this.b2w.set(b, w)
                w++
            }
        }
    }

    pick(): number {
        // 使用白名单的长度初始化随机数
        const num: number = Math.floor(Math.random() * this.bound)
        // 如果找不到对应的值，则说明值本身在白名单中，不需要映射
        return this.b2w.get(num) || num
    }
}