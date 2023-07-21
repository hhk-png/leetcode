/* https://leetcode.cn/problems/longest-word-in-dictionary/

给出一个字符串数组 words 组成的一本英语词典。
    返回 words 中最长的一个单词，该单词是由 words 词典中其他单词逐步添加一个字母组成。

若其中有多个可行的答案，则返回答案中字典序最小的单词。若无答案，则返回空字符串。

 

示例 1：

输入：words = ["w","wo","wor","worl", "world"]
输出："world"
解释： 单词"world"可由"w", "wo", "wor", 和 "worl"逐步添加一个字母组成。
示例 2：

输入：words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
输出："apple"
解释："apply" 和 "apple" 都能由词典中的单词组成。但是 "apple" 的字典序小于 "apply" 

*/

class Trie {
    isEnd: boolean
    children: Map<number, Trie>
    constructor() {
        this.children = new Map()
        this.isEnd = false
    }
}

const ACode: number = 'a'.charCodeAt(0)

function initTrie(words: string[]): Trie {
    const root: Trie = new Trie()
    for (const word of words) {
        let curr: Trie = root
        for (const c of word) {
            const index: number = c.charCodeAt(0) - ACode
            const child: Map<number, Trie> = curr.children
            if (!child.has(index)) {
                child.set(index, new Trie())
            }
            curr = child.get(index) as Trie
        }
        curr.isEnd = true
    }
    return root
}

function search(root: Trie, word: string): boolean {
    for (const c of word) {
        const index: number = c.charCodeAt(0) - ACode
        const child: Trie | undefined = root.children.get(index)
        // 在搜索的时候，每个节点的isEnd 一定为 true , 表示单词在words 中
        //  或者节点不存在
        if (!child || !child?.isEnd) {
            return false
        }
        root = child as Trie
    }
    return root && root.isEnd
}

function longestWord(words: string[]): string {
    const root: Trie = initTrie(words)

    let longest: string = ''
    for (const word of words) {
        if (search(root, word)) {
            // localeCompare 返回的结果小于1(为 -1) 表示 word 的字典序在 longest 前面 
            if (longest.length < word.length || (longest.length === word.length && word.localeCompare(longest) < 0)) {
                longest = word
            }
        }
    }
    return longest
};