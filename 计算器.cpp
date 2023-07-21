#include<string>
#include<stack>
#include<algorithm>
using namespace std;
// 还剩余括号的处理

int calculate(string s) {
	stack<int> stk;
	// 记录算式中的数字
	int num = 0;
	// 记录num前的符号，初始化为 +
	char sign = '+';

	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		// 如果是数字，就读取到num
		if (isdigit(c)) {
			num = 10*num + (c - '0'）
		}

		// 如果不是数字，就是遇到了下一个符号
		// 之前的数字和符号就要存进栈中
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