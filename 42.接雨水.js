/*
  给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

  示例:
  输入: [0,1,0,2,1,0,1,3,2,1,2,1]
  输出: 6
*/
// C:/Users/郝洪坤/Desktop/素材/图片/rainwatertrap.png

// 能够接到雨水的面积是采用累加的方式计算的，而不是面积公式
//      计算面积的时候我们的第一反应通常是采用公式计算，但计算机的世界却与我们的常识不相同

var trap = function(height) {
    let right = height.length-1; // 右指针
    let left = 0; // 左指针
    let left_max = 0; // [0, left]的最大值
    let right_max = 0;  // [right, height.length-1]的最大值
    // 存储结果
    let ans = 0;
    while(left < right){
        if (height[left] < height[right]){
            height[left] >= left_max 
              ? left_max = height[left] 
              : (ans += left_max - height[left]);
            left++;
        }else{
            height[right] >= right_max 
              ? right_max = height[right] 
              : (ans += right_max - height[right]);
            right--;
        }
    }
    return ans;
};