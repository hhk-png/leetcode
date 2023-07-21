// ʵ�� pow(x, n) �������� x �� n ���ݺ�����

// �ݹ�
class Solution {
public:
	/* �ݹ麯�� */
	double fastPow(double x, long long n) {
		if (n == 0) {
			return 1.0;
		}
		double half = fastPow(x, n / 2);
		if (n % 2 == 0) {
			return half * half;
		}
		else {
			return half * half * x;
		}
	}
	double myPow(double x, int n) {
		long long N = n;
		if (N < 0) { // n Ϊ����ʱ�����
			x = 1 / x;
			N = -N;
		}
		return fastPow(x, N);
	}
};


// �������㷨
class Solution {
public:
	double myPow(double x, int n) {
		long long N = n;
		if (N < 0) {
			x = 1 / x;
			N = -N;
		}
		double ans = 1;
		double current_product = x;
		for (long long i = N; i; i /= 2) {
			if ((i % 2) == 1) {
				ans = ans * current_product;
			}
			current_product = current_product * current_product;
		}
		return ans;
	}
};

