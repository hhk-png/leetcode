vector<vector<string>> res;

/* �������̱߳� n���������кϷ��ķ��� */
vector<vector<string>> solveNQueens(int n) {
	// '.' ��ʾ�գ�'Q' ��ʾ�ʺ󣬳�ʼ�������̡�
	vector<string> board(n, string(n, '.'));
	backtrack(board, 0);
	return res;
}

// ·����board ��С�� row ����Щ�ж��Ѿ��ɹ������˻ʺ�
// ѡ���б��� row �е������ж��Ƿ��ûʺ��ѡ��
// ����������row ���� board �����һ��
void backtrack(vector<string>& board, int row) {
	// ������������
	if (row == board.size()) {
		res.push_back(board);
		return;
	}

	int n = board[row].size();
	for (int col = 0; col < n; col++) {
		// �ų����Ϸ�ѡ��
		if (!isValid(board, row, col))
			continue;
		// ��ѡ��
		board[row][col] = 'Q';
		// ������һ�о���
		backtrack(board, row + 1);
		// ����ѡ��
		board[row][col] = '.';
	}
}

/* �Ƿ������ board[row][col] ���ûʺ� */
bool isValid(vector<string>& board, int row, int col) {
	int n = board.size();
	// ������Ƿ��лʺ����ͻ
	for (int i = 0; i < n; i++) {
		if (board[i][col] == 'Q')
			return false;
	}
	// ������Ϸ��Ƿ��лʺ����ͻ
	for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
		if (board[i][j] == 'Q')
			return false;
	}
	// ������Ϸ��Ƿ��лʺ����ͻ
	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j] == 'Q')
			return false;
	}
	return true;
}
