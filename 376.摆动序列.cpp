#include<iostream>
#include<vector>

using namespace std;

// https://leetcode.cn/problems/wiggle-subsequence/

class Solution1 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }

        vector<int> up(n);  
        vector<int> down(n);
        up[0] = down[0] = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                up[i] = up[i - 1];
                down[i] = max(down[i - 1], up[i - 1] + 1);
            } else if (nums[i - 1] < nums[i]) {
                down[i] = down[i - 1];
                up[i] = max(up[i - 1], down[i - 1] + 1);
            } else {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }

        return max(up[n - 1], down[n - 1]);
    }
};

class Solution2 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }

        int up = 1;
        int down = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                up = down + 1;
            } else if (nums[i - 1] > nums[i]) {
                down = up + 1;
            }
        }

        return max(down, up);
    }
};

// Ì°ÐÄ
class Solution3 {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }

        int prevdiff = nums[1] - nums[0];
        int ret = prevdiff == 0 ? 1 : 2;
        for (int i = 2; i < n; i++) {
            int diff = nums[i] - nums[i - 1];
            if ((diff < 0 && prevdiff >= 0) || (diff > 0 && prevdiff <= 0)) {
                ret++;
                prevdiff = diff;
            }
        }

        return ret;
    }
};
