/*
 * @Author: Opynicus
 * @Date: 2022-03-29 21:15:30
 * @LastEditTime: 2022-03-29 21:19:41
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \undefinede:\JuniorWork\leetcode\235.二叉搜索树的最近公共祖先.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
        {
            return NULL;
        }
        if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p ,q);
        }
        else if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p ,q);
        }
        else
        {
            ans = root;
        }
        return ans;
        
    }
};
// @lc code=end

