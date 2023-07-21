// 双指针法
var maxArea = function (height) {
  let left = 0;
  let right = height.length - 1;
  // 保存最大面积
  let max = 0;
  while (left < right) {
    // 这里需要每一次循环的时候计算对应面积,
    maxArea = Math.max(
      maxArea,
      Math.min(height[left], height[right]) * (right - left)
    );
    if (height[left] < height[right]) {
      left++;
    } else {
      right--;
    }
  }
  return maxArea;
};

/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};
*/
