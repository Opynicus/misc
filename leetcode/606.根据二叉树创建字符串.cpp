/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
    void preOrder(TreeNode* root, string& s) {
        if (root == nullptr) {
            return;
        }
        s += "(";
        s += to_string(root->val);
        if (root->left != nullptr) {
            preOrder(root->left, s);
        } else if (root->left == nullptr && root->right != nullptr) {
            s += "()";
        }
        preOrder(root->right, s);
        s += ")";
    }
    string tree2str(TreeNode* root) {
        if(root == nullptr) return "";
        string s = "";
        preOrder(root, s);
        string res(s.begin()+1, s.end()-1);
        stack<char> st;
        return res;
    }
};
// @lc code=end

