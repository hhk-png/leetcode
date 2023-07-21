/*
实现RandomizedSet 类：

  RandomizedSet() 初始化 RandomizedSet 对象
  bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
  bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
  int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
  你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。

 

示例：

  输入
    ["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
    [[], [1], [2], [2], [], [1], [2], []]
  输出
    [null, true, false, true, 2, true, false, 2]

解释
  RandomizedSet randomizedSet = new RandomizedSet();
  randomizedSet.insert(1); // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
  randomizedSet.remove(2); // 返回 false ，表示集合中不存在 2 。
  randomizedSet.insert(2); // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
  randomizedSet.getRandom(); // getRandom 应随机返回 1 或 2 。
  randomizedSet.remove(1); // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
  randomizedSet.insert(2); // 2 已在集合中，所以返回 false 。
  randomizedSet.getRandom(); // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。

*/


var RandomizedSet = function() {
  this.hash = new Map();
  this.list = [];
};

/** 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.insert = function(val) {
  if (this.hash.has(val)) return false;
  
  this.hash.set(val, this.list.length);
  this.list.push(val);
  return true;
};

/** 
 * @param {number} val
 * @return {boolean}
 */
RandomizedSet.prototype.remove = function(val) {
  if (!this.hash.has(val)) return false;

  // 将要删除的元素与最后一个元素交换，删除最后一个元素，这样就能达到O(1)的复杂度
  //    之后再更新 list 和 hash 中的值
  let index = this.hash.get(val);
  let lastEle = this.list[this.list.length - 1];
  this.hash.set(lastEle, index);
  this.hash.delete(val);
  this.swap(index, this.list.length - 1);
  this.list.pop();
  return true;
};

/**
 * @return {number}
 */
RandomizedSet.prototype.getRandom = function() {
  let index = this.list.length * Math.random();
  return this.list[Math.floor(index)];
};

RandomizedSet.prototype.swap = function(i, j) {
  let temp = this.list[i];
  this.list[i] = this.list[j];
  this.list[j] = temp;
}