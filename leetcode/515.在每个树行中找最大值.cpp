/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int cur_lvl_len = q.size();
            int cur_max = q.front()->val;
            for (int i = 0; i < cur_lvl_len; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node->val > cur_max)
                {
                    cur_max = node->val;
                }
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            res.push_back(cur_max);
        }
        return res;
    }
};
// @lc code=end

