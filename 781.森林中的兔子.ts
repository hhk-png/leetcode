// https://leetcode.cn/problems/rabbits-in-forest/submissions/

function numRabbits(answers: number[]): number {
    let result: number = 0
    const count: Map<number, number> = new Map()
    for (const answer of answers) {
        // count[answer] 为0 或者不存在，需要开辟一个新map
        //  假设有n个相同颜色的兔子，则最多有n个兔子喊n - 1，
        //  如果有多余的n - 1，则是其余颜色的兔子，需要令开辟一个map计算
        //  answer + 1 为该颜色兔子的总量，
        if (!count.get(answer)) {
            result += (answer + 1)
            count.set(answer, answer)
        } else { // 
            count.set(answer, count.get(answer) as number - 1)
        }
    }
    return result
};