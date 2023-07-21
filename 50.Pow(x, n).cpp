// 实现 pow(x, n) ，即计算 x 的 n 次幂函数。

// 递归
class Solution {
public:
	/* 递归函数 */
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
		if (N < 0) { // n 为负数时的情况
			x = 1 / x;
			N = -N;
		}
		return fastPow(x, N);
	}
};


// 快速幂算法
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

