/*
 * @Author: Opynicus
 * @Date: 2022-03-02 20:16:11
 * @LastEditTime: 2022-03-02 20:22:38
 * @LastEditors: Opynicus
 * @Description: leetcode problem
 * @FilePath: \undefinede:\JuniorWork\leetcode\234.回文链表.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> judge;
        ListNode* cur = head;
        while (cur) {
            judge.push_back(cur->val);
            cur = cur->next;
        }
        for (int i = 0, j = (int)judge.size() - 1; i < j; ++i, --j) {
            if (judge[i] != judge[j]) {
                return false;
            }
        }
        return true;
        
    }
};
// @lc code=end

