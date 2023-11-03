function reversePairs(nums: number[]): number {
  const countPairs = (left: number, right: number) => {
    if (left === right) {
      return 0;
    } else {
      const mid = Math.floor((left + right) / 2);
      const countLeft = countPairs(left, mid);
      const countRight = countPairs(mid + 1, right);
      let totalCount = countLeft + countRight;

      let j = mid + 1;
      for (let i = left; i <= mid; i++) {
        while (j <= right && nums[i] > 2 * nums[j]) {
          j++;
        }
        totalCount += j - mid - 1;
      }

      // 归并
      const sorted = new Array(right - left + 1);
      let p1 = left, p2 = mid + 1;
      let p = 0;
      while (p1 <= mid || p2 <= right) {
        if (p1 > mid) {
          sorted[p] = nums[p2++];
        } else if (p2 > right) {
          sorted[p] = nums[p1++];
        } else {
          if (nums[p1] < nums[p2]) {
            sorted[p] = nums[p1++];
          } else {
            sorted[p] = nums[p2++];
          }
        }
        p++;
      }
      for (let k = 0; k < sorted.length; k++) {
        nums[left + k] = sorted[k];
      }
      return totalCount;
    }
  }

  if (nums.length === 0) {
    return 0;
  }
  return countPairs(0, nums.length - 1);
};


