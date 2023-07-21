// https://leetcode.cn/problems/random-point-in-non-overlapping-rectangles/

class Solution {
    rects: number[][]
    preSum: number[]
    constructor(rects: number[][]) {
        this.rects = rects
        this.preSum = [0]
        for (const rect of rects) {
            const a = rect[0]
            const b = rect[1]
            const x = rect[2]
            const y = rect[3]
            this.preSum.push(this.preSum[this.preSum.length - 1] + (x - a + 1) * (y - b + 1))
        }
    }

    pick(): number[] {
        let k = Math.floor(Math.random() * this.preSum[this.preSum.length - 1])
        const rectIndex = this.binarySearch(this.preSum, k + 1) - 1
        k -= this.preSum[rectIndex]
        const rect = this.rects[rectIndex]
        const startX = rect[0]
        const startY = rect[1]
        const y = rect[3]
        const colNum = y - startY + 1
        const deltaA = Math.floor(k / colNum)
        const deltaB = k - colNum * deltaA
        return [startX + deltaA, startY + deltaB]
    }

    binarySearch(arr: number[], target: number) {
        let left = 0
        let right = arr.length - 1
        
        while (left <= right) {
            const mid = left + Math.floor((right - left) / 2)
            if (target === arr[mid]) {
                return mid
            } else if (target > arr[mid]) {
                left = mid + 1
            } else {
                right = mid - 1
            }
        }
        return left
    }
}