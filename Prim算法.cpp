#include<iostream>
#include<vector>
using namespace std;

int Prim(vector<vector<int>> map, int n) {
	vector<int> visited(n);
	vector<int> low(n, INT_MAX);
	int result = 0;
	// ѡ�г�ʼ���Ϊ0��Ȼ�����low����
	int pos = 0;
	for (int i = 1; i < n; i++) {
		low[i] = map[pos][i];
	}

	for (int i = 1; i < n; i++) {
		// ��low�������ҳ���Сֵ������¼��Сֵ���ڵĵ�
		int minV = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (!visited[i] && minV > low[i]) {
				minV = low[i];
				pos = i;
			}
		}

		// ����Ȩ��
		result += minV;
		// ����Ѿ����ʹ�
		visited[pos] = 1;

		// ���µ�posΪ������low�����ֵ
		for (int i = 0; i < n; i++) {
			if (!visited[i] && low[i] > map[pos][i])
				low[i] = map[pos][i];
		}

		return result;
	}
}

