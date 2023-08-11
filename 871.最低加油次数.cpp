// https://leetcode.cn/problems/minimum-number-of-refueling-stops/submissions/

class Solution {
  public:
      int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
          int n = stations.size();
          priority_queue<int> pq;
          int res = 0;
          int prev = 0;
          int fuel = startFuel;
          for (int i = 0; i <= n; i++) {
              int currDis = i < n ? stations[i][0] : target;
              fuel -= currDis - prev;
              while (fuel < 0 && !pq.empty()) {
                  fuel += pq.top();
                  pq.pop();
                  res++;
              }
              if (fuel < 0) {
                  return -1;
              }
              if (i < n) {
                  pq.emplace(stations[i][1]);
                  prev = currDis;
              }
          }
          return res;
      }
  };