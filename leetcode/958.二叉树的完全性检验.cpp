/*
 * @Author: Opynicus
 * @Date: 2022-03-27 11:07:40
 * @LastEditTime: 2022-03-27 11:31:29
 * @LastEditors: Opynicus
 * @Description: leetcode binary tree problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\958.二叉树的完全性检验.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=958 lang=cpp
 *
 * [958] 二叉树的完全性检验
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
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr)
        {
            return false;
        }
        queue<TreeNode*> q;
        int judgeNum = 1;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if (node)
            {
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                while (!q.empty())
                {
                    TreeNode* node = q.front();
                    q.pop();
                    if (node)
                    {
                        return false;
                    }
                    
                }
            }
        }
        return true;
        
    }
};
// @lc code=end

