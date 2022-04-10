/*
 * @Author: Opynicus
 * @Date: 2022-03-25 21:45:54
 * @LastEditTime: 2022-03-26 18:15:35
 * @LastEditors: Opynicus
 * @Description: leetcode binary tree problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\145.二叉树的后序遍历.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
        {
            return ans;
        }
        stack<TreeNode*> stk;
        TreeNode* prev = root;
        while (root || !stk.empty())
        {
            while (root)
            {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->right == nullptr || root->right == prev) {
                ans.emplace_back(root->val);
                prev = root;
                root = nullptr;
            } else {
                stk.emplace(root);
                root = root->right;
            }
        }
        return ans;
        
    }
};
// @lc code=end

