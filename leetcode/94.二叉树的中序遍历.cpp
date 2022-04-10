/*
 * @Author: Opynicus
 * @Date: 2022-03-25 21:38:31
 * @LastEditTime: 2022-03-25 21:38:39
 * @LastEditors: Opynicus
 * @Description: leetcode binary tree problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\94.二叉树的中序遍历.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
        {
            return ans;
        }
        stack<TreeNode*> stk;
        while (root || !stk.empty())
        {
            while (root)
            {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            ans.emplace_back(root->val);
            stk.pop();
            root = root->right;
        }
        return ans;
        
    }
};
// @lc code=end

