/*
 * @Author: Opynicus
 * @Date: 2022-03-27 10:20:47
 * @LastEditTime: 2022-03-27 10:26:46
 * @LastEditors: Opynicus
 * @Description: leetcode binary tree problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\104.二叉树的最大深度.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            ans++;
            int curLevelSize = q.size();
            for (int i = 0; i < curLevelSize; i++)
            {
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
        return ans;
        
    }
};
// @lc code=end

