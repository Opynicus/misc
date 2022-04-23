/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        idx = 0;
        inorder(root, bst_arr);
    }
    
    int next() {
        return bst_arr[idx++];
    }
    
    bool hasNext() {
        return idx < bst_arr.size();
    }
protected:
    void inorder(TreeNode* root, vector<int>& bst_arr) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, bst_arr);
        bst_arr.push_back(root->val);
        inorder(root->right, bst_arr);
    }
    int idx;
    vector<int> bst_arr;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

