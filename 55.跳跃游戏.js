// 给定一个非负整数数组，你最初位于数组的第一个位置。

// 数组中的每个元素代表你在该位置可以跳跃的最大长度。

// 判断你是否能够到达最后一个位置。

var jump = function(nums) {
	let maxPosition = 0;
	for (let i = 0; i < nums.length; i++) {
    // 如果i > maxPosition
    // 不能跳出循环
		if (i > maxPosition) return false;
		maxPosition = Math.max(maxPosition, i + nums[i]);
	}
	return true;

};