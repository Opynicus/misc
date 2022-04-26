/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr)
        {
            return -1;
        }
        int res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int cur_lvl_len = q.size();
            for (int i = 0; i < cur_lvl_len; i++)
            {
                if (i == 0)
                {
                   res = q.front()->val;
                }
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
            }
        }
        return res;
    }
};
// @lc code=end

