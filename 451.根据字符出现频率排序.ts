
/* https://leetcode.cn/problems/sort-characters-by-frequency/

给定一个字符串 s ，根据字符出现的 频率 对其进行 降序排序 。一个字符出现的 频率 是它出现在字符串中的次数。

返回 已排序的字符串 。如果有多个答案，返回其中任何一个。

 

示例 1:

输入: s = "tree"
输出: "eert"
解释: 'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
示例 2:

输入: s = "cccaaa"
输出: "cccaaa"
解释: 'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。
示例 3:

输入: s = "Aabb"
输出: "bbAa"
解释: 此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
注意'A'和'a'被认为是两种不同的字符。

*/

function frequencySort1(s: string): string {
  // 创建 [字符: 频率] 的map
  const mp:Map<string, number> = new Map();
  for (const c of s) {
    mp.set(c, (mp.get(c) || 0) + 1);
  }

  // 将map转换为数组按照频率降序排列
  const arr = Array.from(mp).sort((a:[string, number], b:[string, number]) => b[1] - a[1]);
  // 将最终的结果整合
  return arr.reduce((acc:string, val:[string, number]) => {
    return acc + val[0].repeat(val[1]);
  }, '');
};


var frequencySort = function(s:string):string {
  // 创建 [字符: 频率] 的map，并计算最大频率
  const mp:Map<string, number> = new Map();
  let maxFreq:number = 0;
  for (const c of s) {
    const freq = (mp.get(c) || 0) + 1;
    mp.set(c, freq);
    maxFreq = Math.max(maxFreq, freq);
  }

  // 依据最大频率创建桶
  const buckets = new Array(maxFreq + 1).fill(0).map(() => new Array());
  // 将字符按照频率放到桶中
  for (const [ch, num] of mp.entries()) {
    buckets[num].push(ch);
  }

  let result:string = '';
  // 按频率从大到小从 bucket 取值，并将里面的各个字符串分别重复n 次
  for (let i:number = maxFreq; i > 0; i--) {
    const bucket:Array<string> = buckets[i];
    for (const ch of bucket) {
      result += ch.repeat(i);
    }
  }
  return result;
}





