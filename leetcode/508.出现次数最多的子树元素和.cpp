/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  unordered_map<int, int> kv;
  int calSubtreeSum(TreeNode* node, vector<int>& res) {
    if (node == nullptr) {
      return 0;
    }
    int left_sum = calSubtreeSum(node->left, res);
    int right_sum = calSubtreeSum(node->right, res);
    int cur_sum = left_sum + right_sum + node->val;
    if (kv.find(cur_sum) == kv.end()) {
      kv.emplace(cur_sum, 1);
    } else {
      kv.at(cur_sum)++;
    }
    return cur_sum;
  }
  vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) {
      return res;
    }
    calSubtreeSum(root, res);
    int max_cnt = -1;
    for (auto i = kv.begin(); i != kv.end(); i++) {
      if (i->second > max_cnt) {
        max_cnt = i->second;
        res.clear();
        res.push_back(i->first);
      } else if (i->second == max_cnt) {
        res.push_back(i->first);
      }
    }
    return res;
  }
};
// @lc code=end
