/**
 * Initialize your data structure here.
 */
var TrieNode = function() {
  this.next = Object.create(null);
  this.isEnd = false;
}

var Trie = function() {
  this.root = new TrieNode();
};

/**
 * Inserts a word into the trie. 
 * @param {string} word
 * @return {void}
 */
// insert
Trie.prototype.insert = function(word) {

  let node = this.root;
    for(let str of word) {
        if(!node.next[str]) {
            node.next[str] = new TrieNode();
        }
        node = node.next[str];
    }
  node.isEnd = true;

};
/*
  实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
*/


/**
 * Returns if the word is in the trie. 
 * @param {string} word
 * @return {boolean}
 */

// search
Trie.prototype.search = function(word) {
  
  let node = this.root;       // 可以包装成一个函数
  for(let str of word) {
    if(node.next[str]) {
      node = node.next[str];
    } else {
      return false;
    }
  }

  return node.isEnd;
};

/**
 * Returns if there is any word in the trie that starts with the given prefix. 
 * @param {string} prefix
 * @return {boolean}
 */
// startsWith
Trie.prototype.startsWith = function(prefix) {

  let node = this.root;       // 可以包装成一个函数
  for(let str of prefix) {
    if(node.next[str]) {
      node = node.next[str];
    } else {
      return false;
    }
  }

  return true;
}


/**
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */