/*
 * @lc app=leetcode.cn id=1184 lang=cpp
 *
 * [1184] 公交站间的距离
 */

// @lc code=start
class Solution {
 public:
  int distanceBetweenBusStops(vector<int>& distance, int start,
                              int destination) {
    if (start > destination) swap(start, destination);
    int total = 0, d = 0;
    for (int i = 0; i < distance.size(); i++) total += distance[i];
    for (int i = start; i < destination; i++) d += distance[i];
    return min(total - d, d);
  }
};
// @lc code=end
