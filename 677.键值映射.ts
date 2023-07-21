// https://leetcode.cn/problems/map-sum-pairs/

class MapSum {
    map: Map<string, number>
    constructor() {
        this.map = new Map()
    }

    insert(key: string, val: number): void {
        this.map.set(key, val)
    }

    sum(prefix: string): number {
        let result: number = 0
        for (const [key, val] of this.map.entries()) {
            if (key.startsWith(prefix)) {
                result += val
            }
        }

        return result
    }
}