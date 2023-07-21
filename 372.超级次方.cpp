#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    const int MOD = 1337;

    int pow(int x, int n) {
        int res = 1;
        while (n) {
            if (n % 2 != = 0) {
                res = (long)res * x % MOD;
            }
            x = (long)x * x % MOD;
            n /= 2;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        int res = 1;
        for (int i = b.size() - 1; i >= 0; i--) {
            res = (long)res * pow(a, b[i]) % MOD;
            a = pow(a, 10);
        }
        return res;
    }
    /*
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        for (int e : b) {
            ans = (long)pow(ans, 10) * pow(a, e) % MOD;
        }
        return ans;
    }
    */

};