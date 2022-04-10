// @algorithm @lc id=100342 lang=cpp 
// @title ping-heng-er-cha-shu-lcof


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
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
    int hdiff(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            return max(hdiff(root->left), hdiff(root->right)) + 1;
        }

    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
        {
            return true;
        }
        return isBalanced(root->left) && isBalanced(root->right) && abs(hdiff(root->left) - hdiff(root->right)) <= 1;
    }
};