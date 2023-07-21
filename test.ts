function twoSum(nums: number[], target: number): number[] {
  const map = new Map();

  for (let i = 0; i < nums.length; i++) {
    const n: number = target - nums[i];
    const hasKey: number = map.get(n);
    if (hasKey) {
      return [i, hasKey];
    }
    map.set(nums[i], i);
  }

  return [];
}

twoSum([2, 7, 11, 15], 9);
