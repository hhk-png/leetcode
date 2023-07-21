#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int d = nums[0] - nums[1];
        int result = 0;
        int time = 0;
        for (int i = 2; i < n; i++) {
            int temp = nums[i - 1] - nums[i];
            if (temp == d) {
                time++;
            } else {
                d = temp;
                time = 0;
            }
            result += time;
        }

        return result;
    }
};