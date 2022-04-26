/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, int &max_num, int &pre) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, max_num, pre);
        if (pre == -1) {
            pre = root->val;
        } else {
            max_num = min(max_num, abs(root->val - pre));
            pre = root->val;
        }
        inorder(root->right, max_num, pre);
        
        
    }
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) {
            return -1;
        }
        int max_num = INT_MAX;
        int pre = -1;
        inorder(root, max_num, pre);
        return max_num;
    }
};
// @lc code=end

