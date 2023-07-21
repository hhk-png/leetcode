#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

/* https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/

给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤ j < n 。

示例 1：
输入：nums = [3,10,5,25,2,8]
输出：28
解释：最大运算结果是 5 XOR 25 = 28.

示例 2：
输入：nums = [14,70,53,83,49,91,36,80,92,51,66,70]
输出：127

*/

struct Trie {
    Trie* left = nullptr;
    Trie* right = nullptr;
    Trie() {}
};

class Solution2 {
public:
    Trie* root = new Trie();
    static constexpr int HIGH_BIT = 30;

    void add(int num) {
        Trie* curr = root;
        for (int i = HIGH_BIT; i >= 0; --i) {
            int bit = (num >> i) & 1;
            // 0 为左边，1 为右边
            if (bit == 0) {
                if (!curr->left) {
                    curr->left = new Trie();
                }
                curr = curr->left;
            } else {
                if (!curr->right) {
                    curr->right = new Trie();
                }
                curr = curr->right;
            }
        }
    }

    int check(int num) {
        Trie* curr = root;
        int x = 0;
        for (int i = HIGH_BIT; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (bit == 0) {
                // 最终的结果都是使相同比特位置的异或值为 1, 所以不管向左还是向右，都是2x + 1
                //      向另一边的时候为 2x
                if (curr->right) {
                    curr = curr->right;
                    x = 2 * x + 1;
                } else {
                    curr = curr->left;
                    x = 2 * x;
                }
            } else {
                if (curr->left) {
                    curr = curr->left;
                    x = 2 * x + 1;
                } else {
                    curr = curr->right;
                    x = 2 * x;
                }
            }
        }

        return x;
    }

    int findMaximumXOR(vector<int>& nums) {
        int x = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            add(nums[i - 1]);
            x = max(x, check(nums[i]))
        }

        return x;
    }
};

class Solution {
public:
    static constexpr int HIGH_BIT = 30;
    int findMaximumXOR(vector<int>& nums) {
        int x = 0;
        for (int i = HIGH_BIT; i >= 0; --i) {
            unordered_set<int> seen;
            for (int num : nums) {
                seen.insert(num >> i);
            }

            int next_x = 2 * x + 1;
            bool found = false;

            // 由 aj = x ^ ai 得
            //  pre(aj) = pre(x) ^ pre(ai)
            for (int num : nums) {
                if (seen.count(next_x ^ (num >> i))) {
                    found = true;
                    break;
                }
            }

            if (found) {
                x = next_x;
            } else {
                x = next_x - 1;
            }

        }

        return x;
    }
};
