#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		unordered_map<int, int> countAB;
		for (int u : A) {
			for (int v : B) {
				++countAB[u + v];
			}
		}

		int res = 0;
		for (int u : C) {
			for (int v : D) {
				int ans = countAB[-u - v];
				if (ans) {
					res += ans;
				}
			}
		}

		return res;
	}
};
