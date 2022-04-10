/*
 * @Author: Opynicus
 * @Date: 2022-03-19 15:54:59
 * @LastEditTime: 2022-03-19 16:05:19
 * @LastEditors: Opynicus
 * @Description: leetcode linked list problem
 * @FilePath: \csse:\JuniorWork\leetcode\206.反转链表.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
        {
            return NULL;
        }
        ListNode* prev = head;
        ListNode* cur = prev->next;
        while (cur != nullptr)
        {
            ListNode* p = cur->next;
            cur->next = prev;
            prev = cur;
            cur = p;
        }
        head->next = NULL;
        return prev;
        
    }
};
// @lc code=end

