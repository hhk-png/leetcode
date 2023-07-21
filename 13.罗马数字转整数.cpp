class Solution {
public:
	int romanToInt(string s) {
		map<char, int> m = {
			{'I',1},
			{'V',5},
			{'X',10},
			{'L',50},
			{'C',100},
			{'D', 500},
			{'M', 1000}
		};//��ʼ����ϣ��

		// �洢���
		int sum = 0;
		// ǰһ����������ڱȽ�
		int preNum = m[s[0]];
		// �ַ�������
		int len = s.length();
		for (int i = 1; i < len; i++) {
			// ��ǰ��ĸ
			int num = m[s[i]];
			if (preNum < num) { // ���ǰһ������С�ں�һ�������
				sum -= preNum;
			}
			else { // �����
				sum += preNum;
			}
			preNum = num; // �滻preNum
		}

		sum += preNum; // �������Ľ��
		return sum; // ����

	}
};