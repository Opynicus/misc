/*
 * @Author: Opynicus
 * @Date: 2022-03-29 12:00:07
 * @LastEditTime: 2022-03-29 16:54:05
 * @LastEditors: Opynicus
 * @Description: binary search tree
 * @FilePath: \undefinede:\JuniorWork\leetcode\230.二叉搜索树中第k小的元素.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr)
        {
            return -1;
        }
        stack<TreeNode*> stk;
        while (!stk.empty() || root)
        {
            while (root)
            {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            k--;
            if (k == 0)
            {
                break;
            }
            root  = root->right;
        }
        return root->val;
    }
};
// @lc code=end

