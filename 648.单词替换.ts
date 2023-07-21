/* https://leetcode.cn/problems/replace-words/

在英语中，我们有一个叫做 词根(root) 的概念，可以词根后面添加其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。

现在，给定一个由许多词根组成的词典 dictionary 和一个用空格分隔单词形成的句子 sentence。你需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。

你需要输出替换之后的句子。

 

示例 1：

输入：dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
输出："the cat was rat by the bat"
示例 2：

输入：dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
输出："a a b c"

*/


// 字典树的类
class Trie {
    children:Map<string, Trie>
    constructor() {
        this.children = new Map()
    }
}

function replaceWords2(dictionary: string[], sentence: string): string {
    // 初始化字典树
    const root:Trie = initTrie(dictionary)
    // 找到最短单词
    const result:string[] = []
    const words = sentence.split(' ')
    for (const s of words) {
        result.push(findMinWord(s, root))
    }
    // 返回结果
    return result.join(' ')
};

function findMinWord(word: string, root: Trie):string {
    let result:string = ''
    let curr:Trie = root
    for (const c of word) {
        // 在对children 进行操作时，需要应对三种情况
        //  #，有对应字符，无对应字符
        if (curr.children.has('#')) {
            return result
        }
        if (!curr.children.has(c)) {
            return word
        }
        result += c
        curr = curr.children.get(c) as Trie
    }
    return result
}

function initTrie(dictionary: string[]):Trie {
    const root:Trie = new Trie()
    for (const dic of dictionary) {
        let curr:Trie = root
        for (const c of dic) {
            if (!curr.children.has(c)) {
                curr.children.set(c, new Trie())
            }
            curr = curr.children.get(c) as Trie
        }
        // 标记最后的结束符号
        curr.children.set("#", new Trie());
    }
    return root
}

// hash
function replaceWords(dictionary: string[], sentence: string): string {
    const hash:Set<string> = new Set()
    for (const dic of dictionary) {
        hash.add(dic)
    }

    const words:string[] = sentence.split(' ')
    for (let i = 0; i < words.length; i++) {
        const word:string = words[i]
        for (let j = 0; j < word.length; j++) {
            const subWord:string = word.substring(0, 1 + j)
            if (hash.has(subWord)) {
                words[i] = subWord
                break
            }
        }
    }
    return words.join(' ')
};
