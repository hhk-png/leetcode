// test
const result = KMPSearch("SJDGWQIODDHWQOID", "ABC");
console.log(result);

// next[j]，即是在P(0, j)中，最大子匹配的真前缀和真后缀的长度

console.log(buildNext('bccabcaac'))

function buildNext(p) {
  let plen = p.length;
  let k = -1; // 可以用于记录自匹配中已经完全匹配的字符串个数
              // 哨兵：当首个字符失配时，重置后指针所在的位置
  let next = [];
  next[0] = -1;

  // 进行自匹配，
  let j = 0;
  while (j < plen - 1) {
    // 当首字符失配，重新开始匹配过程
    // 字符匹配成功，记录k，并进行下一个字符的匹配
    if (k < 0 || p[k] === p[j]) {
      k++;
      j++;
      next[j] = k;
    // next[j+1] <= next[j] + 1
    // 非首字符匹配失败
    } else {
      k = next[k];
    }
  }

  return next;
}
// 主算法
// 如果在位置j失配，就寻找位置j-1上的字符在整个字符串中第一次出现的位置j'，j'+1就是next[j]的值
// 如果在位置i(j)失配，说明j位置之前的p的前缀就已经完全匹配了
function KMPSearch(s, p) {
  let next = buildNext(p);
  let i = 0; // s的指针
  let j = 0; // p的指针
  let pLen = p.length;
  let sLen = s.length;
  // 主串结构
  // 前缀 - 匹配字符串 - 失配字符 - 后缀

  // 寻找第一个子串匹配的位置
  while (j < pLen && i < sLen) {
    // j可能是哨兵索引
    // 匹配成功一对字符
    if (j < 0 || s[i] === p[j]) {
      i++;
      j++;
    } else {
      // p[j]匹配失败时，到位置next[j]去
      // 相当于p字串向后移动j - next[j]个距离
      // t=next[j]
      // t越大，位移越小，t越小，位移越大
      // 位移量更小，意味着某种意义上的更加安全，避免回溯
      j = next[j];
    }
  }
  // 如果匹配成功
  // j的大小等于pLen的长度说明，字符串完全匹配
  // 此时i是s的指针走到的位置，j==p.length
  return j === pLen ? (i - j) : -1;
}
