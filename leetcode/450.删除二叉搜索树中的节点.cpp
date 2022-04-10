/*
 * @Author: Opynicus
 * @Date: 2022-03-29 21:00:30
 * @LastEditTime: 2022-03-29 21:12:22
 * @LastEditors: Opynicus
 * @Description: binary search tree
 * @FilePath: \undefinede:\JuniorWork\leetcode\450.删除二叉搜索树中的节点.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
        {
            return NULL;
        }
        if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                return NULL;
            }
            else if (root->left && root->right == nullptr)
            {
                return root->left;
            }
             else if (root->left == nullptr && root->right)
            {
                return root->right;
            }
            else
            {
                TreeNode* toBeDelete = root->right;
                while (toBeDelete->left)
                {
                    toBeDelete = toBeDelete->left;
                }
                root->val = toBeDelete->val;
                root->right = deleteNode(root->right, toBeDelete->val);
                
            }
        }
        return root;
    }
};
// @lc code=end

