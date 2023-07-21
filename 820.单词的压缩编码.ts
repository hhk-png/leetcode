// https://leetcode.cn/problems/short-encoding-of-words/submissions/

// Set
function minimumLengthEncoding2(words: string[]): number {
    const good: Set<string> = new Set(words)
    for (const word of words) {
        // i 不能为1，否则会将word 全部删掉，要从0 开始截取
        for (let i = 1; i < word.length; i++) {
            good.delete(word.substring(i))
        }
    }

    let result: number = 0
    for (const word of good) {
        result += word.length + 1
    }

    return result
};

// 前缀树
const ACharCode: number = 'a'.charCodeAt(0)

class Trie {
    children: Map<number, Trie>
    count: number
    constructor() {
        this.children = new Map()
        this.count = 0
    }
    
    set(child: number) {
        if (!this.children.get(child)) {
            this.children.set(child, new Trie())
            this.count++
        }
        return this.children.get(child)
    }
}

function minimumLengthEncoding(words: string[]): number {
    const root: Trie = new Trie()
    const index: Map<Trie, number> = new Map()

    for (let i = 0; i < words.length; i++) {
        const word: string = words[i]
        let temp: Trie = root
        for (let j = word.length - 1; j >= 0; j--) {
            // 这里写的不错
            temp = temp.set(word.charCodeAt(j) - ACharCode) as Trie
        }
        index.set(temp, i)
    }

    let result: number = 0
    for (const [node, idx] of index) {
        if (node.count === 0) {
            result += words[idx].length + 1
        }
    }
    return result
};