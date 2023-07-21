

/* https://leetcode.cn/problems/top-k-frequent-words/

给定一个单词列表 words 和一个整数 k ，返回前 k 个出现次数最多的单词。

返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率， 按字典顺序 排序。

*/

function topKFrequent(words: string[], k: number): string[] {
    const cnt: Map<string, number> = new Map()
    for (const word of words) {
        cnt.set(word, (cnt.get(word) || 0) + 1)
    }

    return Array.from(cnt.keys()).sort((word1: string, word2:string):number => {
        return cnt.get(word1) === cnt.get(word2) 
        ? word1.localeCompare(word2) 
        : ((cnt.get(word2) || 0) - (cnt.get(word1) || 0))
    }).slice(0, k)

};