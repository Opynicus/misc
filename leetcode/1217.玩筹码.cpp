/*
 * @lc app=leetcode.cn id=1217 lang=cpp
 *
 * [1217] 玩筹码
 */

// @lc code=start
class Solution {
 public:
  int minCostToMoveChips(vector<int>& position) {
    int even = 0, odd = 0;
    for (int pos : position) {
      if (pos % 2) {
        odd++;
      } else {
        even++;
      }
    }
    return min(odd, even);
  }
};
// @lc code=end
