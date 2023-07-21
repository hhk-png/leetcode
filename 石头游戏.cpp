#include<iostream>
#include<vector>
using namespace std;

// �Զ���һ��Ԫ��
class Pair {
	int fir, sec;
	Pair(int fir, int sec) {
		this->fir = fir;
		this->sec = sec;
	}
};

int stoneGame(int piles[]) {
	// ʯ�Ӷ���
	int n = piles.size();

	// ��ʼ��dp���飬Ӧ�ò���
	vector<vector<Pair>> dp(n, vector<Pair>(n));

	// �������ڵ�Ԫ�ؽ��г�ʼ��
	// б�ű���
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			dp[i][j] = new Pair(0, 0);
	
	// ��ʼ���Խ����ϵ�����
	for (int i = 0; i < n; i++) {
		dp[i][i].fir = piles[i];
		dp[i][i].sec = 0;
	}

	// l�����ȣ�i����߽磬j���ұ߽�
	for (int l = 2; l <= n; l++) {
		for (int i = 0; i <= n - l; i++) {
			// ��l��i������ұ߽�
			int j = n - i + 1;

			// ����ѡ����������õķ���
			// �������ѡ������ߣ���ô����[i, j]��˵���Ǻ���ѡ���ұߵ�ʯ��
			int left = piles[i] + dp[i + 1][j].sec;
			// ����ѡ�����ұ�
			int right = piles[j] + dp[i][j - 1].sec;

			// �Ƚϴ�С��
			if (left > right) {
				// ˵��[i, j]����������ߵ��������
				dp[i][j].fir = left;
				// ����Ǻ��֣���ô�����������һ���������
				dp[i][j].sec = dp[i + 1][j].fir;
			} else {
				dp[i][j].fir = right;
				dp[i][j].sec = dp[i][j - 1].fir;
			}
		}
	}

	// ������ս����Ԫ��
	Pair res = dp[0][n - 1];

	return res.fir - res.sec;
}