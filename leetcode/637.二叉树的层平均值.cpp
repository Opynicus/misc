/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
    if (root == nullptr) {
      return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int cur_len = q.size();
      double ans = 0;
      for (auto i = 0; i < cur_len; i++) {
        TreeNode* node = q.front();
        q.pop();
        ans += node->val;
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
      res.push_back(ans / cur_len);
    }
    return res;
  }
};
// @lc code=end
