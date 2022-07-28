/*
 * @lc app=leetcode.cn id=1331 lang=cpp
 *
 * [1331] 数组序号转换
 */

// @lc code=start
class Solution {
 public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    unordered_map<int, int> ranks;
    vector<int> ans(arr.size());
    for (auto& a : sortedArr) {
      if (!ranks.count(a)) {
        ranks[a] = ranks.size() + 1;
      }
    }
    for (int i = 0; i < arr.size(); i++) {
      ans[i] = ranks[arr[i]];
    }
    return ans;
  }
};
// @lc code=end
