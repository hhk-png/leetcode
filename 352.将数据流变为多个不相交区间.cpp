// https://leetcode.cn/problems/data-stream-as-disjoint-intervals/description/

class SummaryRanges {
private:
    map<int, int> intervals;

public:
    SummaryRanges() {}

    void addNum(int val) {
        // 找到 l1 最小的且满足 l1 > val 的区间 intervalRight = [l1, r1]
        auto intervalRight = intervals.upper_bound(val);
        // 找到 l0 最大的且满足 l0 <= val 的区间 intervalLeft = [l0, r0]
        // 在有序集合中，interval0 就是 intervalRight 的前一个区间
        // 如果不存在这样的区间，interval0 为尾迭代器
        auto intervalLeft = (intervalRight == intervals.begin() ? intervals.end() : prev(intervalRight));

        if (intervalLeft != intervals.end() && intervalLeft->first <= val && val <= intervalLeft->second) {
            // 情况一
            return;
        }
        else {
            bool left_aside = (intervalLeft != intervals.end() && intervalLeft->second + 1 == val);
            bool right_aside = (intervalRight != intervals.end() && intervalRight->first - 1 == val);
            if (left_aside && right_aside) {
                // 情况四
                int left = intervalLeft->first, right = intervalRight->second;
                intervals.erase(intervalLeft);
                intervals.erase(intervalRight);
                intervals.emplace(left, right);
            }
            else if (left_aside) {
                // 情况二
                ++intervalLeft->second;
            }
            else if (right_aside) {
                // 情况三
                int right = intervalRight->second;
                intervals.erase(intervalRight);
                intervals.emplace(val, right);
            }
            else {
                // 情况五
                intervals.emplace(val, val);
            }
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (const auto& [left, right] : intervals) {
            ans.push_back({ left, right });
        }
        return ans;
    }
};
