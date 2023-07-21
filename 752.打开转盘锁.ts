// https://leetcode.cn/problems/open-the-lock/

function openLock(deadends: string[], target: string): number {
    if (target === '0000') return 0

    const deadSet: Set<string> = new Set(deadends)
    if (deadSet.has('0000')) return -1

    let step: number = 0
    const queue: string[] = []
    queue.push('0000')
    const seen: Set<string> = new Set()
    seen.add('0000')

    while (queue.length) {
        ++step
        const len: number = queue.length
        for (let i = 0; i < len; i++) {
            const currState: string = queue.shift() as string
            for (const state of getNextStatus(currState)) {
                if (!seen.has(state) && !deadSet.has(state)) {
                    if (state === target) {
                        return step
                    }
                    seen.add(state)
                    queue.push(state)
                }
            }
        }
    }

    return -1
};

const prevNum = (x: string): string => {
    return x === '0' ? '9' : (parseInt(x) - 1) + ''
}

const nextNum = (x: string): string => {
    return x === '9' ? '0' : (parseInt(x) + 1) + ''
}

const getNextStatus = (status: string): string[] => {
    const result: string[] = []
    const statusArr: string[] = Array.from(status)
    for (let i = 0; i < 4; i++) {
        const num: string = statusArr[i]
        statusArr[i] = nextNum(num)
        result.push(statusArr.join(''))
        statusArr[i] = prevNum(num)
        result.push(statusArr.join(''))
        // 下一轮循环之前一定要将本次操作的数变回来
        statusArr[i] = num
    }
    return result
}

