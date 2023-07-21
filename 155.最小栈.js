
/*
    设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

    push(x) —— 将元素 x 推入栈中。
    pop() —— 删除栈顶的元素。
    top() —— 获取栈顶元素。
    getMin() —— 检索栈中的最小元素。
*/

/**
 * initialize your data structure here.
 */
var MinStack = function() {
  this.stack = [];
  // 维护一个最小值
  this.min = Infinity;
};

/** 
* @param {number} x
* @return {void}
*/
MinStack.prototype.push = function(x) {
  this.stack.push(x);
  // update this.min
  if(x < this.min) this.min = x;
  // this.min = Math.min(...this.stack);
};


// pop和top都需要判断stack是否为空
/**
* @return {void}
*/
MinStack.prototype.pop = function() {
  if(this.stack.length === 0) {
    return 0;
  }
  let s = this.stack.pop();
  if(this.min === s)
    this.min = Math.min(...this.stack);
};

/**
* @return {number}
*/
MinStack.prototype.top = function() {
  let len = this.stack.length;
  if(len === 0) return 0;
  return this.stack[len-1];
};

/**
* @return {number}
*/
MinStack.prototype.getMin = function() {
  return this.min;
};