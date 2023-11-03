// https://leetcode.cn/problems/max-sum-of-rectangle-no-larger-than-k/submissions/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int res = INT_MIN;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            vector<int> sum(n);
            for (int j = i; j < m; j++) {
                for (int c = 0; c < n; c++) {
                    sum[c] += matrix[j][c];
                }

                set<int> sumSet{ 0 };
                int acc = 0;
                for (int val : sum) {
                    acc += val;
                    auto lowerBound = sumSet.lower_bound(acc - k);
                    if (lowerBound != sumSet.end()) {
                        res = max(res, acc - *lowerBound);
                    }
                    sumSet.insert(acc);
                }
            }
        }
        return res;
    }
};
