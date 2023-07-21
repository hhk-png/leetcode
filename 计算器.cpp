#include<string>
#include<stack>
#include<algorithm>
using namespace std;
// ��ʣ�����ŵĴ���

int calculate(string s) {
	stack<int> stk;
	// ��¼��ʽ�е�����
	int num = 0;
	// ��¼numǰ�ķ��ţ���ʼ��Ϊ +
	char sign = '+';

	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		// ��������֣��Ͷ�ȡ��num
		if (isdigit(c)) {
			num = 10*num + (c - '0'��
		}

		// ����������֣�������������һ������
		// ֮ǰ�����ֺͷ��ž�Ҫ���ջ��
		if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
			switch (sign) {
				int pre;
				case '+':
					stk.push(+num);
					break;
				case '-':
					stk.push(-num) :
					break;
				case '*':
					pre = stk.top();
					stk.pop();
					stk.push(pre * num);
					break;
				case '/':
					pre = stk.top();
					stk.pop();
					stk.push(pre / num);
					break;
			}
			num = 0;
			sign = c;
		}

	}

	int res = 0;
	while (!stk.empty()) {
		res += stk.top();
		stk.pop()
	}

	return res;
}