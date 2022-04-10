/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
        {
            return ans;
        }
        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int curLevelSize = q.size();
            ans.emplace_back(vector<int>());
            for (int i = 0; i < curLevelSize; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                ans.back().emplace_back(node->val);
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
                
                
            }
            
        }
        return ans;
        
    }
};
// @lc code=end

