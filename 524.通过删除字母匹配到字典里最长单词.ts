
/* https://leetcode.cn/problems/longest-word-in-dictionary-through-deleting/

给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary 中最长的字符串，该字符串可以通过删除 s 中的某些字符得到。

如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。

 

示例 1：

输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
输出："apple"
示例 2：

输入：s = "abpcplea", dictionary = ["a","b","c"]
输出："a"

*/

function findLongestWord(s: string, dictionary: string[]): string {
    let result:string = ""
    for (const dic of dictionary) {
        let left:number = 0
        let right:number = 0
        while (left < dic.length && right < s.length) {
            if (dic[left] == s[right]) {
                left++
            }
            right++
        }
        if (left === dic.length) {
            if (dic.length > result.length || (dic.length === result.length && dic < result)) {
                result = dic
            }
        }
    }

    return result;
};


/*

// 我们可以先将 dictionary 依据字符串长度的降序和字典序的升序进行排序，
//  然后从前向后找到第一个符合条件的字符串直接返回即可。

var findLongestWord = function(s, dictionary) {
    dictionary.sort((word1, word2) => {
        if (word1.length !== word2.length) {
            return word2.length - word1.length;
        } else {
            return word1.localeCompare(word2);
        }
    });
    console.log(dictionary)

    for (const t of dictionary) {
        let i = 0, j = 0;
        while (i < t.length && j < s.length) {
            if (t[i] === s[j]) {
                ++i;
            }
            ++j;
        }
        if (i === t.length) {
            return t;
        }
    }
    return "";
};

*/

/* 动态规划


var findLongestWord = function(s, dictionary) {
    const m = s.length;
    const f = new Array(m + 1).fill(0).map(() => new Array(26).fill(m));

    for (let i = m - 1; i >= 0; --i) {
        for (let j = 0; j < 26; ++j) {
            if (s[i] === String.fromCharCode('a'.charCodeAt() + j)) {
                f[i][j] = i;
            } else {
                f[i][j] = f[i + 1][j];
            }
        }
    }
    let res = "";
    for (const t of dictionary) {
        let match = true;
        let j = 0;
        for (let i = 0; i < t.length; ++i) {
            if (f[j][t[i].charCodeAt() - 'a'.charCodeAt()] === m) {
                match = false;
                break;
            }
            j = f[j][t[i].charCodeAt() - 'a'.charCodeAt()] + 1;
        }
        if (match) {
            if (t.length > res.length ||  (t.length === res.length && t.localeCompare(res) < 0)) {
                res = t;
            }
        }
    }
    return res;
};

*/
