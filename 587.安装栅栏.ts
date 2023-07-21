// https://leetcode.cn/problems/erect-the-fence/

function outerTrees(trees: number[][]): number[][] {
  const n: number = trees.length
  if (n < 4) {
    return trees
  }

  let leftMost: number = 0
  for (let i = 0; i < n; i++) {
    if (trees[i][0] < trees[leftMost][0] || (trees[i][0] === trees[leftMost][0] && trees[i][1] < trees[leftMost][1])) {
      leftMost = i
    }
  }

  const res: number[][] = []
  const visited = new Array(n).fill(0)
  let p = leftMost
  do {
    let q = (p + 1) % n
    for (let r = 0; r < n; r++) {
      // 如果r 在pq 的右侧，则q = r
      if (cross(trees[p], trees[q], trees[r]) < 0) {
        q = r
      }
    }
    // 是否存在点i，使得p q i 在同一条直线上
    for (let i = 0; i < n; i++) {
      if (visited[i] || i === p || i === q) {
        continue
      }
      if (cross(trees[p], trees[q], trees[i]) === 0) {
        res.push(trees[i])
        visited[i] = true
      }
    }
    if (!visited[q]) {
      res.push(trees[q])
      visited[q] = true
    }
    p = q
  } while (p !== leftMost)
  return res
};


const cross = (p: number[], q: number[], r: number[]) => {
  return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0])
}

