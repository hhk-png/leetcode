#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

/* https://leetcode.cn/problems/sliding-window-median/ */

using namespace std;
class DualHeap {
private:
    // 如果k 为奇数，则small 比large 的元素个数多一个
    // 大根堆，维护较小的一半元素
    priority_queue<int> small;
    // 小根堆，维护较大的一半元素
    priority_queue<int, vector<int>, greater<int>> large;
    // 延迟删除，存储延迟删除的元素和个数
    unordered_map<int, int> delayed;
    // 窗口的大小
    int k;
    // 大根堆和小根堆的个数
    int smallSize, largeSize;
public:
    DualHeap(int _k) : k(_k), smallSize(0), largeSize(0) {}
private:
    template<typename T>
    // 如果heap 顶端的元素在delayed 中存在，则删除该元素
    void prune(T& heap) {
        // heap 不为空
        while (!heap.empty()) {
            // 获取堆顶的元素
            int num = heap.top();
            // 如果是延时删除的元素
            if (delayed.count(num)) {
                // 将其记录的元素个数减一
                --delayed[num];
                // 等于0 时
                if (!delayed[num]) {
                    // 删除该元素
                    delayed.erase(num);
                }
                // 删除堆中的元素
                heap.pop();
            }
            else {
                break;
            }
        }
    }

    void makeBalance() {
        // small 的元素个数比 large 多两个
        if (smallSize > largeSize + 1) {
            large.push(small.top());
            small.pop();
            --smallSize;
            ++largeSize;
            prune(small);
        }
        else if (smallSize < largeSize) {
            small.push(large.top());
            large.pop();
            ++smallSize;
            --largeSize;
            prune(large);
        }
    }

public:
    void insert(int num) {
        if (small.empty() || num <= small.top()) {
            small.push(num);
            ++smallSize;
        }
        else {
            large.push(num);
            ++largeSize;
        }
        makeBalance();
    }

    void erase(int num) {
        // 延迟删除
        ++delayed[num];
        if (num <= small.top()) {
            --smallSize;
            if (num == small.top()) {
                prune(small);
            }
        }
        else {
            --largeSize;
            if (num == large.top()) {
                prune(large);
            }
        }
        makeBalance();
    }

    // 获取中位数
    double getMedian() {
        return k & 1 ? small.top() : ((double)small.top() + large.top()) / 2;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        DualHeap dh(k);
        for (int i = 0; i < k; i++) {
            dh.insert(nums[i]);
        }
        vector<double> ans = { dh.getMedian() };
        for (int i = k; i < nums.size(); i++) {
            dh.insert(nums[i]);
            dh.erase(nums[i - k]);
            ans.push_back(dh.getMedian());
        }
        return ans;
    }
};

