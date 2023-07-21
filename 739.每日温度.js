/* 
  根据每日 气温 列表，请重新生成一个列表，对应位置的输出是需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。

  例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

  提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。

*/


var dailyTemperatures = function(T) {
  // 存放结果
  let ans = new Array(T.length).fill(0),
      // 存放温度值T[i]在T中的索引
      next = new Array(101).fill(Infinity);
  // 倒序遍历，无法正序
  for (let i = T.length - 1; i >= 0; i--) {
    // 初始化为Infinity
    let warmer_index = Infinity;
    // 遍历温度值
    for (let t = T[i] + 1; t <= 100; t++) {
      // next[t]只要存在，就会进行第一次更新
      // 之后的更新是为了寻找最小值
      if (next[t] < warmer_index) {
        warmer_index = next[t];
      }
    }

    // 说明warmer_index进行了更新
    if (warmer_index < Infinity) {
      // 就存入ans
      ans[i] = warmer_index - i;
    }

    // 存入本次的索引
    next[T[i]] = i;
  }

  // 返回
  return ans;
};


