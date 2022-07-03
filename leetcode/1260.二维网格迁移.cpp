/*
 * @lc app=leetcode.cn id=1260 lang=cpp
 *
 * [1260] 二维网格迁移
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    queue<int> q;
    for (int i = m - 1; i >= 0; i--)
      for (int j = n - 1; j >= 0; j--) q.push(grid[i][j]);
    for (int i = 0; i < k; i++)
    {
      int tmp = q.front();
      q.pop();
      q.push(tmp);
    }
    
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            grid[i][j] = q.front();
            q.pop();
        }
    }
    return grid;
  }
};
// @lc code=end
