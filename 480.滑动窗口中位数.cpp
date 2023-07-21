#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

/* https://leetcode.cn/problems/sliding-window-median/ */

using namespace std;
class DualHeap {
private:
    // ���k Ϊ��������small ��large ��Ԫ�ظ�����һ��
    // ����ѣ�ά����С��һ��Ԫ��
    priority_queue<int> small;
    // С���ѣ�ά���ϴ��һ��Ԫ��
    priority_queue<int, vector<int>, greater<int>> large;
    // �ӳ�ɾ�����洢�ӳ�ɾ����Ԫ�غ͸���
    unordered_map<int, int> delayed;
    // ���ڵĴ�С
    int k;
    // ����Ѻ�С���ѵĸ���
    int smallSize, largeSize;
public:
    DualHeap(int _k) : k(_k), smallSize(0), largeSize(0) {}
private:
    template<typename T>
    // ���heap ���˵�Ԫ����delayed �д��ڣ���ɾ����Ԫ��
    void prune(T& heap) {
        // heap ��Ϊ��
        while (!heap.empty()) {
            // ��ȡ�Ѷ���Ԫ��
            int num = heap.top();
            // �������ʱɾ����Ԫ��
            if (delayed.count(num)) {
                // �����¼��Ԫ�ظ�����һ
                --delayed[num];
                // ����0 ʱ
                if (!delayed[num]) {
                    // ɾ����Ԫ��
                    delayed.erase(num);
                }
                // ɾ�����е�Ԫ��
                heap.pop();
            }
            else {
                break;
            }
        }
    }

    void makeBalance() {
        // small ��Ԫ�ظ����� large ������
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
        // �ӳ�ɾ��
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

    // ��ȡ��λ��
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

