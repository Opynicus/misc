/*
 * @Author: Opynicus
 * @Date: 2022-03-28 19:58:15
 * @LastEditTime: 2022-03-28 20:01:07
 * @LastEditors: Opynicus
 * @Description: binary serach tree
 * @FilePath: \leetcode\108.将有序数组转换为二叉搜索树.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
        {
            return new TreeNode(val);
        }
        else if (val < root->val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        else
        {
            root->right =  insertIntoBST(root->right, val);
        }
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;
        for (int i = 0; i < nums.size(); i++)
        {
            insertIntoBST(root,nums[i]);
        }
        return root;
    }
};
// @lc code=end

