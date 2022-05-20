/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
    int res = 0;
    int calSum(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        auto left_sum = calSum(root->left);
        auto right_sum = calSum(root->right);
        res += abs(left_sum - right_sum);
        return left_sum + right_sum + root->val;
    }
    int findTilt(TreeNode* root) {
        calSum(root);
        return res;
    }
};
// @lc code=end

