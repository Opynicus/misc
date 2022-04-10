/*
 * @Author: Opynicus
 * @Date: 2022-03-28 19:36:38
 * @LastEditTime: 2022-03-28 19:51:12
 * @LastEditors: Opynicus
 * @Description: binary search tree
 * @FilePath: \leetcode\701.二叉搜索树中的插入操作.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
        {
            return new TreeNode(val);
        }
        else if (val < root->val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        else
        {
            root->right =  insertIntoBST(root->right, val);
        }
        return root;
    }
};
// @lc code=end

