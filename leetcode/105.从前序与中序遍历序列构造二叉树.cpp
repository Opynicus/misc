/*
 * @Author: Opynicus
 * @Date: 2022-03-29 21:29:44
 * @LastEditTime: 2022-03-29 21:41:04
 * @LastEditors: Opynicus
 * @Description: 
 * @FilePath: \undefinede:\JuniorWork\leetcode\105.从前序与中序遍历序列构造二叉树.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
     int pl, int pr,int il, int ir) {
         if (pl > pr || il > ir)
         {
             return NULL;
         }
         TreeNode* root = new TreeNode(preorder[pl]);
         int mid = il;
         while (mid < ir &&  inorder[mid] != preorder[pl])
         {
             mid++;
         }
         int bias = mid - il;
         root->left = build(preorder, inorder, pl+1, pl+bias, il, mid-1);
         root->right = build(preorder, inorder, pl+bias+1, pr, mid+1, ir);
         return root;
     }
};
// @lc code=end

