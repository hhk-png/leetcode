
// https://leetcode.cn/problems/implement-magic-dictionary/

class MagicDictionary {
    root: Trie
    constructor() {
        this.root = new Trie()
    }

    buildDict(dictionary: string[]): void {
        for (const dic of dictionary) {
            let curr: Trie = this.root
            for (let i = 0; i < dic.length; i++) {
                const c = dic[i].charCodeAt(0) - 'a'.charCodeAt(0)
                if (!curr.children.has(c)) {
                    curr.children.set(c, new Trie())
                }
                curr = curr.children.get(c) as Trie
            }
            curr.isFinished = true
        }
    }

    search(searchWord: string): boolean {
        return dfs(searchWord, this.root, 0, false)
    }

    
}

const dfs = (word: string, node: Trie, pos: number, modified: boolean): boolean => {
    if (pos == word.length) {
        // 更改过一次 modefied 并且node 达到了最后
        return modified && node.isFinished
    }

    // 继承上一次的modified，modified 为 true 或者 false
    const idx = word[pos].charCodeAt(0) - 'a'.charCodeAt(0)
    if (node.children.has(idx)) {
        if (dfs(word, node.children.get(idx) as Trie, pos + 1, modified)) {
            return true
        }
    }

    // 更改字符，只走一次这个判断
    if (!modified) {
        for (let i = 0; i < 26; i++) {
            // 不要等于idx，因为上面已经走过了
            if (i !== idx && node.children.has(i)) {
                // 更改下一个要dfs 的字符
                if (dfs(word, node.children.get(i) as Trie, pos + 1, true)) {
                    return true
                }
            }
        }
    }

    return false
}

class Trie {
    isFinished: boolean
    children: Map<number, Trie>
    constructor() {
        this.isFinished = false
        this.children = new Map()
    }
}
