class Solution {
public:
	vector<bool> visited;
	bool dfs(int i, vector<int>& leftChild, vector<int>& rightChild) {
		if (visited[i])
			return false;//���һ�������Ѿ����ʹ���
		visited[i] = true;
		bool b1 = true;
		bool b2 = true;
		if (leftChild[i] != -1)//���Ӳ�Ϊ�����������
			b1 = dfs(leftChild[i], leftChild, rightChild);
		if (rightChild[i] != -1)//�Һ��Ӳ�Ϊ��������Һ���
			b2 = dfs(rightChild[i], leftChild, rightChild);
		return b1 && b2;
	}
	bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
		visited = vector<bool>(n, false);
		if (!dfs(0, leftChild, rightChild))//�ж����1
			return false;
		for (int i = 0; i < n; i++)//�ж����2��Ҳ������һ��dfs����û�л�û�з��ʹ��Ľڵ�
			if (!visited[i])
				return false;
		return true;
	}
};

