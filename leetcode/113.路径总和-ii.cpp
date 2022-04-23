/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> ans;
    vector<int> cur_path;
    void dfs(TreeNode* root, int targetSum) {
        if (root == nullptr)
        {
            return;
        }
        cur_path.push_back(root->val);
        targetSum -= root->val;
        if (!root->left && !root->right && targetSum == 0)
        {
            ans.push_back(cur_path);
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        cur_path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};
// @lc code=end

