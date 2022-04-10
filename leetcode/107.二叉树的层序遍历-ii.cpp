/*
 * @Author: your name
 * @Date: 2021-12-06 21:00:05
 * @LastEditTime: 2021-12-06 21:16:03
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \undefinede:\leetcode\107.二叉树的层序遍历-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       queue<TreeNode*> q;
       vector<vector<int>> res;
       if(root)
            q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> vec;
            for(int i = 0; i < size; i++){
                vec.push_back(q.front()->val);
                if(q.front()->left!=NULL)
                q.push(q.front()->left);
                if(q.front()->right!=NULL)
                q.push(q.front()->right);
                q.pop();
            }
            res.push_back(vec);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

