/*
 * @Author: Opynicus
 * @Date: 2022-03-19 15:28:32
 * @LastEditTime: 2022-03-19 15:43:14
 * @LastEditors: Opynicus
 * @Description: leetcode linked list problem
 * @FilePath: \csse:\JuniorWork\leetcode\19.删除链表的倒数第-n-个结点.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* nhead = new ListNode(0, head);
        ListNode* faster = head;
        ListNode* slower = nhead;
        for (int i = 0; i < n; i++)
        {
           faster = faster->next;
        }
        while (faster != nullptr)
        {
            faster = faster->next;
            slower = slower->next;
        }
        slower->next = slower->next->next;
        ListNode* ans = nhead->next;
        delete nhead;
        return ans;
        
    }
};
// @lc code=end

