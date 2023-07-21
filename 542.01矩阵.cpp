#include<iostream>
#include<vector>
#include<queue>

// https://leetcode.cn/problems/01-matrix/submissions/

using namespace std;
class Solution {
private:
    static constexpr int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<int>> seen(m, vector<int>(n));
        queue<pair<int, int>> que;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    que.emplace(i, j);
                    // 0 �����Ϊ��������������û�����Ķ���1
                    seen[i][j] = 1;
                }
            }
        }

        while (!que.empty()) {
            auto [i, j] = que.front();
            que.pop();
            for (int d = 0; d < 4; d++) {
                int indexI = i + dirs[d][0];
                int indexJ = j + dirs[d][1];
                if (indexI >= 0 && indexI < m && indexJ >= 0 && indexJ < n && !seen[indexI][indexJ]) {
                    dist[indexI][indexJ] = dist[i][j] + 1;
                    seen[indexI][indexJ] = 1;
                    que.emplace(indexI, indexJ);
                }
            }
        }

        return dist;
    }
};

class Solution2 {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // ��ʼ����̬�滮�����飬���еľ���ֵ������Ϊһ���ܴ����
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX / 2));
        // ��� (i, j) ��Ԫ��Ϊ 0����ô����Ϊ 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                }
            }
        }

        // �ֱ�����ϣ����ϣ����£������ĸ��������ŶԽ����ƶ�

        // ֻ�� ˮƽ�����ƶ� �� ��ֱ�����ƶ���ע�⶯̬�滮�ļ���˳��
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i - 1 >= 0) {
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                }
                if (j - 1 >= 0) {
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }
        // ֻ�� ˮƽ�����ƶ� �� ��ֱ�����ƶ���ע�⶯̬�滮�ļ���˳��
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (i + 1 < m) {
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                }
                if (j - 1 >= 0) {
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }
        // ֻ�� ˮƽ�����ƶ� �� ��ֱ�����ƶ���ע�⶯̬�滮�ļ���˳��
        for (int i = 0; i < m; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i - 1 >= 0) {
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                }
                if (j + 1 < n) {
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
                }
            }
        }
        // ֻ�� ˮƽ�����ƶ� �� ��ֱ�����ƶ���ע�⶯̬�滮�ļ���˳��
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i + 1 < m) {
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                }
                if (j + 1 < n) {
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
                }
            }
        }
        return dist;
    }
};


