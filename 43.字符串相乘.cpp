// ����: num1 = "123", num2 = "456"
// ��� : "56088"
// ���⣺m�ĺ���
class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1[0] == '0' || num2[0] == '0') return "0"; // ����

		int n = num1.size() + num2.size();// ������˽����λ��С����������λ��֮��
											// �����������ս����λ��
		string res(n, '0');

		for (int i = num1.size() - 1; i >= 0; i--) {

			int m = n - 1, mbit = 0, abit = 0;  //mbit�˷���λ��abit�ӷ���λ

			for (int k = num1.size() - i - 1; k > 0; k--)  //��֤��λ���
				m--; 

			for (int j = num2.size() - 1; j >= 0; j--, m--) {
				// �����������
				int multi = (num1[i] - '0')*(num2[j] - '0') + mbit;
				// �����Ľ�λ
				mbit = multi / 10;
				// �����ĸ�λ + ֮ǰ�ӷ��Ľ�λ + ��ǰλ�õ����� = �µĵ�ǰλ�õ�����
				int add = res[m] - '0' + multi % 10 + abit;
				res[m] = add % 10 + '0';
				// �������ļӷ���λ
				abit = add / 10;
			}

			// num1��num2��һ��������˺����β����
			if (mbit)
				res[m] += mbit;
			if (abit)
				res[m] += abit;
		}

		// ����
		for (int i = 0; i < res.size(); i++)
			if (res[i] != '0')
				return res.substr(i);
		return "";
	}
};