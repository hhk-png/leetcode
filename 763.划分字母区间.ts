// https://leetcode.cn/problems/partition-labels/submissions/

function partitionLabels(s: string): number[] {
    const last: number[] = new Array(26)
    const codeA: number = 'a'.charCodeAt(0)
    const n: number = s.length
    // 计算每个字母出现的最后位置
    for (let i = 0; i < n; i++) {
        last[s.charCodeAt(i) - codeA] = i
    }

    const partition: number[] = []
    let start: number = 0
    let end: number = 0
    // 闭区间 [start, end]
    for (let i = 0; i < n; i++) {
        end = Math.max(end, last[s.charCodeAt(i) - codeA])
        if (i === end) {
            partition.push(end - start + 1)
            start = end
        }
    }
    return partition
};


