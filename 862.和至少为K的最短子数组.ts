// https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/

function shortestSubarray(nums: number[], k: number): number {
  const n: number = nums.length;
  const preSumArr: number[] = new Array(n + 1).fill(0);
  for (let i = 0; i < n; i++) {
    preSumArr[i + 1] = preSumArr[i] + nums[i];
  }
  let res: number = n + 1;
  const queue: number[] = [];
  for (let i = 0; i <= n; i++) {
    const curSum: number = preSumArr[i];
    // 当前的presum 减掉队列头部的presum 大于等于k，则更新res，res 的值通过 i - queue[0] 来计算
    while (queue.length != 0 && curSum - preSumArr[queue[0]] >= k) {
      res = Math.min(res, i - queue.shift()!);
    }
    // 如果当前的presum 小于等于队列尾部的presum，则将队列尾部的i 出队
    //  因为后面的presum 减去前面的一定小于等于0
    while (queue.length != 0 && preSumArr[queue[queue.length - 1]] >= curSum) {
      queue.pop();
    }
    queue.push(i);
  }
  // 如果res 的值没有被更新过，则返回-1
  return res < n + 1 ? res : -1;
}

