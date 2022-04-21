/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
        {
            return ans;
        }
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            deque<int> tmp;
            int cur_level_len = q.size();
                 for (int i = 0; i < cur_level_len; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    if (level % 2 == 0)
                    {
                        tmp.push_back(node->val);
                    } else {
                         tmp.push_front(node->val);
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
        ans.push_back(vector<int>{tmp.begin(), tmp.end()});
        level++;
        }
        return ans; 
    }
};
// @lc code=end

