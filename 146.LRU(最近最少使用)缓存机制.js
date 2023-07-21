/*
    运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

    获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
    写入数据 put(key, value) - 如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥/数据值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。


    进阶:
    你是否可以在 O(1) 时间复杂度内完成这两种操作？
*/



// 使用map

/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {
  this.capacity = capacity;
  this.map = new Map();
};

/** 
* @param {number} key
* @return {number}
*/
LRUCache.prototype.get = function(key) {
  let val = this.map.get(key);
  if(val === undefined) return -1;
  // 最近最少使用
  // 把访问过的元素放到map的最后面，这样删除元素的时候删除最前面的就可以了
  this.map.delete(key);
  this.map.set(key,val);
  return val;
};

/** 
* @param {number} key 
* @param {number} value
* @return {void}
*/
LRUCache.prototype.put = function(key, value) {
  // 如果map中有想要添加的key，
  // 就删除原来的key，再次建立想要添加的key，进行更新
  if(this.map.has(key)) {
    this.map.delete(key);
  }

  this.map.set(key, value);

  // map内元素满的时候，就要先在最后面建立一个key，再删除最前面的key
  let keys = this.map.keys();
  while(this.map.size > this.capacity) {
    this.map.delete(keys.next().value);
  }
};


// 双向链表实现
function  DLinkedNode  () {
  this.key = null;
  this.value = null;
  this.prev = null
  this.next = null;
}

var LRUCache = function(capacity) {
  this.cache = new Map ();
  this.size = 0;
  this.capacity = capacity;

  this.head = new DLinkedNode ();
  this.tail = new DLinkedNode ();

  this.head.next = this.tail;
  this.tail.prev = this.head;
};

LRUCache.prototype.get = function(key) {
  let node =  this.cache.get(key);
  if (!node) return -1;

  this.moveToHead (node);
  return node.value;
};

LRUCache.prototype.put = function(key, value) {
  let node = this.cache.get(key);
  if (!node) {
    let newNode = new DLinkedNode ();
    newNode.key = key;
    newNode.value = value;

    this.cache.set (key, newNode );
    this.addNode(newNode);
    this.size ++ ;

    if (this.size > this.capacity ) {
        let tailNode = this.popTail();
        this.cache.delete(tailNode.key);
        this.size -- ;
    };
  } else {
    node.value = value;
    this.moveToHead (node);
  };
};


LRUCache.prototype.addNode = function( node ) {
    node.prev = this.head;
    node.next = this.head.next;

    this.head.next.prev = node;
    this.head.next = node;
}

LRUCache.prototype.removeNode = function( node ) {
    node.prev.next = node.next;
    node.next.prev = node.prev;
}

LRUCache.prototype.moveToHead = function( node ) {
    this.removeNode (node);
    this.addNode (node);
}

LRUCache.prototype.popTail = function( node ) {
    let res = this.tail.prev;
    this.removeNode (res);
    return res;
}