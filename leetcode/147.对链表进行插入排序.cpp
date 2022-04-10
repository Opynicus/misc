/*
 * @Author: Opynicus
 * @Date: 2022-04-05 21:30:16
 * @LastEditTime: 2022-04-05 21:40:04
 * @LastEditors: Opynicus
 * @Description: linked list + sort
 * @FilePath: \undefinede:\JuniorWork\leetcode\147.对链表进行插入排序.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr)
        {
            return NULL;
        }
        ListNode* hhead = new ListNode(0);
        hhead->next = head;
        ListNode* prior = head;
        ListNode* cur = head->next;
        while (cur)
        {
            if (prior->val <= cur->val)
            {
                prior = prior->next;
            }
            else
            {
                ListNode* prev = hhead;
                while (prev->next->val <= cur->val)
                {
                    prev = prev->next;
                }
                prior->next = cur->next;
                cur->next = prev->next;
                prev->next = cur;     
            }
            cur = prior->next;
        }
        return hhead->next;
        
    }
};
// @lc code=end

