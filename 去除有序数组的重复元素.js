const { SSL_OP_SSLEAY_080_CLIENT_DH_BUG } = require("constants");

var removeDuplicates = function(nums) {
  if (nums.length === 0) return 0;
  let slow = 0;
  let fast = 1;

  while (fast < nums.length) {
    if (nums[slow] !== nums[fast]) {
      slow++;
      nums[slow] = nums[fast]
    }
    fast++;
  }

  return nums;
}