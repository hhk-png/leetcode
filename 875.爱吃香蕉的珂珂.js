/*
珂珂喜欢吃香蕉。这里有 N 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 H 小时后回来。

珂珂可以决定她吃香蕉的速度 K （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 K 根。如果这堆香蕉少于 K 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  

珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。

返回她可以在 H 小时内吃掉所有香蕉的最小速度 K（K 为整数）。

 

示例 1：
输入: piles = [3,6,7,11], H = 8
输出: 4

示例 2：
输入: piles = [30,11,23,4,20], H = 5
输出: 30

示例 3：
输入: piles = [30,11,23,4,20], H = 6
输出: 23
*/

// 只要speed从1开始穷举到max(piles)，一旦发现某个值可以在H小时内吃完所有香蕉，这个值就是最小速度
// speed取值范围为[1, max(piles)]，可以使用二分查找
var minEatingSpeed = function(piles, H) {
  let left = 1; // 速度最小为1
  let right = Math.max(...piles) + 1; // 查找区间为[1, max(piles))，所以需要加1

  while (left < right) {
    // 防止溢出
    let mid = left + Math.floor((right - left) / 2);
    // 如果可以完成那么就搜索左侧区间，[left, mid)
    if (canFinish(piles, mid, H)) {
      right = mid;
      // 没有完成，[mid + 1, right)
    } else {
      left = mid + 1;
    }
  }

  // 返回最小速度
  return left;
}

// 通过吃香蕉的总次数判断是否能够吃完香蕉
function canFinish(piles, speed, H) {
  let time = 0; // 初始为0
  for (let pile of piles) {
    time += timeOf(pile, speed); //也可以把函数替换成 Math.floor((pile - 1)/speed) + 1
    
  }
  // 吃香蕉的次数小于H，说明可以吃完
  return time <= H;
}

// 计算的是以速度speed吃一堆香蕉所用的时间
function timeOf(n, speed) {
  return Math.floor(n / speed) + ((n % speed > 0) ? 1 : 0);
}