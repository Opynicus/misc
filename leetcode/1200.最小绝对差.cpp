/*
 * @lc app=leetcode.cn id=1200 lang=cpp
 *
 * [1200] 最小绝对差
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    vector<vector<int>> res;
    int min_diff = INT_MAX;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; ++i) {
      int diff = arr[i + 1] - arr[i];
      if (diff < min_diff) {
        min_diff = diff;
        res.clear();
        res.push_back({arr[i], arr[i + 1]});
      } else if (diff == min_diff) {
        res.push_back({arr[i], arr[i + 1]});
      }
    }
    return res;
  }
};
// @lc code=end
