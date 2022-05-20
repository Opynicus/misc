/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr)
        {
            return root2;
        }
        if (root2 == nullptr)
        {
            return root1;
        }
        auto cur_node = new TreeNode(root1->val + root2->val);
        cur_node->left = mergeTrees(root1->left, root2->left);
        cur_node->right = mergeTrees(root1->right, root2->right);
        return cur_node;
        
        
        
    }
};
// @lc code=end

