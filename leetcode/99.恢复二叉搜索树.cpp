/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
  void recoverTree(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode* x = nullptr;
    TreeNode* y = nullptr;
    TreeNode* prev = nullptr;

    while (!stk.empty() || root != nullptr) {
      while (root != nullptr) {
        stk.push(root);
        root = root->left;
      }
      root = stk.top();
      stk.pop();
      if (prev != nullptr && root->val < prev->val) {
        y = root;
        if (x == nullptr) {
          x = prev;
        } else {
          break;
        }
      }
      prev = root;
      root = root->right;
    }
    swap(x->val, y->val);
  }
};
// @lc code=end
