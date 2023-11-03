// https://leetcode.cn/problems/data-stream-as-disjoint-intervals/description/

class SummaryRanges {
private:
    map<int, int> intervals;

public:
    SummaryRanges() {}

    void addNum(int val) {
        // �ҵ� l1 ��С�������� l1 > val ������ intervalRight = [l1, r1]
        auto intervalRight = intervals.upper_bound(val);
        // �ҵ� l0 ���������� l0 <= val ������ intervalLeft = [l0, r0]
        // �����򼯺��У�interval0 ���� intervalRight ��ǰһ������
        // ������������������䣬interval0 Ϊβ������
        auto intervalLeft = (intervalRight == intervals.begin() ? intervals.end() : prev(intervalRight));

        if (intervalLeft != intervals.end() && intervalLeft->first <= val && val <= intervalLeft->second) {
            // ���һ
            return;
        }
        else {
            bool left_aside = (intervalLeft != intervals.end() && intervalLeft->second + 1 == val);
            bool right_aside = (intervalRight != intervals.end() && intervalRight->first - 1 == val);
            if (left_aside && right_aside) {
                // �����
                int left = intervalLeft->first, right = intervalRight->second;
                intervals.erase(intervalLeft);
                intervals.erase(intervalRight);
                intervals.emplace(left, right);
            }
            else if (left_aside) {
                // �����
                ++intervalLeft->second;
            }
            else if (right_aside) {
                // �����
                int right = intervalRight->second;
                intervals.erase(intervalRight);
                intervals.emplace(val, right);
            }
            else {
                // �����
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
