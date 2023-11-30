// https://leetcode.cn/problems/shopping-offers/submissions/484302836/

function shoppingOffers(price: number[], special: number[][], needs: number[]): number {
  const memo: Map<string, number> = new Map();

  // 记忆化搜索计算满足购物清单所需花费的最低价格
  const dfs = (curNeeds: number[]) => {
    if (!memo.has(curNeeds.join(','))) {
      let minPrice = 0;
      for (let i = 0; i < n; ++i) {
        minPrice += curNeeds[i] * price[i]; // 不购买任何大礼包，原价购买购物清单中的所有物品
      }
      for (const curSpecial of filteredSpecial) {
        const specialPrice = curSpecial[n];
        const nextNeeds: number[] = [];
        for (let i = 0; i < n; ++i) {
          if (curSpecial[i] > curNeeds[i]) { // 不能购买超出购物清单指定数量的物品
            break;
          }
          nextNeeds.push(curNeeds[i] - curSpecial[i]);
        }
        if (nextNeeds.length === n) { // 大礼包可以购买
          minPrice = Math.min(minPrice, dfs(nextNeeds)! + specialPrice);
        }
      }
      memo.set(curNeeds.join(','), minPrice);
    }
    return memo.get(curNeeds.join(','));
  }

  const n = price.length;

  // 过滤不需要计算的大礼包，只保留需要计算的大礼包
  const filteredSpecial: number[][] = [];
  for (const sp of special) {
    let totalCount = 0, totalPrice = 0;
    for (let i = 0; i < n; ++i) {
      totalCount += sp[i];
      totalPrice += sp[i] * price[i];
    }
    if (totalCount > 0 && totalPrice > sp[n]) {
      filteredSpecial.push(sp);
    }
  }

  return dfs(needs)!;

};