/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
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
  int maxLevelSum(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    int max_level = 0, cur_level = 0;
    int max_sum = INT_MIN;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      cur_level++;
      int cur_level_size = q.size();
      int sum = 0;
      for (int i = 0; i < cur_level_size; i++) {
        TreeNode* node = q.front();
        q.pop();
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
        sum += node->val;
      }
      if (sum > max_sum) {
        max_sum = sum;
        max_level = cur_level;
      }
    }
    return max_level;
  }
};
// @lc code=end
