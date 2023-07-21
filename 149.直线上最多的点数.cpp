#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


class Solution {
public:
	int gcd(int a, int b) {
		return b ? gcd(b, a % b) : a;
	}

	int maxPoints(vector<vector<int>>& points) {
		int n = points.size();
		if (n <= 2) {
			return n;
		}

		int res = 0;
		for (int i = 0; i < n; i++) {
			if (res > n / 2 || res > n - i) {
				return res;
			}

			unordered_map<int, int> map;
			for (int j = i + 1; j < n; j++) {
				int x = points[i][0] - points[j][0];
				int y = points[i][1] - points[j][1];
				if (y == 0) {
					x = 1;
				} else if (x == 0) {
					y = 1;
				} else {
					if (y < 0) {
						x = -x;
						y = -y;
					} 
					int gcdxy = gcd(abs(x), abs(y));
					x /= gcdxy;
					y /= gcdxy
				}
				map[my + 20001 * mx]++;
			}
			for (auto&[_, num] : map) {
				res = max(res, num + 1);
			}
		}

		return res;
	}
};
