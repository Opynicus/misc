/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> res;
    int cur_res, cnt, max;

    void update(int x) {
        if (x == cur_res) {
            cnt++;
        } else {
            cur_res = x;
            cnt = 1;
        }
        if (cnt == max) {
            res.push_back(cur_res);
        }
        if (cnt > max) {
            res = vector<int> {cur_res};
            max = cnt;
        }
    }

    void inorder(TreeNode* root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        update(root->val);
        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }
};
// @lc code=end

