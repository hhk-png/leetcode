#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

/*

    https://leetcode.cn/problems/circular-array-loop/

*/
// 无法使用哈希表的解决方法
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        auto next = [&](int cur) {
            return ((cur + nums[cur]) % n + n) % n;
        };

        // 快慢指针
        for (int i = 0; i < n; i++) {
            int slow = i;
            int fast = next(slow);
            // 使用乘法保证序列的符号一致
            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0) {
                // 说明遇到了环
                if (slow == fast) {
                    // 避免原地转圈的情况
                    if (slow != next(slow)) {
                        return true;
                    }
                    else {
                        break;
                    }
                }
                slow = next(slow);
                fast = next(next(fast));
            }
            // 说明当前经过的序列不是环，将沿途的元素标记为0
            int add = i;
            while (nums[add] * nums[next(add)]) {
                nums[add] = 0;
                add = next(add);
            }
        }

        return false;
    }
};
