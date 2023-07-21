#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

/*

    https://leetcode.cn/problems/circular-array-loop/

*/
// �޷�ʹ�ù�ϣ��Ľ������
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        auto next = [&](int cur) {
            return ((cur + nums[cur]) % n + n) % n;
        };

        // ����ָ��
        for (int i = 0; i < n; i++) {
            int slow = i;
            int fast = next(slow);
            // ʹ�ó˷���֤���еķ���һ��
            while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0) {
                // ˵�������˻�
                if (slow == fast) {
                    // ����ԭ��תȦ�����
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
            // ˵����ǰ���������в��ǻ�������;��Ԫ�ر��Ϊ0
            int add = i;
            while (nums[add] * nums[next(add)]) {
                nums[add] = 0;
                add = next(add);
            }
        }

        return false;
    }
};
