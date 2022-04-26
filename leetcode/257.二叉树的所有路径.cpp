/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void dfs(TreeNode* root, string cur_path, vector<string>& res) {
         if (root != nullptr) {
            cur_path += to_string(root->val);
            if (root->left == nullptr && root->right == nullptr) {
                res.push_back(cur_path);
            } else {
                cur_path += "->";
                dfs(root->left, cur_path, res);
                dfs(root->right, cur_path, res);
            }
        }

        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr)
        {
            return res;
        }
        dfs(root, "", res);
        return res;
    }
};
// @lc code=end

