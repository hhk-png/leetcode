#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/*

给你一个二叉树的根结点 root ，请返回出现次数最多的子树元素和。
    如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。

一个结点的 「子树元素和」 定义为以该结点为根的
    二叉树上所有结点的元素之和（包括结点本身）。

*/

class Solution {
    unordered_map<int, int> cnt;
    int maxCnt = 0;

    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int sum = node->val + dfs(node->left) + dfs(node->right);
        // 通过计算 maxCnt 来统计最后要返回的数组
        maxCnt = max(maxCnt, ++cnt[sum]);
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> ans;
        for (auto& [s, c] : cnt) {
            if (c == maxCnt) {
                ans.emplace_back(s);
            }
        }
        return ans;
    }
};