/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
 public:
  void dfs(vector<vector<char>>& board, int x, int y, int n,
           int m) {  //不被包围意味着与边界存在的O连接
    if (x < 0 || y < 0 || x >= n || y >= m || board[x][y] != 'O') {
      return;
    }
    board[x][y] = 'S';
    dfs(board, x + 1, y, n, m);
    dfs(board, x - 1, y, n, m);
    dfs(board, x, y + 1, n, m);
    dfs(board, x, y - 1, n, m);
  }
  void solve(vector<vector<char>>& board) {
    int n = board.size();
    if (n == 0) {
      return;
    }
    int m = board[0].size();
    //从边界开始dfs
    for (auto i = 0; i < n; i++) {
      dfs(board, i, 0, n, m);
      dfs(board, i, m - 1, n, m);
    }
    for (auto j = 1; j < m - 1; j++) {
      dfs(board, 0, j, n, m);
      dfs(board, n - 1, j, n, m);
    }
    for (auto i = 0; i < n; i++) {
      for (auto j = 0; j < m; j++) {
        if (board[i][j] == 'S') {
          board[i][j] = 'O';
        } else if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }
};
// @lc code=end
