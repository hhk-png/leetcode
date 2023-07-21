/**
 * 也可以使用二分查找，二分查找的对象是前缀长度
 */

var longestCommonPrefix = function(strs){
  if (strs.length == 0) return "";
  if (strs.length == 1) return strs[0];

  let res = strs[0];
  for (let i = 1; i < strs.length; i++) {
      const count = Math.min(res.length, strs[i].length);
      let index = 0;
      while(index < count && res[index] == strs[i][index]) {
        index++;
      }
      res = res.substr(0, index);
  }

  return res;
};