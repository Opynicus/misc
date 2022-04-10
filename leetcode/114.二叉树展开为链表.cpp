/*
 * @Author: Opynicus
 * @Date: 2022-03-28 17:52:59
 * @LastEditTime: 2022-03-28 18:06:58
 * @LastEditors: Opynicus
 * @Description: binary tree
 * @FilePath: \leetcode\114.二叉树展开为链表.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    vector<TreeNode*> node;
    void preOrder(TreeNode* root) {
        if (root == nullptr)
        {
            return ;
        }
        node.push_back(root);
        preOrder(root->left);
        preOrder(root->right);
    }
    void flatten(TreeNode* root) {
        preOrder(root);
        int n = node.size();
        for (int i = 1; i < n; i++) {
            TreeNode *prev = node.at(i-1), *curr = node.at(i);
            prev->left = nullptr;
            prev->right = curr;
        
    }
    }
};
// @lc code=end

