/*
 * @Author: Opynicus
 * @Date: 2022-03-29 11:47:22
 * @LastEditTime: 2022-03-29 11:53:59
 * @LastEditors: Opynicus
 * @Description: balanced binary tree
 * @FilePath: \undefinede:\JuniorWork\leetcode\110.平衡二叉树.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int height(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            return max(height(root->left), height(root->right)) + 1;
        }
        
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
        {
            return true;
        }
        return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1;
        
    }
};
// @lc code=end

