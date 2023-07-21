// https://leetcode.cn/problems/random-flip-matrix/submissions/

class Solution {
    m: number
    n: number
    total: number
    map: Map<number, number>
    constructor(m: number, n: number) {
        this.m = m
        this.n = n
        this.total = this.m * this.n
        this.map = new Map()
    }

    flip(): number[] {
        const temp: number = Math.floor((Math.random() * this.total))
        this.total--
        const index: number = this.map.get(temp) || temp
        this.map.set(temp, this.map.get(this.total) || this.total)
        return [Math.floor(index / this.n), index % this.n]
    }

    reset(): void {
        this.total = this.m * this.n
        this.map.clear()
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(m, n)
 * var param_1 = obj.flip()
 * obj.reset()
 */