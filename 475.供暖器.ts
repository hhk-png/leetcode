// https://leetcode.cn/problems/heaters/

function findRadius(houses: number[], heaters: number[]): number {
  houses.sort((a, b) => a - b)
  heaters.sort((a, b) => a - b)
  let j = 0
  let res: number = 0
  for (let i = 0; i < houses.length; i++) {
    let currDis = Math.abs(houses[i] - heaters[j])
    while (
      j < heaters.length - 1 &&
      (Math.abs(houses[i] - heaters[j]) >= Math.abs(houses[i] - heaters[j + 1]))
    ) {
      j++
      currDis = Math.min(currDis, Math.abs(houses[i] - heaters[j]))
    }
    res = Math.max(res, currDis)
  }
  return res
};

function findRadius2(houses: number[], heaters: number[]): number {
  heaters.sort((a, b) => a - b)
  let res: number = 0
  for (const house of houses) {
    const i: number = binarySearch(heaters, house)
    const j: number = i + 1
    const leftDis = i >= 0 ? Math.abs(house - heaters[i]) : Number.MAX_VALUE
    const rightDis = j < heaters.length ? Math.abs(house - heaters[j]) : Number.MAX_VALUE
    const currDis = Math.min(leftDis, rightDis)
    res = Math.max(res, currDis)
  }
  return res
}

const binarySearch = (nums: number[], target: number) => {
  let left: number = 0
  let right: number = nums.length - 1
  if (target < nums[0]) {
    return -1
  }
  while (left < right) {
    const mid: number = Math.floor((right - left + 1) / 2) + left;
    if (target < nums[mid]) {
      right = mid - 1
    } else {
      left = mid
    }
  }
  return left
}


// class Solution {
//   public int findRadius(int[] houses, int[] heaters) {
//       int ans=0;
//       int d=(int)2e9;
//       Arrays.sort(houses);
//       Arrays.sort(heaters);
//       int j=0;
//       for(int i=0;i<houses.length;i++){
//           while(j<heaters.length&&heaters[j]<houses[i]){j++;}
//           if(j==0){d=heaters[0]-houses[i];}
//           else if(j==heaters.length){d=houses[i]-heaters[j-1];}
//           else{d=Math.min(heaters[j]-houses[i],houses[i]-heaters[j-1]);}
//           ans=Math.max(ans,d);
//       }
//       return ans;
//   }
// }
