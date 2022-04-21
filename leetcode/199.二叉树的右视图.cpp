/*
 * @Author: Opynicus
 * @Date: 2022-04-21 21:36:40
 * @LastEditTime: 2022-04-21 21:40:47
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \undefinedf:\github_repos\Leetcode_Solutions\199.二叉树的右视图.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
        {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int cur_level_len = q.size();
            for (int i = 0; i < cur_level_len; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
                if (i == cur_level_len - 1)
                {
                    ans.push_back(node->val);
                }
            }
            
        }
        return ans;
        
        
    }
};
// @lc code=end

