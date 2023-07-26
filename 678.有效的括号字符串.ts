// https://leetcode.cn/problems/valid-parenthesis-string/submissions/

function checkValidString(s: string): boolean {
  const n: number = s.length
  let leftStack: number[] = []
  let asteriskStack: number[] = []
  for (let i = 0; i < n; i++) {
      const c = s[i]
      if (c === '(') {
          leftStack.push(i)
      } else if (c === '*') {
          asteriskStack.push(i)
      } else {
          if (leftStack.length) {
              leftStack.pop()
          } else if (asteriskStack.length) {
              asteriskStack.pop()
          } else {
              return false
          }
      }
  }
  while (leftStack.length && asteriskStack.length) {
      const index1 = leftStack.pop()!
      const index2 = asteriskStack.pop()!
      if (index1 > index2) {
          return false
      }
  }
  return leftStack.length === 0
};


function checkValidString2(s: string): boolean {
  let minCount = 0
  let maxCount = 0;
  const n = s.length;
  for (let i = 0; i < n; i++) {
      const c = s[i];
      if (c === '(') {
          minCount++;
          maxCount++;
      } else if (c === ')') {
          minCount = Math.max(minCount - 1, 0);
          maxCount--;
          if (maxCount < 0) {
              return false;
          }
      } else {
          minCount = Math.max(minCount - 1, 0);
          maxCount++;
      }
  }
  return minCount === 0;
};

