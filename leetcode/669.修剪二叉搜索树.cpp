/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
  TreeNode* traversal(TreeNode* root, int low, int high) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root->val < low) {
      return traversal(root->right, low, high);
    }
    if (root->val > high) {
      return traversal(root->left, low, high);
    }
    root->left = traversal(root->left, low, high);
    root->right = traversal(root->right, low, high);
    return root;
  }
  TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (root == nullptr) {
      return nullptr;
    }
    return traversal(root, low, high);
  }
};
// @lc code=end
