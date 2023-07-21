/*
    using PII = pair<int, int>;

    class Solution {
    public:
        bool canMeasureWater(int x, int y, int z) {
            stack<PII> stk;
            stk.emplace(0, 0);
            auto hash_function = [](const PII& o) {return hash<int>()(o.first) ^ hash<int>()(o.second);};
            unordered_set<PII, decltype(hash_function)> seen(0, hash_function);
            while (!stk.empty()) {
                if (seen.count(stk.top())) {
                    stk.pop();
                    continue;
                }
                seen.emplace(stk.top());
                
                auto [remain_x, remain_y] = stk.top();
                stk.pop();
                if (remain_x == z || remain_y == z || remain_x + remain_y == z) {
                    return true;
                }
                // 把 X 壶灌满。
                stk.emplace(x, remain_y);
                // 把 Y 壶灌满。
                stk.emplace(remain_x, y);
                // 把 X 壶倒空。
                stk.emplace(0, remain_y);
                // 把 Y 壶倒空。
                stk.emplace(remain_x, 0);
                // 把 X 壶的水灌进 Y 壶，直至灌满或倒空。
                stk.emplace(remain_x - min(remain_x, y - remain_y), remain_y + min(remain_x, y - remain_y));
                // 把 Y 壶的水灌进 X 壶，直至灌满或倒空。
                stk.emplace(remain_x + min(remain_y, x - remain_x), remain_y - min(remain_y, x - remain_x));
            }
            return false;
        }
    };
*/

// https://leetcode.cn/problems/water-and-jug-problem/

function gcd(a: number, b: number) {
    while (b) {
        let remainder = a % b
        a = b;
        b = remainder;
    }
    return a;
}

function canMeasureWater2(jug1Capacity: number, jug2Capacity: number, targetCapacity: number): boolean {
        if (jug1Capacity + jug2Capacity < targetCapacity) {
            return false;
        }
        if (jug1Capacity == 0 || jug2Capacity == 0) {
            return targetCapacity == 0 || jug1Capacity + jug2Capacity == targetCapacity;
        }
        return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
};

