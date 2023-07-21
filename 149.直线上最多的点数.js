/*
  给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点。求最多有多少个点在同一条直线上。
  示例 1：  
    输入：points = [[1,1],[2,2],[3,3]]
    输出：3

  示例 2：
    输入：points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
    输出：4

  https://leetcode-cn.com/problems/max-points-on-a-line/solution/zhi-xian-shang-zui-duo-de-dian-shu-by-le-tq8f/
  */

const maxPoints = function (points) {
  const n = points.length;
  // 在点的总数量小于等于2的情况下，我们可以用一条直线将所有的点串联，
  //    此时我们直接返回点的总数量即可
  if (n <= 2) {
    return n;
  }
  let res = 0;
  for (let i = 0; i < n; i++) {
    // 当我们找到一条直线经过了图中超过半数的点时，我们即可以确定该直线即为经过最多点的直线
    // 当我们枚举到点i时，我们之多只能找到n - i 个点共线，假设此前找到的共线的点的数量的最大值为k
    //    如果有 k >= n - i ，那么此时我么即可停止枚举，因为不可能再找到更大的答案了
    if (res >= n - i || res > n / 2) {
      break;
    }
    const map = new Map();
    // 当我们枚举到点 i 时，我们只需要考虑编号大于i的点到点i的斜率，因为如果同时经过编号小于点 i 的点 j，
    //    那么当我们枚举到j时就已经考虑过该直线了
    for (let j = i + 1; j < n; j++) {
      let x = points[i][0] - points[j][0];
      let y = points[i][1] - points[j][1];
      if (y === 0) {
        x = 1;
      } else if (x === 0) {
        y = 1;
      } else {
        if (y < 0) {
          x = -x;
          y = -y;
        }
        let gcdxy = gcd(Math.abs(x), Math.abs(y));
        x /= gcdxy;
        y /= gcdxy;
      }
      // 浮点类型可能因为精度不够而无法足够精确的表示每一个斜率，因此我们需要换一种方法来记录斜率
      const key = y + 20001 * x;
      map.set(key, (map.get(key) || 0) + 1);
    }
    for (const num of map.values()) {
      res = Math.max(res, num);
    }
  }

  return res;
}

const gcd = (a, b) => {
  return b ? gcd(b, a % b) : a;
}