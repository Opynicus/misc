/*
 * @lc app=leetcode.cn id=1765 lang=cpp
 *
 * [1765] 地图中的最高点
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
    int m = isWater.size(), n = isWater[0].size();
    vector<vector<int>> res(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (isWater[i][j]) {
          res[i][j] = 0;
          q.emplace(i, j);
        }
      }
    }
    while (!q.empty()) {
      auto &p = q.front();
      for (auto &dir : dirs) {
        int x = p.first + dir[0], y = p.second + dir[1];
        if (x >= 0 && x < m && y >= 0 && y < n && res[x][y] == -1) {
          res[x][y] = res[p.first][p.second] + 1;
          q.emplace(x, y);
        }
      }
      q.pop();
    }
    return res;
  }
};
// @lc code=end
