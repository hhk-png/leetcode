// https://leetcode.cn/problems/maximum-length-of-pair-chain/submissions/

var findLongestChain = function (pairs: number[][]) {
  let curr = -Number.MAX_VALUE, res = 0;
  pairs.sort((a, b) => a[1] - b[1]);
  for (const p of pairs) {
    if (curr < p[0]) {
      curr = p[1];
      res++;
    }
  }
  return res;
}



function findLongestChain2(pairs: number[][]): number {
  // 按照第二个数字排序
  pairs.sort((a, b) => a[1] - b[1])
  const stack: number[][] = []
  stack.push(pairs[0])

  let res: number = 0
  for (let i = 1; i < pairs.length; i++) {
    const left = stack[stack.length - 1][1]
    const right = pairs[i][0]
    if (left >= right) {
      continue
    }
    stack.push(pairs[i])
  }
  return stack.length
};


