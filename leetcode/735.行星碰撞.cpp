/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */

// @lc code=start
class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> st;
    for (auto a : asteroids) {
      bool exist = true;
      while (exist && a < 0 && !st.empty() && st.back() > 0) {
        exist = st.back() < -a;
        if (st.back() <= -a) {
          st.pop_back();
        }
      }
      if (exist) {
        st.push_back(a);
      }
    }
    return st;
  }
};
// @lc code=end
