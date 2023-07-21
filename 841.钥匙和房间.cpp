/*
�� N �����䣬��ʼʱ��λ�� 0 �ŷ��䡣
	ÿ�������в�ͬ�ĺ��룺0��1��2��...��N-1�����ҷ����������һЩԿ����ʹ�������һ�����䡣

����ʽ�ϣ�����ÿ������ i ����һ��Կ���б� rooms[i]��
	ÿ��Կ�� rooms[i][j] �� [0,1��...��N-1] �е�һ��������ʾ��
	���� N = rooms.length�� Կ�� rooms[i][j] = v ���Դ򿪱��Ϊ v �ķ��䡣

������� 0 �ŷ�������������з��䶼����ס��

��������ɵ��ڷ���֮�������߶���

����ܽ���ÿ�����䷵�� true�����򷵻� false��

ʾ�� 1��
	����: [[1],[2],[3],[]]
	���: true
	����:
		���Ǵ� 0 �ŷ��俪ʼ���õ�Կ�� 1��
		֮������ȥ 1 �ŷ��䣬�õ�Կ�� 2��
		Ȼ������ȥ 2 �ŷ��䣬�õ�Կ�� 3��
		�������ȥ�� 3 �ŷ��䡣
		���������ܹ�����ÿ�����䣬���Ƿ��� true��

ʾ�� 2��
	���룺[[1,3],[3,0,1],[2],[0]]
	�����false
	���ͣ����ǲ��ܽ��� 2 �ŷ��䡣
*/

class Solution {
private:
	vector<bool> canGo;
	int num;
public:
	void goRoom(int roomNum, vector<vector<int>>& rooms) {
		canGo[roomNum] = true;
		num++;
		for (auto neibor : rooms[roomNum]) {
			if (!canGo[neibor])
				goRoom(neibor, rooms);
		}
	}
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		int n = rooms.size();
		num = 0;
		canGo.assign(n, false);
		goRoom(0, rooms);

		return num == n;
	}
};