/*
 * @lc app=leetcode.cn id=565 lang=cpp
 *
 * [565] 数组嵌套
 */

// @lc code=start
class Solution {
 public:
  int arrayNesting(vector<int> &nums) {
    int ans = 0, n = nums.size();
    vector<int> vis(n);
    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      while (!vis[i]) {
        vis[i] = true;
        i = nums[i];
        ++cnt;
      }
      ans = max(ans, cnt);
    }
    return ans;
  }
};
// @lc code=end
