// https://leetcode.cn/problems/reveal-cards-in-increasing-order/

function deckRevealedIncreasing(deck: number[]): number[] {
  const n: number = deck.length
  const index: number[] = new Array(n).fill(0).map((val, index) => index)

  const res: number[] = new Array(n).fill(0)
  deck.sort((a, b) => a - b)
  for (const card of deck) {
    res[index.shift()!] = card
    if (index.length !== 0) {
      index.push(index.shift()!)
    }
  }
  return res
};

